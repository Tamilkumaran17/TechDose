#include <bits/stdc++.h>
using namespace std;


void st()
{
    string s;
    getline(cin,s);

    int pos = s.find(':');

    double ch = stod(s.substr(0,pos)), pp= stod(s.substr(pos+1));

    

    vector<pair<string,double>> mp = { 
        {"PENNY", 0.01},
        {"NICKEL", 0.05},
        {"DIME", 0.10},
        {"QUARTER", 0.25},
        {"HALF DOLLAR", 0.50},
        {"ONE", 1.00},
        {"TWO", 2.00},
        {"FIVE", 5.00},
        {"TEN", 10.00},
        {"TWENTY", 20.00},
        {"FIFTY", 50.00},
        {"ONE HUNDRED", 100.00}};

    vector<string> ans;


    sort(mp.begin(),mp.end(), [](auto& a, auto& b){
        return a.second > b.second;

    });

    int rem = round((pp-ch)*100);

    if( (pp-ch) < 0)
    {
        cout<<"ERROR";
        return;
    }
    if((pp-ch) == 0)
    {
        cout<<"ZERO";
    }

    for(auto &i:mp)
    {
        int val = round(i.second * 100);

        while( rem >= val)
        {
            ans.push_back(i.first);
            rem-=val;
        }

    }

    sort(ans.begin(),ans.end());


    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];

        if(i!=ans.size()-1)
        cout<<",";

       

    }



    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}