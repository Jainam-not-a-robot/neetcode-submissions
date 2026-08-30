class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int elems = (m + n + 1)/2;
        int l = 0, r = m;
        while (l <= r) {
            int cut1 = l + (r - l)/2;
            int cut2 = elems - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == m ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0) {
                    return (float)(max(l1, l2) + min(r1, r2))/2;
                }
                else return (float)(max(l1, l2));
            }
            else if (l1 > r2) r = cut1 - 1;
            else l = cut1 + 1;
        }
        return -1;
    }
};
