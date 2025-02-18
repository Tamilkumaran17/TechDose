#include <bits/stdc++.h>
using namespace std;


// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

 
// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.



void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n);

    int x2=0,x3=0,x5=0;

    int mul_2=2,mul_3=3,mul_5=5;
    dp[0]=1;
    int next=1;

    for(int i=1;i<n;i++)
    {
        next=min({mul_2,mul_3,mul_5});

        dp[i]=next;

        if(next==mul_2)
        {
            x2++;
            mul_2= dp[x2] * 2;
        }

        if(next==mul_3)
        {
            x3++;
            mul_3= dp[x3] * 3;
        }

        if(next==mul_5)
        {
            x5++;
            mul_5= dp[x5] * 5;
        }
    }
    cout<< "The Ugly number for "<< n << " th number is "<< next; 

   
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