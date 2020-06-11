//__        __   _  _ _       
//\ \      / /__(_)(_|_) __ _ 
// \ \ /\ / / _ \ || | |/ _` |
//  \ V  V /  __/ || | | (_| |
//   \_/\_/ \___|_|/ |_|\__,_|
//               |__/         
//
/**

 * 
*  完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
*  它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
*  例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
* 
*  给定函数count(int n),用于计算n以内(含n)完全数的个数
* @param n  计算范围, 0 < n <= 500000
* @return n 以内完全数的个数, 异常情况返回-1
* 
*/
#include <iostream>

using namespace std;

bool is_perfect(int n)
{
    int sum =0;
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            if (i==1)
                sum++;
            else if(i*i==n)
            {
                sum+=i;
            }
            else
            {
                sum+=i+n/i;
            }
        }
    }
    if (sum==n)
    {
        cout<< n<<endl;
        return true;
    }
    else
        return false;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int perfect_num=0;
        for (int i=6;i<n+1;i++)
        {
            if (is_perfect(i))
                perfect_num++;
        }
        cout<<perfect_num<<endl;
    }
    return 0;
}
