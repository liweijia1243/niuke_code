#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if (n<3)
            cout<<-1<<endl;
        else
        {
            int r=(n-2)%4;
            if(r==1 || r==3)
                cout<<2<<endl;
            if(r==2)
                cout<<3<<endl;
            if(r==0)
                cout<<4<<endl;
        }
    }
    return 0;
}
