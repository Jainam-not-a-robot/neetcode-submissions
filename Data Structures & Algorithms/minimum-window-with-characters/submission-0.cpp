class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freq, t_freq_copy;
        for (int i = 0; i < t.size(); i++) t_freq[t[i]]++;
        int remaining = t_freq.size();
        int left = -1, len = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (t_freq[s[r]]) {
                t_freq_copy[s[r]]++;
                if (t_freq[s[r]] == t_freq_copy[s[r]]) remaining--;
            }
            while (remaining == 0) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    left = l;
                }
                if (t_freq[s[l]]) t_freq_copy[s[l]]--;
                if (t_freq[s[l]] > t_freq_copy[s[l]]) remaining++;
                l++;
            }
        }
        return left == -1 ? "" : s.substr(left, len);
    }
};
