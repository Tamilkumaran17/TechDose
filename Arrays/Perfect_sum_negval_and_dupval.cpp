// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int>& arr, int tar,int k,int st,int cursum,vector<int>& curr, set<vector<int>>& ans)
{
    if(curr.size() == k){
    if(cursum==tar)
    {
        ans.insert(curr);
    }
    return;
}
    
    if(st>=n)
    return;
    
    curr.push_back(arr[st]);
    dfs(n,arr,tar,k,st+1,cursum+arr[st],curr,ans);
    curr.pop_back();
    dfs(n,arr,tar,k,st+1,cursum,curr,ans);
}

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    
    vector<int> arr={1, 9, -1, 8, 6};
    int tar=4;
    int k=2;
    
    set<vector<int>> ans;
    vector<int> curr;
    
    dfs(arr.size(), arr,tar,k,0,0,curr,ans);
    if(!ans.empty()){
    for(auto ir:ans)
    {
        cout<<"[";
        for(auto j:ir)
        {
            cout<<j<<" ";
        }
        cout<<"], ";
    }}
    else
    cout<<"[]";
    return 0;
}