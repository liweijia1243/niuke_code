//
//              _  _ _         _ _ 
//__      _____(_)(_|_) __ _  | (_)
//\ \ /\ / / _ \ || | |/ _` | | | |
// \ V  V /  __/ || | | (_| | | | |
//  \_/\_/ \___|_|/ |_|\__,_| |_|_|
//              |__/               
//华为OJ，在字符串中找出连续最长的数字串
//注意本题要求，相同的最大长度，都要输出
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int n=str.size();
        vector<int> dp(n+1,0);
        int max=-1;
        for (int i=0;i<n;i++)
        {
            if (str[i]>='0' && str[i]<='9')
            {
                dp[i+1]=dp[i]+1;
                if (dp[i+1]>max)
                {
                    max=dp[i+1];
                }
            }
            else
            {
                dp[i+1]=0;
            }
        }
        vector<int> max_index;
        for (int i=1;i<n+1;i++)
        {
            if (dp[i]==max)
                max_index.push_back(i-1);
        }
        for (int i=0;i<max_index.size();i++)
        {    
            cout<<str.substr(max_index[i]-max+1,max);
        }
        cout<<","<<max<<endl;
    }    
    return 0;
}
