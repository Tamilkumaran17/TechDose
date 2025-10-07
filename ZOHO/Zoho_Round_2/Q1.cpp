#include <bits/stdc++.h>
using namespace std;


int prime_factor(int n)
{
    int c=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c++;
            while(n%i==0)
            n/=i;

        }
    }

    if(n>1)
    c++;

    return c;
}

int digit_sum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+= (n%10);
        n/=10;
    }
    return sum;
}


bool sort_arr(int pf1, int pf2, int ds1, int ds2, int idx1, int idx2)
{
    if( pf1 < pf2)
    return true;

    if( pf1== pf2 && ds1 < ds2)
    return true;

    if(pf1==pf2 && ds1 == ds2 && idx1 > idx2)
    return true;

    return false;
}

void custom_sort(int arr[], int n)
{
    int pf[100], ds[100], idx[100];

    for(int i=0;i<n;i++)
    {
         pf[i]= prime_factor(arr[i]);
        ds[i]= digit_sum(arr[i]);
        idx[i]= i;
    }


    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(sort_arr(pf[j], pf[j+1], ds[j], ds[j+1], idx[j], idx[j+1])){

                int temp;

                temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp;
                
                temp= pf[j]; pf[j]= pf[j+1]; pf[j+1]=temp;

                temp= ds[j]; ds[j]=ds[j+1]; ds[j+1]=temp;

                temp= idx[j]; idx[j]= idx[j+1]; idx[j+1]= temp;
                
            }
        }
    }
}


int main()
{
    int arr[]={22,35,40};
    int n=sizeof(arr)/sizeof(arr[0]);

    custom_sort(arr,n);

    for(int i:arr)
    cout<<i <<" ";
}