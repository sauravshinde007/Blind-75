#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isTwoSum(vector<int> &arr, int target){
    int n = arr.size();
    unordered_map<int, int> mpp; //value and freq

    for(int i : arr){
        int complement = target - i;
        if(mpp.find(complement) != mpp.end()) return true;
        
        //add curent i in the map
        mpp[i]++;
    }

    //if not found
    return false;
}

int main(){

    vector<int> arr = {1, 2, 5, 0, -1};
    
    if(isTwoSum(arr, 7)) cout<<"True"<<endl;
    else cout <<"False"<<endl;

    return 0;
}