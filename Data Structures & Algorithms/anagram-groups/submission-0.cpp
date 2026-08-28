class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &s : strs) {
            vector<int> freq(26, 0);
            for (char x : s) freq[x - 'a']++;
            string hash = "";
            for (int i = 0; i < 26; i++) hash += to_string(freq[i]) + "#";
            mp[hash].push_back(s);
        } 
        vector<vector<string>> ans;
        for (auto &x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
