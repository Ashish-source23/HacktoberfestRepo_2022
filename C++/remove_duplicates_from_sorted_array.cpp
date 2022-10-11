//name: protoi
//github username: protoi

//Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int j=0;
        if(nums.size() < 1)
        {
            return 0;
        }
        for(i=0; i<nums.size(); i++)
        {
            if(nums[i] > nums[j])
            {
                j++;
            }
            nums[j]=nums[i];
        }
        return j+1;
    }
};