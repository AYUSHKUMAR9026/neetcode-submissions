class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        deque<int> q;
        vector<int> ans;

        int sum = 0;
        int minsum = INT_MAX;

        if (k == arr.size()) {
            return arr;
        }

        // First window
        for (int i = 0; i < k; i++) {
            sum += abs(arr[i] - x);
            q.push_back(arr[i]);
        }

        minsum = sum;
        ans = vector<int>(q.begin(), q.end());

        // Sliding window
        for (int i = k; i < arr.size(); i++) {

            sum += abs(arr[i] - x);
            sum -= abs(arr[i - k] - x);

            q.pop_front();
            q.push_back(arr[i]);

            if (sum < minsum) {
                ans = vector<int>(q.begin(), q.end());
                minsum = sum;
            }
        }

        return ans;
    }
};