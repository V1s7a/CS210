/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 */

//#define NEW_SIMD_CODE

#ifdef KERNEL_STATIC
#include "inc_vendor.h"
#include "inc_types.h"
#include "inc_platform.cl"
#include "inc_common.cl"
#include "inc_simd.cl"
#include "inc_hash_sha256.cl"
#endif

#define COMPARE_S "inc_comp_single.cl"
#define COMPARE_M "inc_comp_multi.cl"

typedef struct aescrypt
{
  u32 iv[4];
  u32 key[8];

} aescrypt_t;

typedef struct aescrypt_tmp
{
  u32 pass[144];
  int len;

} aescrypt_tmp_t;

KERNEL_FQ void m22400_init (KERN_ATTR_TMPS_ESALT (aescrypt_tmp_t, aescrypt_t))
{
  /**
   * base
   */

  const u64 gid = get_global_id (0);

  if (gid >= gid_max) return;

  // salt:

  u32 s[16] = { 0 }; // 64-byte aligned

  s[0] = salt_bufs[salt_pos].salt_buf[0];
  s[1] = salt_bufs[salt_pos].salt_buf[1];
  s[2] = salt_bufs[salt_pos].salt_buf[2];
  s[3] = salt_bufs[salt_pos].salt_buf[3];

  // convert password to utf16le:

  const u32 pw_len = pws[gid].pw_len;

  const u32 pw_len_utf16le = pw_len * 2;

  u32 w[144] = { 0 };

  for (u32 i = 0, j = 0; i < 64; i += 4, j += 8)
  {
    u32 in[4];

    in[0] = pws[gid].i[i + 0];
    in[1] = pws[gid].i[i + 1];
    in[2] = pws[gid].i[i + 2];
    in[3] = pws[gid].i[i + 3];

    u32 out0[4];
    u32 out1[4];

    make_utf16le_S (in, out0, out1);

    w[j + 0] = hc_swap32_S (out0[0]);
    w[j + 1] = hc_swap32_S (out0[1]);
    w[j + 2] = hc_swap32_S (out0[2]);
    w[j + 3] = hc_swap32_S (out0[3]);
    w[j + 4] = hc_swap32_S (out1[0]);
    w[j + 5] = hc_swap32_S (out1[1]);
    w[j + 6] = hc_swap32_S (out1[2]);
    w[j + 7] = hc_swap32_S (out1[3]);
  }

  // sha256:

  sha256_ctx_t ctx;

  sha256_init   (&ctx);
  sha256_update (&ctx, s, 32);
  sha256_update (&ctx, w, pw_len_utf16le);
  sha256_final  (&ctx);

  // set tmps:

  #ifdef _unroll
  #pragma unroll
  #endif
  for (int i = 127; i >= 0; i--) // create some space for the first digest without extra buffer
  {
    w[8 + i] = w[i];
  }

  w[0] = ctx.h[0];
  w[1] = ctx.h[1];
  w[2] = ctx.h[2];
  w[3] = ctx.h[3];
  w[4] = ctx.h[4];
  w[5] = ctx.h[5];
  w[6] = ctx.h[6];
  w[7] = ctx.h[7];

  const u32 final_len = 32 + pw_len_utf16le;

  const u32 idx_floor = (final_len / 64) * 16;
  const u32 idx_ceil  = ((final_len & 63) >= 56) ? idx_floor + 16 : idx_floor;

  append_0x80_4x4_S (&w[idx_floor + 0], &w[idx_floor + 4], &w[idx_floor + 8], &w[idx_floor + 12], (final_len & 63) ^ 3);

  w[idx_ceil + 14] = 0;
  w[idx_ceil + 15] = final_len * 8;

  #ifdef _unroll
  #pragma unroll
  #endif
  for (u32 i = 0; i < 144; i++)
  {
    tmps[gid].pass[i] = w[i];
  }

  tmps[gid].len = final_len;
}

