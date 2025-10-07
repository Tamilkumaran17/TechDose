#include <bits/stdc++.h>
using namespace std;


struct Task
{
    int start, end; 
};


void sort_2darr(Task arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if( arr[j].start > arr[j+1].start || (arr[j].start == arr[j+1].start && arr[j].end > arr[j+1].end) )
            {
                Task temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int schedule(int n,Task arr[],int cooldown, int m )
{
    sort_2darr(arr,n);

    int last_time[100];
    int count[100];
    int cores=0;

    for(int i=0;i<n;i++)
    {
        int placed=0;

        for(int c=0; c<cores;c++)
        {
            if( arr[i].start >= last_time[c] + cooldown && count[c] < m)
            {
                last_time[c]= arr[i].end;
                count[c]++;
                
                placed=1;
                break;
            }
        }

        if(!placed)
        {
            last_time[cores]= arr[i].end;
            count[i]=1;
            cores++;
        }
    }

    return cores;
}
int main()
{
    int n=5, cooldown= 0, m=1;
    Task arr[5]= { {1,2}, {2,3}, {3,4}, {4,5},{5,6}};

    cout<< schedule(n,arr,cooldown,m);

}