class Solution {
public:
    int trap(vector<int>& height) {
        int maxh = 0;
        int maxi = 0;

        if (height.size() <= 2) {
            return 0;
        }

        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxh) {
                maxh = height[i];
                maxi = i;
            }
        }

        int store = 0;
        int curr = height[0];

        // Left side of the global maximum
        for (int i = 1; i < maxi; i++) {
            if (height[i] > curr) {
                curr = height[i];
            } else {
                store += min(maxh, curr) - height[i];
            }
        }

        curr = height[height.size() - 1];

        // Right side of the global maximum
        for (int i = height.size() - 2; i > maxi; i--) {
            if (height[i] > curr) {
                curr = height[i];
            } else {
                store += min(maxh, curr) - height[i];
            }
        }

        return store;
    }
};