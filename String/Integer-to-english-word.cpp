#include <bits/stdc++.h>
using namespace std;

string int_to_eng(map<int,string>& ones, map<int,string>& tens,map<int,string>& onecase,vector<int>& digit)
{

    // {0 1 2} {3 4 5} {6 7 8} 9
    // compute set of three which are need to be repeted
    // example: 
    //          2,341 means compute last three set {341} and add thousand and add next set of three, ie{2}
    

    string ans;
    
    if(digit[9]) ans += ones[digit[9]]+" Billion ";  //billion


    if(digit[8]) ans += ones[digit[8]]+" Hundred ";

    if(digit[7]==1) ans += onecase[digit[6]]+ " ";
    else{
        if(digit[7]) ans += tens[digit[7]]+ " ";
        if(digit[6]) ans += ones[digit[6]]+ " ";
    }
    if(digit[8] || digit[7] || digit[6]) ans += "Million ";



    if(digit[5]) ans += ones[digit[5]]+ " Hundred ";

    if(digit[4]==1) ans += onecase[digit[3]] + " ";
    else{
        if(digit[4]) ans += tens[digit[4]] + " ";
        if(digit[3]) ans += ones[digit[3]] + " ";
    }
    if(digit[5] || digit[4] || digit[3]) ans += "Thousand ";



    if(digit[2]) ans+= ones[digit[2]]+ " Hundred ";

    if(digit[1]==1) ans += onecase[digit[0]] + " ";
    else{
        if(digit[1]) ans += tens[digit[1]] + " ";
        if(digit[0]) ans += ones[digit[0]] + " ";
    }

    while(ans.size() && ans.back()==' ')
    ans.pop_back();


    
    return ans;

} 

void solve(int num)
{
    if(num==0)
    cout<<"Zero";

    map<int, string> ones;
    ones[0]="";
    ones[1]="One";
    ones[2]="Two";
    ones[3]="Three";
    ones[4]="Four";
    ones[5]="Five";
    ones[6]="Six";
    ones[7]="Seven";
    ones[8]="Eight";
    ones[9]="Nine";

    map<int, string> tens;
    tens[0]="";
    tens[1]="Ten";
    tens[2]="Twenty";
    tens[3]="Thirty";
    tens[4]="Forty";
    tens[5]="Fifty";
    tens[6]="Sixty";
    tens[7]="Seventy";
    tens[8]="Eighty";
    tens[9]="Ninety";

    map<int, string> onecase;
    onecase[0]="Ten";
    onecase[1]="Eleven";
    onecase[2]="Twelve";
    onecase[3]="Thirteen";
    onecase[4]="Fourteen";
    onecase[5]="Fifteen";
    onecase[6]="Sixteen";
    onecase[7]="Seventeen";
    onecase[8]="Eighteen";
    onecase[9]="Nineteen";

    vector<int> digit;

    int n=num;
    while(n)
    {
        digit.push_back(n%10);
        n/=10;
    }

    while(digit.size()<10)
    {
        digit.push_back(0);
    }

    cout<< int_to_eng(ones,tens,onecase,digit);

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 

    int num;
    cin>>num;
// cout<<num<<" poda";
    solve(num);
    return 0;
}