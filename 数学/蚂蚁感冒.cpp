#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 55;

int n;
int x[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];

	int left = 0, right = 0; //分别表示左边向右走的蚂蚁数，和右边向左走的
	for (int i = 1; i < n; i++)
		if (abs(x[i]) < abs(x[0]) && x[i] > 0) left++;
		else if (abs(x[i]) > abs(x[0]) && x[i] < 0) right++;

	if (x[0] > 0 && right == 0 || x[0] < 0 && left == 0) cout << 1 << endl;
	else cout << left + right + 1 << endl;

	return 0;
}



