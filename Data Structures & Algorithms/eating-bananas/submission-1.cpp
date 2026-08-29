class Solution {
public:
    bool possible(vector<int> &piles, int m, int h) {
        int time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + m - 1) / m;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if (h < piles.size()) return -1;
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int m = l + (r - l)/2;
            if (possible(piles, m, h)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
