class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        int n = s.size();
        int pos = 0;
        while (pos < n){
            if (s[pos] == '(' || s[pos] == '{' || s[pos] == '['){
                st.push(s[pos]);
            }else if (st.empty()){
                return false;
            }else {
               if (s[pos] == ')'){
                    if (st.top() != '(') return false;
               }else if (s[pos] == '}'){
                   if (st.top() != '{') return false;
               }else if (s[pos] == ']'){
                   if (st.top() != '[') return false;
               }
               st.pop();
            }
            pos++;
        }  
        if (st.empty()) return true;
        else return false;
    }
};
