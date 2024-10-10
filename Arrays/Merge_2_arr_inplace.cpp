#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);

    // Input arrays
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int j = 0; j < m; j++) cin >> arr2[j];

    for(int i=n-1,j=0; i>=0,j<m;i--,j++)
    {
        if(arr1[i] > arr2[j])
        swap(arr1[i],arr2[j]);

        else
        break;
    }

    sort(begin(arr1),end(arr1));
    sort(begin(arr2),end(arr2));

// Print the modified array
for (int i = 0; i < n; i++) cout << arr1[i]<<" ";
cout<<endl;
for (int j = 0; j < m; j++) cout << arr2[j]<<" ";

    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
}
