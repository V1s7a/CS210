#include "lab13functs.h"
// *** function header example *** //
/**   ----------------------------------------------------------
* @fn
* @brief <high level description of purpose of the function>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/

void swapPassByValue(int* val1, int* val2)
{
	int x = *val1, y = *val2;
	val1 = y;
	val2 = x;
}

void swapPassByReference(int* value1, int* value2)
{
	int temp1 = *value1, temp2 = *value2;
	*value1 = temp2;
	*value2 = temp1;
}

int pointerSum(int* num1, int* num2)
{
	int val = *num1 + *num2;
	return val;
}

void findFactorial(int x,long int* LP)
{
	int i;
	*LP = 1;
	for (i = 1; i <= x; ++i) {
		*LP = *LP * i;
	}
}
