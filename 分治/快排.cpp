#include<iostream>
using namespace std;

void swap(int & a, int & b) //用引用改变实参的值
{
	int tmp = a;
	a = b;
	b = tmp;
}

void QuickSort(int a[], int s, int e) //s e 指待排序的范围
{
	if (s >= e)
		return;

	int k = a[s];
	int i = s, j = e;
	while (i != j)
	{
		while (j > i && a[j] >= k)
			--j;
		swap(a[i], a[j]);
		while (i < j && a[i] <= k)
			++j;
		swap(a[i], a[j]);
	}

	QuickSort(a, s, i - 1);
	QuickSort(a, j + 1, e);
}

int main()
{
	int a[5] = { 6,4,5,4,3 };
	QuickSort(a, 2, 4);
}
