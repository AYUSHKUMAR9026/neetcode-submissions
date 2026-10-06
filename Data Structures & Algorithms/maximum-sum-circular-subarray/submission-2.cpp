class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int ans = INT_MIN;

        // Normal Kadane
        for (int i = 0; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }

        // All elements are negative
        if (ans < 0) {
            return ans;
        }

        // Total sum
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // Find minimum subarray
        int minSum = 0;
        int minAns = INT_MAX;

        for (int i = 0; i < n; i++) {
            minSum = min(nums[i], minSum + nums[i]);
            minAns = min(minAns, minSum);
        }

        // Circular maximum
        int circularSum = total - minAns;

        return max(ans, circularSum);
    }
};