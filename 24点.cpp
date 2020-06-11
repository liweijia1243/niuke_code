//
//__        __   _  _ _       
//\ \      / /__(_)(_|_) __ _ 
// \ \ /\ / / _ \ || | |/ _` |
//  \ V  V /  __/ || | | (_| |
//   \_/\_/ \___|_|/ |_|\__,_|
//               |__/         
//
//
//
/*
* *题目描述
*计算24点是一种扑克牌益智游戏，随机抽出4张扑克牌，通过加(+)，减(-)，乘(*), 除(/)四种运算法则计算得到整数24，本问题中，扑克牌通过如下字符或者字符串表示，其中，小写joker表示小王，大写JOKER表示大王： 
*
*                   3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
*
*本程序要求实现：输入4张牌，输出一个算式，算式的结果为24点。 
*
*详细说明： 
*
*1.运算只考虑加减乘除运算，没有阶乘等特殊运算符号，友情提醒，整数除法要当心； 
*2.牌面2~10对应的权值为2~10, J、Q、K、A权值分别为为11、12、13、1； 
*3.输入4张牌为字符串形式，以一个空格隔开，首尾无空格；如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算； 
*4.输出的算式格式为4张牌通过+-*/ /*四个运算符相连，中间无空格，4张牌出现顺序任意，只要结果正确； 
*5.输出算式的运算顺序从左至右，不包含括号，如1+2+3*4的结果为24
*6.如果存在多种算式都能计算得出24，只需输出一种即可，如果无法得出24，则输出“NONE”表示无解。
*
*输入描述:
*输入4张牌为字符串形式，以一个空格隔开，首尾无空格；
*
*输出描述:
*如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算； 
*示例1
*输入
*复制
*A A A A
*输出
*复制
*NONE
* *
* */
#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<string> poker_dict={"A","2","3","4","5","6","7","8","9","10","J","Q","K","joker","JOKER"};
vector<int> poker_num={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

double cal_24(double a, char c,double b)
{
    if (c=='+')
    {
        return (double)a+(double)b;
    }
    if (c=='-')
    {
        return (double)a-(double)b;
    }
    if (c=='*')
    {
        return (double)a*(double)b;
    }
    if (c=='/')
    {
        return (double)a/(double)b;
    }
};

bool jiesuan(int a,int b,int c,int d, string &  cal)
{
    string pos="+-*/";
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++)
            {
               if (cal_24(cal_24(cal_24(a,pos[i],b),pos[j],c),pos[k],d) == 24.0000)
               {
                   cal = poker_dict[a-1]+pos[i]+poker_dict[b-1]+pos[j]+poker_dict[c-1]+pos[k]+poker_dict[d-1];
                   return true;
               } 
            }
        }
    }
    return false;
};

int main()
{
    map<string,int> poker_map;
    for (int i=0;i<15;i++)
    {
        poker_map[poker_dict[i]] = poker_num[i];
    }
    vector<string>  s(4);
    bool flag_error=0;
    while(cin>>s[0]>>s[1]>>s[2]>>s[3])
    {
        vector<int> poker(4,0);
        for (int i=0;i<4;i++)
        {
            poker[i]=poker_map[s[i]];
            if (poker[i] == 14 || poker[i] == 15)
                flag_error=1;
        }
        if (flag_error)
        {
            cout<<"ERROR"<<endl;
        }
        else
        {
            vector<bool> check(4,0);
            bool flag_24=0;
            string  cal="";
            for (int i=0;i<4;i++)
            {
                if (!check[i]&& !flag_24)
                {
                    check[i]=1;
                    for (int j=0;j<4;j++)
                    {
                        if (!check[j] && !flag_24)
                        {
                            check[j]=1;
                           for (int k=0;k<4;k++)
                           {
                               if (!check[k] && !flag_24)
                               {
                                   check[k]=1;
                                   for (int l=0;l<4;l++)
                                   {
                                       if (!check[l] && !flag_24)
                                       {
                                           check[l]=1;
                                           if (jiesuan(poker[i],poker[j],poker[k],poker[l],cal))
                                           {
                                               flag_24 =1;
                                           }
                                           check[l]=0;
                                       }
                                   }
                                   check[k]=0;
                               }
                           } 
                           check[j]=0;
                        }
                    }
                    check[i]=0;
                }
            }
            if (flag_24)
            {
                cout<<cal<<endl;
            }
            else
            {
                cout<<"NONE"<<endl;
            }
        }
    }   
    return 0;
}
