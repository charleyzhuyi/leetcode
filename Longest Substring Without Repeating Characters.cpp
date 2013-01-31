class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char ht[26] = {0};
        int maxlen = 0;
        int begin_pos = 0;
        for (int i=0;i<s.size();i++){
            int foundpos = ht[s[i]-'a'];
            if (foundpos == 0) {
                ht[s[i]-'a'] = i+1;
                if (i-begin_pos+1 > maxlen) maxlen = i-begin_pos+1;
            } else {
                for (int j = begin_pos; j< foundpos;j++) ht[s[j]-'a'] = 0;
                ht[s[i]-'a'] = i+1;
                begin_pos = foundpos;
            }
        }
        return maxlen;
    }
};
