#include<memory>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
char oriLights[5]; //����࿪һ��������
char lights[5];
char result[5];

int GetBit(char c, int i)
{
	return (c >> i) & 1; //get c�ĵ�iλ c����iλ
}
void SetBit(char& c, int i, int v) //��c�ĵ�iλ�ĳ�v
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
void FlipBit(char& c, int i) //�ѵ�iλ��ת
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
	cin >> T; //���������������
	for (int t = 1; t <= T; ++t)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				int s;
				cin >> s; //�ѵ�i�е�j�е�״̬����s

				SetBit(oriLights[i], j, s);  //��orilights�ĵ�i����j��bit��Ϊs
			}
		}
		for (int n = 0; n < 64; ++n)
		{
			int switchs = n;// ��n��ʾ2^5�ֵ�һ�п���״̬
			memcpy(lights, oriLights, sizeof(oriLights));//lights�������ڱ�ʾ��ǰѭ���Ƶ�״̬
			for (int i = 0; i < 5; ++i)
			{
				result[i] = switchs;
				for (int j = 0; j < 6; j++)
				{
					if (GetBit(switchs, j))// ����Ϊ1��ζ��Ҫ�ı�Ƶ�״̬
					{
						if (j > 0)
							FlipBit(lights[i], j - 1);
						FlipBit(lights[i], j);
						if (j < 5)
							FlipBit(lights[i], j + 1);
					}// ��ͬһ�еƵĴ���
				}
				if (i < 4) //�����һ��ǰ��Ҫ��i+1�д���
					lights[i + 1] ^= switchs;//���switchs��1����һ�ж�Ӧλ�øı�
				switchs = lights[i];//Ϊ��ʹ��i�е�ȫ�𣬵�i+1�п���״̬�����ǵ�i�е�״̬
			}
			if (lights[4] == 0)// �������ȹ̶���һ������ֲ���ͬʱȷ��ǰ���е�ȫ��ֻ��Ҫ�����һ�С�
			{
				OutputResult(t, result);
				break;
			}
		}
	}
	return 0;
}
