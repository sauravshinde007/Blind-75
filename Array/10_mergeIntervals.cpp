#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping 
// intervals that cover all the intervals in the input.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size() <= 1){
            return intervals;
        }

        //sort the array
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        for(auto &interval : intervals){
            //if ans is empty or not mergable then add the elem
            if(ans.empty() || ans.back()[1] < interval[0] ){
                ans.push_back(interval);
            }else{
                //mergable intervals (update the end of answer's back)
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;

    }

void print(vector<vector<int>> arr){
    int n = arr.size();
    cout<<"[ "<<endl;
    for(int i=0; i<n; i++){
        cout<<"[ "<<arr[i][0]<<", "<<arr[i][1]<<"], ";
    }
    cout<<"]"<<endl;
}

int main(){
    
    vector<vector<int>> arr = {{4,7}, {1,4}};

    sort(arr.begin(), arr.end());

    print(arr);


    return 0;
}