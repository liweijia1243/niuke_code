//
//__        __   _  _ _       
//\ \      / /__(_)(_|_) __ _ 
// \ \ /\ / / _ \ || | |/ _` |
//  \ V  V /  __/ || | | (_| |
//   \_/\_/ \___|_|/ |_|\__,_|
//               |__/         
//题目描述
//扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
//3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
//输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
//请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
//基本规则：
//（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
//（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
//（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
//
//（4）输入的两手牌不会出现相等的情况。
//
#include <iostream>
#include <vector>

using namespace std;

int check_style(string poker);
int poker_compare(string poker1,int label1,string poker2,int label2);
int space_count(string poker);
int main()
{
    string str;
    while (getline(cin,str))
    {
        int pos=str.find('-');
        string poker1=str.substr(0,pos);
        string poker2=str.substr(pos+1,str.size()-pos+1);
        int label1,label2;
        label1 = check_style(poker1);
        label2 = check_style(poker2);
        int compare = poker_compare(poker1,label1,poker2,label2);
        if (compare==0)
            cout<<poker2<<endl;
        else if (compare==1)
            cout<<poker1<<endl;
        else
            cout<<"ERROR"<<endl;
    }
    return 0;
}

int space_count(string poker)
{   
    int count(0);
    int n=poker.size(); 
    for (int i=0;i<n;i++)
    {
        if (poker[i]==' ')
            count++;
    } 
    return count;
}
int check_style(string poker)
{
    int n=poker.size();
    int count = space_count(poker);
    if (count == 0 || count == 2  || count==4)
        return 1;
    else if (count == 3)
        return 2;
    else
    {
        if (n==11)
            return 3;
        else
            return 1;
    }
}
int poker_compare(string poker1,int label1,string poker2,int label2)
{
    vector<string> dict={"3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};
    if (label1 < label2)
    {
        return 0;
    }
    else if (label1 > label2)
        return 1;
    else
    {
        if (space_count(poker1) == space_count(poker2))
        {
            int pos1 = poker1.find_first_of(' ');
            int pos2 = poker2.find_first_of(' ');
            string str1=poker1.substr(0,pos1);
            string str2=poker2.substr(0,pos2);
            for (int i=0;i<dict.size();i++)
            {
                if (str1==dict[i])
                    pos1 = i;
                if (str2 ==dict[i])
                    pos2 = i;
            }
            if (pos1 < pos2)
                return 0;
            else
                return 1;
        }
        else
        {
            return 3;
        }
    }
}


























