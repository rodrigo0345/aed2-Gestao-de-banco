#include "master.h"
#include "time.h"

unsigned short CheckMonthDays(int, int, int);

/* indica se a data fornecida pelo utilizador é válida ou não */
unsigned short Time_CheckInputDate_Int(int Day,
	int Month,
	int Year)
{

	if (CheckMonthDays(Day, Month, Year) && Year > 1800)
	{
		return 1;
	}
	return 0;
}

enum MonthList
{
	January = 1, February, March,
	April, May, June, July,
	August, September, October,
	November, December
};

/* retorna falso, sempre que o dia, o mes ou o ano sejam inválidos */
unsigned short CheckMonthDays(int Day,
	int Month,
	int year)
{
	switch (Month)
	{
	case January:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	case February:
		if (year % 4 == 0)
		{
			if (Day <= 29)
			{
				return 1;
			}
		}
		else
		{
			if (Day <= 28)
			{
				return 1;
			}
		}
		break;
	case March:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	case April:
		if (Day <= 30)
		{
			return 1;
		}
		break;
	case May:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	case June:
		if (Day <= 30)
		{
			return 1;
		}
		break;
	case July:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	case August:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	case September:
		if (Day <= 30)
		{
			return 1;
		}
		break;
	case October:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	case November:
		if (Day <= 30)
		{
			return 1;
		}
		break;
	case December:
		if (Day <= 31)
		{
			return 1;
		}
		break;
	default:
		return 0;
	}
	return 0;
}