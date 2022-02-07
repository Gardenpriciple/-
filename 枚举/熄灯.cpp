#include<memory>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
char oriLights[5]; //建议多开一点避免错误
char lights[5];
char result[5];

int GetBit(char c, int i)
{
	return (c >> i) & 1; //get c的第i位 c右移i位
}
void SetBit(char& c, int i, int v) //吧c的第i位改成v
{
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= ~(1 << i);
	}
}
void FlipBit(char& c, int i) //把第i位反转
{
	c ^= (1 << i);
}

void OutputResult(int i, char result[])
{
	cout << "PUZZLE #" << i << endl;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << GetBit(result[i], j);
			if (j < 5)
				cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	int T;
	cin >> T; //读入测试数据组数
	for (int t = 1; t <= T; ++t)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				int s;
				cin >> s; //把第i行第j列的状态存入s

				SetBit(oriLights[i], j, s);  //把orilights的第i个第j个bit设为s
			}
		}
		for (int n = 0; n < 64; ++n)
		{
			int switchs = n;// 用n表示2^5种第一行开关状态
			memcpy(lights, oriLights, sizeof(oriLights));//lights复制用于表示当前循环灯的状态
			for (int i = 0; i < 5; ++i)
			{
				result[i] = switchs;
				for (int j = 0; j < 6; j++)
				{
					if (GetBit(switchs, j))// 开关为1意味着要改变灯的状态
					{
						if (j > 0)
							FlipBit(lights[i], j - 1);
						FlipBit(lights[i], j);
						if (j < 5)
							FlipBit(lights[i], j + 1);
					}// 对同一行灯的处理
				}
				if (i < 4) //在最后一行前，要对i+1行处理
					lights[i + 1] ^= switchs;//如果switchs是1，这一行对应位置改变
				switchs = lights[i];//为了使第i行灯全灭，第i+1行开关状态必须是第i行灯状态
			}
			if (lights[4] == 0)// 这样在先固定第一行这个局部的同时确保前四行灯全灭，只需要看最后一行。
			{
				OutputResult(t, result);
				break;
			}
		}
	}
	return 0;
}
