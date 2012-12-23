class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        map<char,int> map;
        int maxlength = 0;
        int tail = 0;
        int head = 0;
        
        for (int i=0;i<s.size();i++) {
            
            char rchar = s[i];
            if (map[rchar] <= tail) {
                map[rchar] = i+1;
               head = i;
               
            } else {
                
                if (maxlength < head-tail+1)
                    maxlength = head-tail+1;
                
                tail = map[rchar];
                map[rchar] = i+1;
               
                head = i;
            }
            
        }
     
        
        if (head-tail+1 > maxlength)
            maxlength = head-tail+1;
        
        return maxlength;
    }
};
