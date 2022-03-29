#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 110, M = 1 << 20;

int n, m, k;
vector<int> col[M]; // 哪些行可以包含这一列
int log2[M], cnt;
 
int lowbit(int x)
{
    return x & -x;
}
 
 
int h(int state) // 最少需要再选几行
{
    int res = 0;
    for (int i = (1 << m) - 1 - state; i; i -= lowbit(i))
    {
        int c = log2[lowbit(i)];
        res ++ ;
        for (auto row : col[c]) i &= -row;//把所有是1的位变成0，0的不变
    }
    
    return res;
}

bool dfs(int depth, int state)
{
    if (!depth || h(state) > depth) return state == (1 << m) - 1;
    //如果层数已经是0或当前状态需要的已经大于最少的，判断一下是否满足要求（11111）
    
    //找到选择性最少的一列
    int t = -1;
    for (int i = (1 << m) - 1 - state; i; i -= lowbit(i))//i如果这一位是1表示还没有被选
    {
        int c = log2[lowbit(i)];//找到最后一位1
        if (t == -1 || col[t].size() > col[c].size())
            t = c;
    }
    
    //枚举选哪行
    for (auto row : col[t])
        if (dfs(depth - 1, state | row)) //或上就是成功了
            return true;
    
    
    return false;
}


int main()
{
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i ++ ) log2[1 << i] = i;
    for (int i = 0; i < n; i ++ ) 
    {
        int state = 0;//每一行用一个二进制表示
        for (int j = 0; j < k ; j ++ )
        {
            int c;
            cin >> c;
            state |= 1 << c - 1;//糖的这一位变成1
        }
        
        for (int j = 0; j < m; j ++ )
            if (state >> j & 1)//枚举每一列,这一行包含第j列就放进去
            {
                col[j].push_back(state);
            }
    }
    
    int depth = 0;
    while (depth <= m && !dfs(depth, 0)) depth ++ ;
    
    if (depth > m) depth = -1;//没搜到无解
    cout << depth << endl;
    
    return 0;
}
