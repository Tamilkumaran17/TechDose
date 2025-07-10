#include <bits/stdc++.h>
using namespace std;

// 

void solve()
{

    int n;
    cin >> n;

    vector<string> ans;
    ans.push_back("1"); 

    for(int i = 1; i <= n; i++) {
        string s = ans.back();
        string ns;
        int c = 1;

        for(int j = 0; j < s.size(); j++) {
            if(j + 1 < s.size() && s[j] == s[j + 1]) {
                c++;
            } else {
                ns.push_back(char(c + '0'));
                ns.push_back(s[j]);
                c = 1;
            }
        }

        ans.push_back(ns);
    }

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    
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