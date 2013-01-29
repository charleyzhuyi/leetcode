class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*haystack == '\0' &&  *needle == '\0') return "";
        if (*haystack != '\0' &&  *needle == '\0') return haystack;
        
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        for (int i=0;i<len1-len2+1;i++){
            int p = i;
            for (int j=0;j<len2;j++){
                if (haystack[p] != needle[j]) break;
                if (j == len2-1) return haystack+i;
                p++;
            }
        }
        return NULL;
    }
};
