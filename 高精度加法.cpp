/*要求编程实现上述高精度的十进制加法。
要求实现方法：
public String add (String num1, String num2)
【输入】num1：字符串形式操作数1，如果操作数为负，则num1的前缀为符号位'-'
num2：字符串形式操作数2，如果操作数为负，则num2的前缀为符号位'-'
【返回】保存加法计算结果字符串，如果结果为负，则字符串的前缀为'-'
注：
(1)当输入为正数时，'+'不会出现在输入字符串中；当输入为负数时，'-'会出现在输入字符串中，且一定在输入字符串最左边位置；
(2)输入字符串所有位均代表有效数字，即不存在由'0'开始的输入字符串，比如"0012", "-0012"不会出现；
(3)要求输出字符串所有位均为有效数字，结果为正或0时'+'不出现在输出字符串，结果为负时输出字符串最左边位置为'-'。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string string_add(string& str1,string& str2)
{
    int c=0;
    int a1(0),a2(0);
    string::iterator it1=str1.begin();
    string::iterator it2=str2.begin();
    string out;
    while(c!=0 || it1!=str1.end() || it2!=str2.end())
    {
        a1= (it1 == str1.end()) ? 0 : *it1-'0';
        a2= (it2 == str2.end()) ? 0 : *it2-'0';
       out.push_back( (a1+a2+c)%10+'0');
       c = (a1+a2+c)/10;

       it1 = (it1 == str1.end()) ? str1.end() : it1+1;
       it2 = (it2 == str2.end()) ? str2.end() : it2+1;
    }
    reverse(out.begin(),out.end());
    return (out);
}

bool compare(string& str1 , string& str2)
{
    if(str1.size()>str2.size())
        return true;
    else if(str1.size()<str2.size())
        return false;
    else
    {
    return (str1>str2);
    }
}

string string_minus(string& str1,string& str2)
{
    int c=0;
    int a1(0),a2(0);
    string::iterator it1=str1.begin();
    string::iterator it2=str2.begin();
    string out;
    while(it1!=str1.end() || it2!=str2.end())
    {
       a1= (it1 == str1.end()) ? 0 : *it1-'0';
       a2= (it2 == str2.end()) ? 0 : *it2-'0';
       if (a1+c >= a2)
       {
            out.push_back((a1-a2+c)+'0');
            c=0;
       }
       else
       {
            out.push_back((a1+10+c-a2)+'0');
            c=-1;
       }

       it1 = (it1 == str1.end()) ? str1.end() : it1+1;
       it2 = (it2 == str2.end()) ? str2.end() : it2+1;
    }
    reverse(out.begin(),out.end());
    if (str1 ==str2)
        out="0";
    return (out);

}


int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
    //首先要判断是加法还是减法
    //其次我们需要将字符串逆序方便操作
    int s1=str1.size();
    int s2=str2.size();
    if (str1[0]!='-' && str2[0]!='-')
    {
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        cout<<string_add(str1,str2)<<endl;
    }
    if (str1[0]=='-' && str2[0]=='-')
    {
        string out="-";
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        str1.erase(s1-1);
        str2.erase(s2-1);
        out+=string_add(str1,str2);
        cout<<out<<endl;
    }
    if (str1[0]=='-' && str2[0]!='-')
    {
        str1.erase(0,1);
        string out;
        if (compare(str1,str2))
        {
            out="-";
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            out+=string_minus(str1,str2);
            cout<<out<<endl;
        }
        else
        {
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            out = string_minus(str2,str1);
            cout<<out<<endl;
        }
    }
    if (str1[0]!='-' && str2[0]=='-')
    {
        str2.erase(0,1);
        string out;
        if(compare(str2,str1))
        {
            out="-";
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            out+=string_minus(str2,str1);
            cout<<out<<endl;
        }
        else
        {
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            out = string_minus(str1,str2);
            cout<<out<<endl;
        }
    }

    }
    return 0;
}
























