class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        if (*haystack == '\0' &&  *needle == '\0') return "";
        if (*haystack != '\0' &&  *needle == '\0') return haystack;
        
        char *p ;
        char *save = NULL;
        bool matched = false;
        
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        
        for (int i=0;i<len1-len2+1;i++) {
            
            p = &haystack[i];
            
            char *n = needle;
            
            if ( *p == *n) {
                
                save = p;
                
                
                matched = true;
                
                while ( *n != '\0') {
                    
                    if (*p == * n) {
                        
                        p++;
                        n++;
                    }else {
                        matched = false;
                        break;
                    }
                    
                }
                
                if (matched) {
                    break;
                } else {
                    p = save;
                }
                
            }
            p++;
            
        }
        if (matched)
            return save;
        else
            return NULL;
    }
};
