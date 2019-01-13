// Problem found at: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        
        if (nums.empty()) {
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }
        int pivot_idx = find_pivot(nums);
        
        if (target < nums[pivot_idx]) {
            // search left
            for (int i = pivot_idx; i >= 0; i--) {
                if (nums[i] == target)
                    range.push_back(i);
            }
        } else if (target > nums[pivot_idx]) {
            // search right
            for (int i = pivot_idx; i < nums.size(); i++) {
                if (nums[i] == target)
                    range.push_back(i);
            }
        } else if (target == nums[pivot_idx]) {
            // search left until different element found, then search right until
            // diff element found 
            for (int i = pivot_idx; i >= 0; i--) {
                if (nums[i] == target)
                    range.push_back(i);
                else
                    break;
            }
            for (int i = pivot_idx; i < nums.size(); i++) {
                if (nums[i] == target)
                    range.push_back(i);
                else
                    break;
            }
        }
        
        if (range.empty()) {
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }
        trim_range(range);
        
        return range;
    }
    
    int find_pivot(vector<int> &nums) {
        return nums.size() / 2;
    }
    
    void trim_range(vector<int> &range) {
        sort(range.begin(), range.end());
        range.erase(range.begin()+1, range.end()-1);
    }
};