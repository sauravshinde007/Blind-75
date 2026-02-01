// Problem Statement: We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// 1.We can buy and sell a stock only once.
// 2.We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.

// We need to tell the maximum profit one can get by buying and selling this stock

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int mini = INT_MAX;
    int maxProfit = INT_MIN;

    for(int i : prices){
        mini = min(mini, i);
        maxProfit = max(maxProfit, i - mini);

    }

    return maxProfit;
}

int main(){



    return 0;
}