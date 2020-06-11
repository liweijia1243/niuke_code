#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace std;

int main()
{
    int n;
    cin>>n;
    Eigen::MatrixXd m_xd;
    m_xd = Eigen::MatrixXd::Random(n,n);
    cout<<"你好offer，这里是牛客网刷题文件夹"<<endl;
    cout<<"this is Random Matrix"<<endl;
    cout<<m_xd<<endl;
    cout<<"this is the inverse()"<<endl;
    cout<<m_xd.inverse()<<endl; 
    return 0;
}
