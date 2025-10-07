#include <bits/stdc++.h>
using namespace std;

//  949

string largestTimeFromDigits(vector<int>& arr) {

        sort(arr.begin(),arr.end(),greater<int>());

        do{
            int h= arr[0] * 10 + arr[1];
            int m= arr[2] * 10 + arr[3];

            if(h<24 && m<60)
            {
                string time="";

                if(h < 10)
                time+="0";

                time+=to_string(h);

                time+=":";

                if(m < 10)
                time+="0";

                time+= to_string(m);

                return time;
            }
        }while(prev_permutation(arr.begin(),arr.end()));
        
        return "";
    }



void solve()
{

    int n;
    cin>>n;

    vector<int> arr(n);
    
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<< largestTimeFromDigits(arr)<<endl;

   


    

    

    



   
    
    


    
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