#include <bits/stdc++.h>
using namespace std;


void rotate(vector<int>&nums, int start, int end)
{
    while (start<end)
    {
        /* code */
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
    
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int &i:arr)
    cin>>i;

    int k;
    cin>>k;

    k=k%n;

    rotate(arr,0,n-1);
    rotate(arr,0,k-1);
    rotate(arr,k,n-1);

    cout<< "The rotated array is "<<endl;

    for(int i:arr)
    cout << i <<" ";
   
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