#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    //Sort the array
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for(int i=0; i<n; i++){
        //check for duplicate i (if duplicate then skip)
        if(i !=0 && nums[i] == nums[i-1]) continue;

        int j = i+1;
        int k = n-1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                //Sum is 0 (triplet found)
                vector<int> temp = {nums[i], nums[j], nums[k]};
                result.push_back(temp);

                j++;
                k--;

                //after moving j and k check if duplicate j or k found
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;

            }
        }
    }

    return result;
}

int main(){



    return 0;
}