#include <bits/stdc++.h>
using namespace std;


//1390

vector<int> getDivisor(int num)
{
    vector<int> divv;

    for(int i=1;i*i<num;i++)
    {
        if(num%i==0)
        {
            divv.push_back(i);
            if(i!=num/i)
            divv.push_back(num/i);
        }
    }

    return divv;
}


void solve()
{

   int n;
   cin>> n;

   vector<int> arr(n);

   for(int &i:arr)
   cin>>i;

   int sum=0;

   for(int i:arr)
   {
        vector<int> divv=getDivisor(i);

        int size=divv.size();

        if(size==4)
        {
            int tot=accumulate(divv.begin(),divv.end(),0);
            sum+=tot;
        }
   }

   cout<<sum;

   
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

    return 0;

}