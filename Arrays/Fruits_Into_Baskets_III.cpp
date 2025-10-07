#include <bits/stdc++.h>
using namespace std;

//  3479


    vector<int> segment;

void build_segment_tree(vector<int>& baskets, int low, int high, int idx)
    {
    if(low==high)
    {
        segment[idx]= baskets[low];
        return;
    }

    int mid= low + (high-low)/2;

    build_segment_tree(baskets, low,mid, 2*idx);
    build_segment_tree(baskets, mid+1, high, 2*idx+1);

    segment[idx]= max(segment[2*idx], segment[2*idx+1]);

    }

int left_most(const int& fruit, int low, int high, int idx)
    {
    if( fruit > segment[idx] )
        return -1;

    if(low == high)
    {
        segment[idx]=-1;
        return 1;
    }

    int val;
    int mid= low + (high - low)/2;

    if( fruit <= segment[2*idx])
    val= left_most(fruit,low,mid,2*idx);
    else
    val= left_most(fruit,mid+1,high, 2*idx+1);

    segment[idx]= max(segment[2*idx], segment[2*idx+1]);

    return val;
    }
int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
    int n=fruits.size();

    segment = vector<int>(4*n+1);

    int idx=1;
    build_segment_tree(baskets, 0,n-1,idx);

    int c=0;

    for(int i=0;i<n;i++)
    {
        if( left_most(fruits[i], 0,n-1,idx) == -1)
        c++;
    }

    return c;

    }

void solve()
{

    int n;
    cin>>n;

    vector<int> fruits(n), basktes(n);

    for(int &i:fruits)
    cin>>i;

    for(int &i: basktes)
    cin>>i;

    cout<<numOfUnplacedFruits(fruits,basktes);
    
    
    


    
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