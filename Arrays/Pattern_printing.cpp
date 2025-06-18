#include <iostream>
#include <vector>
using namespace std;


// CRY


// * * R 
// * R Y 
// R Y C 


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    cin >> s;

    int n = s.size();
    int mid = n / 2;

    vector<vector<char>> arr(n, vector<char>(n, '*'));

    arr[0][n - 1] = s[mid]; 

    string str;
    str += s[mid];

    for (int i = 1; i < n; i++) {
        int idx = 0;

        for (int j = n - 1 - i; j < n - 1; j++) {
            arr[i][j] = str[idx++];
        }

        arr[i][n - 1] = s[(str.size()+1)%n];    
        str += s[(str.size()+1)%n];             
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
