#include <bits/stdc++.h>
using namespace std;


// Intuition

//      Cantor's diagonal argumentis a proof in set theory.

//          While we do not need to fully understand the proof and its consequences, this approach uses very similar ideas.

//          We start by initializing the answeransto an empty string. To buildans, we need to assign either"0"or"1"to each indexifor indices0ton - 1. How do we assign them soansis guaranteed to be different from every string innums? We know that two strings are different, as long as they differ by at least one character. We can intentionally construct ouransbased on this fact.

//  For each index  i, we will check thei 
// th
//  character of thei 
// th
//  string innums. That is, we checkcurr = nums[i][i]. We then assignans[i]to the opposite ofcurr. That is, ifcurr = "0", we assignans[i] = "1". Ifcurr = "1", we assignans[i] = "0".

// What is the point of this strategy?answill differ from every string inat leastone position. More specifically:

// ansdiffers fromnums[0]innums[0][0].
// ansdiffers fromnums[1]innums[1][1].
// ansdiffers fromnums[2]innums[2][2].
// ...
// ansdiffers fromnums[n - 1]innums[n - 1][n - 1].
// Thus, it is guaranteed thatansdoes not appear innumsand is a valid answer.

// This strategy is applicable because both the length ofansand the length of each string innumsare larger than or equal ton, the number of strings innums. Therefore, we can find one unique position for each string innums.



void solve()
{
    int n;
    cin >> n;
    
    vector<string> arr;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr.push_back({s});
    }

    string ans;

    for(int i=0;i<n;i++)
    {
        char curr=arr[i][i];
        ans+= curr=='0' ? '1' : '0';
    }

    cout<<"Find Unique Binary String "<<ans;
   
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

    return 0;

}