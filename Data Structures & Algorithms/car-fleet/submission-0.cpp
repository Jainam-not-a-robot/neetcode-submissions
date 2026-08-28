class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++) v.push_back({position[i], speed[i]});
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        float time = 0;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            float curr_time = (float)(target - v[i].first) / v[i].second;
            if (curr_time > time) {
                cnt++;
                time = curr_time;
            }
        }
        return cnt;
    }
};
