class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxc = 0;

        while (left < right) {
            int h = min(heights[left], heights[right]);
            int width = right - left;

            maxc = max(maxc, h * width);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxc;
    }
};