#include <bits/stdc++.h>
using namespace std;


int toggle(int num, int pos){
    int mask = 1 << pos;
    num ^=mask;
    return num;
}

int main(){
    int num,pos;
    cin >> num >> pos;
    cout << toggle(num,pos) << endl;
    return 0;
    
}