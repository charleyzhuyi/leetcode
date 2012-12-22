//O(n2) solution, can be further improved to O(n)
class Solution {
public:
    string expandAroundCenter(string s,int left,int right) {

        while (left >=0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        
        return s.substr(left+1,right-left-1);
        
    }

    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest = 0;
        string resultStr;
        
        for (int i=0;i<s.size();i++) {
            
            string aResult =expandAroundCenter(s,i,i); 
            if (aResult.size() > longest) {
                longest = aResult.size();
                
                resultStr = aResult;
            }
            
            
            string bResult = expandAroundCenter(s,i,i+1); 
            if (bResult.size() > longest) {
                longest = bResult.size();
                resultStr = bResult;
            }
        }
        
        return resultStr;
    }
};
