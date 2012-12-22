class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lastCount = 0;
        int count = 0;
        
        while ( *s != '\0') {
            
            if ( *s == ' ') {
                
                if (count >0)
                    lastCount = count;
                
                count = 0;
                s++;
    
            } else {
                count++;
                s++;
            }
            
            
            
        }
        
        if (count >0)
            lastCount = count;
        
        
        return lastCount;
    }
};
