
/*
*求两个字符串的距离，也就是a串通过增删改，最少多少个字符，可以变道b串
*用动态规划思想解决这道题目
*也是非常简单但经典的题目
*
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        int n,m;
        n=str1.size();
        m=str2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<m+1;i++)
        {
            dp[0][i]=i;
        }
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=i;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if (str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
                }
            }
        }
        
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
