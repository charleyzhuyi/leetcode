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
    
    //dp solution, still O(n2) computation time. and O(n2)space 
     string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        bool check[1000][1000] = {false};
        int maxLen = 0;
        int begin = 0;
        string result;
        //base case
        for (int i=0;i<n;i++) {
            check[i][i]=true;
            maxLen = 1;
            result = s.substr(i,1);
        }
        for (int i=0;i<n-1;i++) {
            if (check[i][i] && s[i]==s[i+1]){
                
                check[i][i+1]=true;
                 maxLen = 2;
                begin = i;
            }
        }
        
        for (int len=3;len<=n;len++) {
            
            for (int i=0;i<n-len+1;i++) {
                
                int j = i+len-1;
               if (check[i+1][j-1] && s[i] == s[j]) {
                   
                   check[i][j] = true;
                   maxLen = len;
                   begin = i;
               }
                
                
            }
            
            
        }
        
        return s.substr(begin,maxLen);
        
    }
};
