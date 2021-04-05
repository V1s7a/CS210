#include "lab10functs.h"

// *** function header example *** //
/**   ----------------------------------------------------------
* @fn
* @brief <high level description of purpose of the function>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/
#include <stdbool.h>
#include <ctype.h>
bool isFirstHalfAlpha(char x)
{	
	char y = tolower(x);
	switch (y)
	{
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
		return true;
		break;
	default:
		return false;
		break;
	}
}

int typeOfChar(char x)
{
	if (isalpha(x) == false) {
		return -1;
	}
	char y = tolower(x);
	switch (y)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 0;
	default:
		return 1;
		break;
	}
}

bool isMagicChar(char x)
{
	char magicChar = '@';
	if (x == magicChar)
		return true;
	else
		return false;
	
}
