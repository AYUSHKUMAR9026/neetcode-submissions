class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;

        while (i < n) {

            // If it is a closing bracket
            if (s[i] == ']') {

                string val = "";

                // Take everything until [
                while (st.top() != "[") {
                    val = st.top() + val;
                    st.pop();
                }

                // Remove [
                st.pop();

                // Get number
                int k = stoi(st.top());
                st.pop();

                // Repeat val k times
                string temp = "";

                for (int j = 0; j < k; j++) {
                    temp += val;
                }

                // Put decoded string back
                st.push(temp);
            }

            // If it is a number
            else if (isdigit(s[i])) {
                string num = "";

                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }

                st.push(num);
                continue;
            }

            // If it is [ or normal character
            else {
                st.push(string(1, s[i]));
            }

            i++;
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};