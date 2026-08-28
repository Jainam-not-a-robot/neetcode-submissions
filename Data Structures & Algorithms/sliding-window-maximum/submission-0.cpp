class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int l = 0;
        vector<int> ans;
        for (int r = 0; r < nums.size(); r++) {
            while (!dq.empty() && nums[r] > nums[dq.back()]) dq.pop_back();
            dq.push_back(r);
            while (!dq.empty() && r - dq.front() + 1 > k) dq.pop_front();
            if (r >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
