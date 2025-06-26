#include <bits/stdc++.h>
using namespace std;


//2311


int fun(string s, int k) {
    int sm = 0;
    int cnt = 0;
    int bits = 32 - __builtin_clz(k);
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[s.size() - 1 - i];
        if (ch == '1') {
            if (i < bits && sm + (1 << i) <= k) {
                sm += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt;
}

void solve()
{

   string s;
   cin>>s;

   int k;
   cin>>k;

   cout<< fun(s, k);



   

   

   

   
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