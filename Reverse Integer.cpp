class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = false;
        if (x<0){
            x = -x;
            neg = true;
        }
        
        int numDigits = 1;
        int result = 0;
        while (x>0){
            int digit = x%10;
            result = result*10+digit;
            x = x/10;
        }
        
        if (neg) return -result;
        else return result;
    }
};
