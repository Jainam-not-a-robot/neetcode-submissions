class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n - 1;
        while (l <= r) {
            int m1 = l + (r - l)/2;
            int x = m1 / n;
            int y = m1 % n;
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] > target) r = m1 - 1;
            else l = m1 + 1;
        }
        return false;
    }
};
