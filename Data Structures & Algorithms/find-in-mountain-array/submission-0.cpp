class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();

        // 1. Find the peak
        int start = 0;
        int end = n - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                // We are on increasing side
                start = mid + 1;
            }
            else {
                // We are on decreasing side
                end = mid;
            }
        }

        int peak = start;

        // 2. Binary search on increasing side
        start = 0;
        end = peak;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }
            else if (value < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // 3. Binary search on decreasing side
        start = peak + 1;
        end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }
            else if (value < target) {
                // Decreasing array → target is on left
                end = mid - 1;
            }
            else {
                // target is on right
                start = mid + 1;
            }
        }

        return -1;
    }
};