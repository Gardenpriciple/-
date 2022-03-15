#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_valid(int year, int month, int day)
{
	if (month == 0 || month > 12) return false;
	if (day == 0) return false;
	if (month != 2)
	{
		if (day > days[month]) return false;
	}
	else
	{
		int leap = year % 100 && year % 4 == 0 || year % 400 == 0;
		if (day > 28 + leap)
			return false;
	}

	return true;
}

int main()
{
	int a, b, c;
	scanf_s("%d/%d/%d", &a, &b, &c);

	for (int date = 19600101; date <= 20591231; date++)
	{
		int year = date / 10000, month = date % 10000 / 100, day = year % 100;
		if (check_valid(year, month, day))
		{
			if (year % 100 == a && month == b && day == c ||
				month == a && day == b && year % 100 == c ||
				day == a && month == b && year % 100 == c)
			{
				printf("%d-%02d-%02d\n", year, month, day);
			}
		}
	}

	return 0;
}
