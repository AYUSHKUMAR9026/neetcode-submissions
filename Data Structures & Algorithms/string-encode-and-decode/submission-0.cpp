class Solution {
public:

    string encoded = "";

    string encode(vector<string>& strs) {

        for (int i = 0; i < strs.size(); i++) {

            int length = strs[i].length();

            encoded += to_string(length) + "#" + strs[i];
        }

        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while (i < s.length()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Convert length from string to integer
            int length = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Take 'length' characters
            ans.push_back(s.substr(j, length));

            // Move to next encoded string
            i = j + length;
        }

        return ans;
    }
};