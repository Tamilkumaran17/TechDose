#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> & arr, int dist, int k){
    int n = arr.size();
    int count = 1;
    int last=arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] -last  >= dist){

            count++;
            last = arr[i];
        }
        if(count >= k) return 1;
    }
        return 0;
}

int Aggressive_cows(vector<int>& arr, int k){
    int n = arr.size();
    sort(arr.begin(),arr.end());

    int left =1, right = arr[n-1]-arr[0];
    while(left <= right){
        int mid = (left + right)/2;
        if(is_possible(arr, mid, k)){
            left = mid+1;
            }
            else{
               right = mid-1;
                }

    }
    return right;



}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        cout<<Aggressive_cows(arr,k)<<endl;
    }
    
}
