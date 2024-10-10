#include <bits/stdc++.h>
using namespace std;

void Selection_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minn=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[minn])
            minn=j;
        }
        swap(arr[i],arr[minn]);
    }
}

int main()
{
    cout<<"Enter the N ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Selection_sort(arr,n);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
    
}