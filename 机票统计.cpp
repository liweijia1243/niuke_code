//
//__        __   _  _ _       
//\ \      / /__(_)(_|_) __ _ 
// \ \ /\ / / _ \ || | |/ _` |
//  \ V  V /  __/ || | | (_| |
//   \_/\_/ \___|_|/ |_|\__,_|
//               |__/         
////华为记票统计练习题
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<pair<string,int> > vec_p;	
        string candi_name; 
        for (int i=0;i<n;i++)
        {
            cin>>candi_name;
            bool flag_candi = true;
            for (auto ite=vec_p.begin();ite!=vec_p.end();ite++)
            {
                if (ite->first == candi_name)
                    flag_candi = false;
            }
            if (flag_candi)
                vec_p.push_back(pair<string,int>(candi_name,0));
        }

        int num;
        cin>>num;
        int invalid(0);

        for(int i=0;i<num;i++)
        {
            string piao;
            cin>>piao;
            bool falg_find=false;
            for (auto ite=vec_p.begin();ite!=vec_p.end();ite++)
            {
                if (ite->first == piao )
                {
                    falg_find = true;
                    ite->second++;
                    break;
                }
            }
            if (!falg_find)
                invalid++;
        }

        for (auto ite=vec_p.begin(); ite!=vec_p.end();ite++)
        {
            cout << ite->first <<" : "<< ite->second<<endl;
        }
        cout<<"Invalid : "<<invalid<<endl;

    }
    return 0;
}
