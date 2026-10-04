class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // pair = {position, speed}
        vector<pair<int, int>> cars;

        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position in descending order
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Store arrival times
        vector<double> time(n);

        for(int i = 0; i < n; i++) {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        stack<double> st;

        for(int i = 0; i < n; i++) {

            if(st.empty() || time[i] > st.top()) {
                st.push(time[i]);
            }
        }

        return st.size();
    }
};