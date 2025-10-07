#include <bits/stdc++.h>
using namespace std;

//  1414





void solve()
{

    int k;
    cin>>k;
    

    vector<int> fib={1,1};

    while (fib.back() < k)
    {
        /* code */
        fib.push_back( fib[fib.size()-1] + fib[fib.size()-2] );
    }

    int c=0,i=fib.size()-1;

    vector<int> nums;
    

    while(k>0)
    {
        if(fib[i] <= k)
        {
            c++;
            nums.push_back(fib[i]);
            k-=fib[i];
        }
        i--;
    }

    cout<<c<<endl;
    for(int i:nums)
    cout<<i<<" ";
    

    



   
    
    


    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}