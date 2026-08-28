class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (l != i+1 && nums[l] == nums[l-1]) {
                    l++;
                    continue;
                }
                if (r != nums.size() - 1 && nums[r] == nums[r+1]) {
                    r--;
                    continue;
                }
                if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] > 0) r--;
                else l++;
            }
        }
        return ans;
    }
};
