#include <bits/stdc++.h>
using namespace std;

string toLower(string & s){
    string res;
    for(char c: s){
        if('A' <= c && 'Z' >= c) res += static_cast<char>(c+32);
        else res+=c;
    }

    return res;
}

string toUpper(string & s){
    string res;
    for(char c: s){
        if('a' <= c && 'z' >= c) res += static_cast<char>(c-32);
        else res+=c;
    }

    return res;
}

int main(){
    string s;
    cin >> s;
    string low,high;
    low=toLower(s);
    high=toUpper(s);
    cout<<"to lower "<< low<<endl;
    cout<< "TO UPPER " << high <<endl;

}