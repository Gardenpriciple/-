#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double EPS = 1e-6;
double f(double x) { return x * x * x - 5 * x * x + 10 * x - 80; }

int main()
{
	double root, x1 = 0, x2 = 100, y;
	root = x1 + (x2 - x1) / 2;
	int triedTimes = 1; //记录一共尝试多少次，对球根不是必须的/
	y = f(root);
	
	while (fabs(y) >= EPS)
	{
		if (y > 0)		x2 = root;
		else	x1 = root;
		root = x1 + (x2 - x1) / 2;
		y = f(root);
		triedTimes++;
	}

	printf(" %f\n", root);
	printf(" %d\n", triedTimes);
}
