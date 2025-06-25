#include <bits/stdc++.h>
using namespace std;

// 456

void solve()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &i : arr)
        cin >> i;

    stack<int> st;
    vector<int> minn(n);

    minn[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        minn[i] = min(minn[i - 1], arr[i]);
    }

    int flag=0;

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] <= minn[i])
            continue;

        
            while(!st.empty() && st.top() <= minn[i])
            st.pop();

            if(!st.empty() && st.top() < arr[i])
            cout<<"True", flag=1;

            st.push(arr[i]);    
    }

    if(flag==0)
    cout<<"False";
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