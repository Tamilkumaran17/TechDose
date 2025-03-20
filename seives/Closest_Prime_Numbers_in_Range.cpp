#include <bits/stdc++.h>
using namespace std;

vector<int> Eratosthenes(int n){
    vector<int> isPrime(n+1,1);
    isPrime[0]=0;
    isPrime[1]=0;

    for(int i=2 ; i*i <= n; i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=0;
            }    
        }
    }

    return isPrime;
}

void solve()
{
    int left,right;
    cin>>left>>right;

    vector<int> prims = Eratosthenes(right);

    vector<int> primearr;
    for(int i=left;i<=right;i++)
    {
        if(prims[i]==1)
        primearr.push_back(i);
    }

    int minn=INT_MAX;
    vector<int> ans(2,-1);
    

    for(int i=0;i<primearr.size()-1;i++)
    {
        int diff=primearr[i+1]-primearr[i];
        if(diff < minn)
        {
            minn=diff;
            ans[0]=primearr[i];
            ans[1]=primearr[i+1];
        }
    }

    cout<<"The ans is : {"<<ans[0] <<" , "<<ans[1] << "}";
    

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    


}