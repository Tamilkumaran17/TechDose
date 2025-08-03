#include <bits/stdc++.h>
using namespace std;


// 239


void fun(int n, vector<int>& arr) {

    int furr=0, curr=0, jump=0;
    for(int i=0;i<n-1;i++)
    {
        furr= max(furr,i+arr[i]);

        if(i==curr)
        {
            jump++;
            curr= furr;

        }
    }

    cout<<"Min Jumps needed : "<<jump;
    
}

void solve()
{

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i:arr)
    cin>>i;

    


   fun(n,arr);

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