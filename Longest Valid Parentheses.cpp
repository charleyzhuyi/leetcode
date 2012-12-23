class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxCount =0;
        int sum = 0;
        int count = 0;
        for (int i=0;i<s.size();i++){
            int value = s[i]=='('?sum++:sum--;
            if (sum >=0) {
                count++;
                if ( sum == 0) {
                    if (count > maxCount)
                        maxCount = count;
                }
            } else {
                count = 0;
                sum = 0;
            }
        }
        
        sum = 0;
        count = 0;
        for (int i=s.size()-1;i>=0;i--) {
              int value = s[i]==')'?sum++:sum--;
            if (sum >=0) {
                count++;
                if ( sum == 0) {
                    if (count > maxCount)
                        maxCount = count;
                }
            } else {
                count = 0;
                sum = 0;
            }
        }
        
        
        return maxCount;
    }
};
