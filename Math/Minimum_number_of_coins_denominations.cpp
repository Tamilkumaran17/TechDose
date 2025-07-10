#include <bits/stdc++.h>
using namespace std;





int fun(int n) {

    int sum=0, count=0;

    while(sum < n)
    {
        int next = sum+1;
        sum+= next;
        count++;
    }
    return count;
}

void solve()
{

   int n;
   cin>>n;

   while(n--)
   {
    int N;
    cin>>N;
   cout<< fun(N)<<endl;
    
   }




   

   

   

   
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