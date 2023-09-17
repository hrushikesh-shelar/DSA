class Solution {
public:
    
    bool isClosing(char n, char m) {
        if(
            (n==')' and m=='(')
            or
            (n==']' and m=='[')
            or
            (n=='}' and m=='{')
        ) {
            return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ')' or s[i] == ']' or s[i] == '}') {
                if(st.empty()) {
                    return false;
                }
                char top = (char) st.top();
                if(!isClosing(s[i], top)) {
                    return false;
                }
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};