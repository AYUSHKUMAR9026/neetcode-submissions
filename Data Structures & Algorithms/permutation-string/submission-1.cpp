class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> need, window;

        for (char c : s1) {
            need[c]++;
        }

        int n = s1.size();

        for (int i = 0; i < s2.size(); i++) {

            window[s2[i]]++;

            // Keep window size = s1.size()
            if (i >= n) {
                window[s2[i - n]]--;
                
                if (window[s2[i - n]] == 0)
                    window.erase(s2[i - n]);
            }

            // Check whether current window is a permutation
            if (window == need)
                return true;
        }

        return false;
    }
};