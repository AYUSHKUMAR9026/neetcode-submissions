class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n, 1);
        vector<int> suff(n, 1);

        int ans = 1;

        // Prefix product
        for (int i = 0; i < n; i++) {
            pref[i] = ans;
            ans *= nums[i];
        }

        ans = 1;

        // Suffix product
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = ans;
            ans *= nums[i];
        }

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = pref[i] * suff[i];
        }

        return a;
    }
};