class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (string &s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                len = len*10 +(s[i] - '0');
            }
            else if (s[i] == '#') {
                ans.push_back(s.substr(i+1, len));
                i += len;
                len = 0;
            }
        }
        return ans;
    }
};
