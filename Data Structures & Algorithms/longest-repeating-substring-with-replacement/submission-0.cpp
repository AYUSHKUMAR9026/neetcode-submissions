class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        int ans = 1;

        char maxc = s[0];
        int maxval = 0;

        int j = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < n; i++) {

            m[s[i]]++;

            if (m[s[i]] > maxval) {
                maxc = s[i];
                maxval = m[s[i]];
            }

            // replacements needed =
            // window size - frequency of most frequent character
            while ((i - j + 1) - maxval > k) {

                m[s[j]]--;
                j++;

                // recompute maximum frequency
                maxval = 0;

                for (auto &p : m) {
                    if (p.second > maxval) {
                        maxval = p.second;
                        maxc = p.first;
                    }
                }
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};