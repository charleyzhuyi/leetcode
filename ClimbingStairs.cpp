class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int Fm2 = 1;
        int Fm1 = 2;
        int Fnow = 0;
        
        for (int i = 3; i<=n ;i++) {
            
            Fnow = Fm1 + Fm2;
            Fm2 = Fm1;
            Fm1 = Fnow;
        }
        
        return Fnow;
    }
};
