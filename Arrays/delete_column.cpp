


// Given a 2D character array arr[r][c] with characters and special symbols:

// <: delete the left column and replace < with *

// >: delete the right column and replace > with *

// You want to output the modified array after applying these deletions and symbol replacements.



#include <bits/stdc++.h>
using namespace std;

int main() {

      #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    
    int r,c;
    cin>>r>>c;
    
    vector<vector<char>>  arr(r,vector<char>(c));
    
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    cin>>arr[i][j];
    
    vector<int> mark(c,0);
    
    for(int j=0;j<c;j++)
    {
        for(int i=0;i<r;i++)
        {
            if(arr[i][j]=='<' || arr[i][j]=='>')
            {
                mark[j]=1;
                break;
            }
        }
    }
    
    vector<int> todelete = mark;
    
    for(int j=0;j<c;j++)
    {
        if(todelete[j]==1){
            for(int i=0;i<r;i++)
                {
                    if(arr[i][j]=='<')
                    {
                        if(j > 0)
                        todelete[j-1]=-1;

                        arr[i][j]='*';
                        todelete[j]=0;
                        break;
                    }
                    
                    if(arr[i][j]=='>')
                    {
                        if(j < c-1)
                        todelete[j+1]=-1;

                        arr[i][j]='*';
                        todelete[j]=0;
                        break;
                    }
                }
        }
    }
    
    for(int i=0;i<r;i++)
    {
       
            for(int j=0;j<c;j++)
            {
                if(todelete[j]!=-1)
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        
    }
    
    

    return 0;
}


