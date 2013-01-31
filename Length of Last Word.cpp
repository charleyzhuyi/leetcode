class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strlen(s);
        int p = n-1;
        int count = 0;
        while (s[p] == ' ' && p >=0) p--;
        while (s[p] != ' ' && p >=0) {
            count++;
            p--;
        }
        return count;
    }
};
