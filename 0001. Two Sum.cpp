Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


---------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int>v;
        for (int i = 0; i < nums.size(); i++) {
            int cpl = target - nums[i];
            if (mp[cpl] != 0) {
                v.push_back(i);
                v.push_back(mp[cpl] - 1);
                return v;
            }
            mp[nums[i]] = i + 1;
        }
        return v;
    }
};
