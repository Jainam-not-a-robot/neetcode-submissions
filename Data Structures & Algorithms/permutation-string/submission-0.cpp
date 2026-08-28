class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < s1.size(); i++) freq[s1[i] - 'a']++;
        vector<int> copy(26, 0);
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            copy[s2[r] - 'a']++;
            while (r - l + 1 > s1.size()) {
                copy[s2[l] - 'a']--;
                l++;
            }
            bool cond = true;
            for (int i = 0; i < 26; i++) {
                if (copy[i] != freq[i]) cond = false;
            }
            if (cond) return true;
        }
        return false;
    }
};
