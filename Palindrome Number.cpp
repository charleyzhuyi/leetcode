class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<0) return false;
     
        
        int divide = 1;
        Palindrome Number
        while (x/divide>=10)
            divide *=10;
        
        while (x != 0) {
            int l = x/divide;
            int r = x%10;
            if (l != r) return false;
            
            x = (x%divide) / 10;
            divide = divide/100;
        }
        
        return true;
    }
};
