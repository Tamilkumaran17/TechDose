#include <bits/stdc++.h>
using namespace std;


//405




void solve()
{

   int n;
   cin>> n;

   if(n==0)
   cout<<"0";

   unsigned int num=n;

   string hex="", hexval="0123456789abcdef";

   while(num)
   {
    hex =hexval[num%16] + hex;
    num/=16;
   }
   cout<<hex;

   

   
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