#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int sum(0);
        for (int i=6;i<n+1;i++)
        {
            if(i%7 == 0 || to_string(i).find('7') != -1)
                sum++;
        }

        cout<<sum<<endl;
        //cout<<stoi("23454")<<endl;
        //stox,以及to_string两个函数都是std中的成员，不需要其他头文件引用
    }
    return 0;
}
