class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        string temp = "";
        
        for (int i = 0; i <= path.size(); i++) {
            
            // If we reach '/' or end of string
            if (i == path.size() || path[i] == '/') {
                
                if (temp == "" || temp == ".") {
                    // Ignore empty string and "."
                }
                
                else if (temp == "..") {
                    // Go to parent directory
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                
                else {
                    // Normal directory
                    st.push(temp);
                }
                
                temp = "";
            }
            
            else {
                temp += path[i];
            }
        }
        
        // Build answer
        string ans = "";
        
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if (ans == "") {
            return "/";
        }
        
        return ans;
    }
};