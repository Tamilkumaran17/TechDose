
#include <bits/stdc++.h>
using namespace std;

int setIthBit(int n, int i) {
    int mask = 1 << i;
    
    return n | mask;
}

int main() {
    int num;
    cin>>num;
    int i;
    cin>>i;     
    
    int result = setIthBit(num, i);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}