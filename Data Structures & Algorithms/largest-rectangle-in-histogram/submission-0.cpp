class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextsmall(heights.size(), 0), prevsmall(heights.size(), 0);
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nextsmall[i] = st.empty() ? heights.size() : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            prevsmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, (nextsmall[i] - prevsmall[i] - 1) * heights[i]);
        }
        return ans;
    }
};
