// *** function header example *** //
/**   ----------------------------------------------------------
* @fn
* @brief <high level description of purpose of the function>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/

#include "lab12functs.h"
#include <stdio.h>

int isArmstrong(int x)
{
	int r, temp = x, sum = 0;
	while (x > 0)
	{
		r = x % 10;
		sum = sum + (r * r * r);
		x = x / 10;
	}
	if (temp == sum)
		return 1;
	else
		return 0;
	
}

int findGCD(int x, int y)
{
	x = (x > 0) ? x : -x;
	y = (y > 0) ? y : -y;

	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;

}

void printRange(int x, int y)
{
	while (x <= y)
	{
		printf("%d\n", x);
		x = ++x;
	}
	return;
}