KERNEL_FQ void m22400_loop (KERN_ATTR_TMPS_ESALT (aescrypt_tmp_t, aescrypt_t))
{
  const u64 gid = get_global_id (0);

  if (gid >= gid_max) return;

  // init

  u32 w[144];

  #ifdef _unroll
  #pragma unroll
  #endif
  for (u32 i = 0; i < 144; i++)
  {
    w[i] = tmps[gid].pass[i];
  }

  const int pw_len = tmps[gid].len;

  // main loop

  for (u32 i = 0; i < loop_cnt; i++)
  {
    u32 h[8];

    h[0] = SHA256M_A;
    h[1] = SHA256M_B;
    h[2] = SHA256M_C;
    h[3] = SHA256M_D;
    h[4] = SHA256M_E;
    h[5] = SHA256M_F;
    h[6] = SHA256M_G;
    h[7] = SHA256M_H;

    u32 w0[4];
    u32 w1[4];
    u32 w2[4];
    u32 w3[4];

    int left;
    int idx;

    for (left = pw_len, idx = 0; left >= 56; left -= 64, idx += 16)
    {
      w0[0] = w[idx +  0];
      w0[1] = w[idx +  1];
      w0[2] = w[idx +  2];
      w0[3] = w[idx +  3];
      w1[0] = w[idx +  4];
      w1[1] = w[idx +  5];
      w1[2] = w[idx +  6];
      w1[3] = w[idx +  7];
      w2[0] = w[idx +  8];
      w2[1] = w[idx +  9];
      w2[2] = w[idx + 10];
      w2[3] = w[idx + 11];
      w3[0] = w[idx + 12];
      w3[1] = w[idx + 13];
      w3[2] = w[idx + 14];
      w3[3] = w[idx + 15];

      sha256_transform (w0, w1, w2, w3, h);
    }

    w0[0] = w[idx +  0];
    w0[1] = w[idx +  1];
    w0[2] = w[idx +  2];
    w0[3] = w[idx +  3];
    w1[0] = w[idx +  4];
    w1[1] = w[idx +  5];
    w1[2] = w[idx +  6];
    w1[3] = w[idx +  7];
    w2[0] = w[idx +  8];
    w2[1] = w[idx +  9];
    w2[2] = w[idx + 10];
    w2[3] = w[idx + 11];
    w3[0] = w[idx + 12];
    w3[1] = w[idx + 13];
    w3[2] = w[idx + 14];
    w3[3] = w[idx + 15];

    sha256_transform (w0, w1, w2, w3, h);

    w[0] = h[0];
    w[1] = h[1];
    w[2] = h[2];
    w[3] = h[3];
    w[4] = h[4];
    w[5] = h[5];
    w[6] = h[6];
    w[7] = h[7];
  }

  tmps[gid].pass[0] = w[0];
  tmps[gid].pass[1] = w[1];
  tmps[gid].pass[2] = w[2];
  tmps[gid].pass[3] = w[3];
  tmps[gid].pass[4] = w[4];
  tmps[gid].pass[5] = w[5];
  tmps[gid].pass[6] = w[6];
  tmps[gid].pass[7] = w[7];
}

KERNEL_FQ void m22400_comp (KERN_ATTR_TMPS_ESALT (aescrypt_tmp_t, aescrypt_t))
{
  const u64 gid = get_global_id (0);

  if (gid >= gid_max) return;

  // digest

  u32 dgst[16] = { 0 };

  dgst[0] = tmps[gid].pass[0];
  dgst[1] = tmps[gid].pass[1];
  dgst[2] = tmps[gid].pass[2];
  dgst[3] = tmps[gid].pass[3];
  dgst[4] = tmps[gid].pass[4];
  dgst[5] = tmps[gid].pass[5];
  dgst[6] = tmps[gid].pass[6];
  dgst[7] = tmps[gid].pass[7];

  // IV

  u32 data[16] = { 0 };

  data[ 0] = esalt_bufs[digests_offset].iv[0];
  data[ 1] = esalt_bufs[digests_offset].iv[1];
  data[ 2] = esalt_bufs[digests_offset].iv[2];
  data[ 3] = esalt_bufs[digests_offset].iv[3];

  // key

  data[ 4] = esalt_bufs[digests_offset].key[0];
  data[ 5] = esalt_bufs[digests_offset].key[1];
  data[ 6] = esalt_bufs[digests_offset].key[2];
  data[ 7] = esalt_bufs[digests_offset].key[3];
  data[ 8] = esalt_bufs[digests_offset].key[4];
  data[ 9] = esalt_bufs[digests_offset].key[5];
  data[10] = esalt_bufs[digests_offset].key[6];
  data[11] = esalt_bufs[digests_offset].key[7];

  /*
   * HMAC-SHA256:
   */

  sha256_hmac_ctx_t ctx;

  sha256_hmac_init   (&ctx, dgst, 32);
  sha256_hmac_update (&ctx, data, 48);
  sha256_hmac_final  (&ctx);

  const u32 r0 = ctx.opad.h[DGST_R0];
  const u32 r1 = ctx.opad.h[DGST_R1];
  const u32 r2 = ctx.opad.h[DGST_R2];
  const u32 r3 = ctx.opad.h[DGST_R3];

  #define il_pos 0

  #ifdef KERNEL_STATIC
  #include COMPARE_M
  #endif
}
