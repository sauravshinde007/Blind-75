#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getSum(int a, int b){
    //here b represents carry
    while(b != 0){
        int temp = a && b;
        a = a ^ b; //XOR of a and b (here a will store addition result)
        b = (temp) << 1; //left shift 1 to add carry to next (left) digits
    }

    return a;
}

int binaryToDecimal(string s){
    int result = 0;
    int base = 1;//represents (2 ^ 0 = 1)

    int n = s.size();

    for(int i=n-1; i>=0; i--){
        int bit = s[i] - '0';
        result += bit * base;
        base *= 2;
    }

    return result;
}

int main(){

    cout<<binaryToDecimal("1011");

    return 0;
}