class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = false;
        if ( (dividend > 0 && divisor < 0) || (dividend <0 && divisor > 0)) {
            neg = true;
        }
        
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        int a = dividend;
        int b =divisor;
        
        if (divisor == 0) {
            return INT_MAX;
        }
        if (divisor == INT_MIN) {
            return (dividend == INT_MIN) ? 1 : 0;
        }
        if (dividend == INT_MIN) {
            if (neg) {
                return -1 + divide(dividend + b, b);
            }
            else {
                return 1 - divide(dividend + b, b);
            }
        }
        

        int result = 0;
        
         
    while ( a >=b) {
        int q = 1;
        while (a - b >=b ) {
            b = b << 1;
            q = q << 1;
        }
        a = a-b;
        b = divisor; 
        result += q;
        
    }
        
        return neg?-result:result;
    }
    
};
