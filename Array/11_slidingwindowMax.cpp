#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;

    int prevMax = INT_MIN;

    for(int i=0; i<k; i++){
        prevMax = max(prevMax, nums[i]);
    }

    result.push_back(prevMax);

    for(int i=k; i<n; i++){
        //prev max is edge element
        int maxi = INT_MIN;
        if(prevMax == nums[i-k]){
            maxi = max(maxi, nums[i]);
        }else{
            maxi = max(maxi, max(prevMax, nums[i]));
        }

        prevMax = maxi;
        result.push_back(maxi);
    }

    return result;
}

int main(){
    


    return 0;
}