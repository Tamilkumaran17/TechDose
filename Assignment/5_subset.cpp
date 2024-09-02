#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr,int n){
    vector<vector<int>> subsets;

    int tot = 1 << n;

    for(int i=0; i<tot ;i++){
        vector<int> list;
        for(int j=0; j<n; j++){
            if((i & (1 << j))){
                list.push_back(arr[j]);
            }
        }
        subsets.push_back(list);
    }
    cout<<"The subsets are \n";

    for(auto &sub: subsets){
        cout<<"[ ";
        for(int i : sub){
            cout<< i << " ";
        }
        cout<<"]";

        cout<<endl;
    }
}



int main() {
    int num;
    cout<<"Enter the value for N: ";
    cin >> num;

    vector<int> arr(num);
    for(int i = 0; i < num; i++){
        cin>>arr[i];
    }
    subsets(arr,num);
   
    return 0;
}