// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) 
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target 
// if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.



#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] == target) return mid;

        //Identify Sorted Half
        //Left Sorted Half
        if(nums[low] <= nums[mid]){
            //target in sorted half
            if(target >= nums[low] && target <= nums[mid]) high = mid - 1;
            //target in unsorted half
            else low = mid + 1;
        }
        //Right Sorted Half
        else{
            //target in sorted half
            if(target >= nums[mid] && target <= nums[high]) low = mid + 1;
            //target in unsorted half
            else high = mid - 1;
        }
    }

    return -1;
    
}

int main(){



    return 0;
}