#include <bits/stdc++.h>
using namespace std;

// Diamond pattern

void solve()
{

    int n;
    cin >> n;

    // diamond

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        cout<<" ";

        for(int j=0; j<2*i+1;j++)
        cout<<"*";

        for(int j=0;j<n-i-1;j++)
        cout<<" ";

        cout<<endl;

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        cout<<" ";

        for(int j=0;j< 2*n - (2*i+1);j++)
        cout<<"*";

        for(int j=0;j<i;j++)
        cout<<" ";
        cout<<endl;
    }

    cout<<endl;




    // diagonal  ^
                 

    for(int i=n;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++)
        cout<<"*";

        cout<<endl;
    }


    // 0 1 diagonal |_

    int start = 1;
    for(int i=0;i<n;i++)
    {
       if(i%2==0)
       start = 1;
       else start = 0;

        for(int j=0;j<=i;j++)
        {
            cout<<start<<" ";
            start = 1-start;
            
        }
        cout<<endl;
        
    }


    cout<<endl;


    // |_ _|


    int space = 2*(n-1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<j;

        for(int j=1;j<=space;j++)
        cout<<" ";

        for(int j=i;j>=1;j--)
        cout<<j;

        cout<<endl;

        space-=2;
    }


    cout<<endl;

    // pyramid A's

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        cout<<" ";

        char ch='A';
        int mid = (2*i+1)/2;
        for(int j=0;j<2*i+1;j++)
        {
            cout<<ch;

            if(j < mid)
            ch++;
            else
            ch--;
        }

        for(int j=0;j<n-i-1;j++)
        cout<<" ";

        cout<<endl;
    }


    cout<<endl;




    char ch = char('A' + n-1);
    // cout<<ch;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            cout<<char(ch-j)<<" ";
        }
        cout<<endl;
    }

    cout<<endl;





    space = 0;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        cout<<"*";

        for(int j=0;j<space;j++)
        cout<<" ";

        for(int j=0;j<n-i;j++ )
        cout<<"*";

        cout<<endl;

        space+=2;
    }

    space=2*(n-2);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        cout<<"*";

        for(int j=0;j<space;j++)
        cout<<" ";

        for(int j=i;j>=0;j-- )
        cout<<"*";

        cout<<endl;

        space-=2;
    }


    cout<<endl;






    space = 2*(n-1);


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        cout<<"*";

        for(int j=0;j<space;j++)
        cout<<" ";

        for(int j=i;j>=0;j--)
        cout<<"*";

        space-=2;

        cout<<endl;
    }
    space=2;

    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        cout<<"*";

        for(int j=0;j<space;j++)
        cout<<" ";
        
        for(int j=0;j<i;j++)
        cout<<"*";

        space+=2;
        cout<<endl;
    }

    cout<<endl;

    int inner = 2*(n-2)+1;

    for(int i=0;i<n;i++)
    {
        if(i==0 || i==n-1)
        {
            for(int j=0;j<n;j++)
            cout<<"* ";
        }

        else{
           cout<<"*";
           for(int j=0;j<inner;j++)
           cout<<" ";
           cout<<"*";
        }

        cout<<endl;

    }

    
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