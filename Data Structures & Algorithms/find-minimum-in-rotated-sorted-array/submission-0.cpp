class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) {
                // Minimum is on the right side
                start = mid + 1;
            }
            else {
                // Minimum is on the left side, including mid
                end = mid;
            }
        }

        return nums[start];
    }
};