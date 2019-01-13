// Problem found at: https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		// Each index represents a color. Value of each index is how many of each color are needed.
        int arr[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        // Regenerate vector in order.
        nums.clear();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < arr[i]; j++)
                nums.push_back(i);
        }
    }
};