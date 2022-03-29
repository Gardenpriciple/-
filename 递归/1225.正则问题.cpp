#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int k;
string str;

int dfs()
{
    int res = 0;
    while (k < str.size() )
    {
        if (str[k] == '(') //处理（。。。）
        {
            k ++; //跳过左括号
            res += dfs();
            k ++; //跳过右括号
        }
        else if (str[k] == '|')
        {
            k ++;
            res = max(res, dfs());
        }
        else if (str[k] == ')') break;
        else
        {
            k ++;//记得x也要跳过
            res ++;
        }
    }
    
    return res;
}


int main()
{
    cin >> str;
    cout << dfs() << endl;
}
