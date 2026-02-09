#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int reverseBits(int n) {
        int result = 0;

        //traverse all 32 bits
        for(int i=0; i<32; i++){
            //get the ith bit from n
            int bit = (n >> i) & 1; //right shift n by i and AND it with 1 to get the ith bit
            //because ANDing any bit with 1 will give same bit (1 & 1 = 1 , 0 & 1 = 0)

            //Add this bit to result in reverse manner (starting from MSB)
            result = result | (bit << (31 - i));
        }

        return result;
    }

int main(){
    


    return 0;
}