class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return 1.0;
        if (n==1) return x;
        bool neg = false;
        if (n<0) {
            neg = true;
            n = -n;
        }
        double result = pow(x,n >> 1);
        result *= result;
        if (n&1) result = result*x;
        if (neg) {
            return 1.0/result;
        }
        else {
            return result;}
    }
};
