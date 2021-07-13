/*Devesh-1816847*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    // 1. Adding two nums without using any arthemetic operator
    int num1, num2;
    cin >> num1 >> num2;
    cout << (num1^num2)+2*(num1&num2) << endl;

    // 2. count set bits
    int totalSetBits = 0, num;
    cin >> num;
    for(int i=31; i>=0; i--)
        totalSetBits += (num>>i)&1;
    cout << totalSetBits << endl;

    // 3. Rotate by n bits
    int num, rotateBits;
    cin >> num >> rotateBits;
    while(rotateBits--){
        if((num>>31)&1)
            --num;
        num <<= 1;
    }
    cout << num << endl;
}

// adding two nums without using any arthemetic operator
// count bits
// rotate by n bits
// 1000 0000 0000 0000
// 0000 0000 0000 1001 ->   0001 0010