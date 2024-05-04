/* Problem --> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/  */


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.empty()) {
            ans.push_back(-1); ans.push_back(-1);
            return ans;
        }
        if(nums.size() == 1) {
            if(nums[0] == target) {
                ans.push_back(0); ans.push_back(0);
            }
            else {
                ans.push_back(-1); ans.push_back(-1);
            }
            return ans;
        }
        int t1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int t2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if(t1 < nums.size() && nums[t1] == target) ans.push_back(t1);
        else ans.push_back(-1);
        if(t2 >= 0 && nums[t2] == target) ans.push_back(t2);
        else ans.push_back(-1);

        return ans;
    }
};