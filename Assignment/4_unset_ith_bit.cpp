#include <bits/stdc++.h>
using namespace std;

int unsetIthBit(int n, int i) {
    int mask = ~(1 << i);
    
    return n & mask;
}

int main() {
    int num;
    cin >> num;
    int i;
    cin >> i;
    
    int resultUnset = unsetIthBit(num, i);
    
    std::cout << "Result after unsetting the ith bit: " << resultUnset << std::endl;
    
    return 0;
}