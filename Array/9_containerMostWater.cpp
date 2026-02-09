// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of \
the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size(); //no of heights
    int maxA = INT_MIN;

    int left = 0;
    int right = n-1;

    while(left <= right){
        int w = right - left;
        int h = min(height[right], height[left]);

        maxA = max(maxA, w*h);

        if(height[left] < height[right]) left++;
        else right--;
    }

    return maxA;
}

int main(){



    return 0;
}