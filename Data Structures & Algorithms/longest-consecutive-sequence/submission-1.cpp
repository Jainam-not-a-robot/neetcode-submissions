class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); 
        int maxim = 0;
        for (int x : s) {
            if (s.find(x-1) == s.end()) {
                int r = x;
                while (s.find(r) != s.end()) r++;
                maxim = max(r - x, maxim);
            }
        }  
        return maxim;
    }
};
