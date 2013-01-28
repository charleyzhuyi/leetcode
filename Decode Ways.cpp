class Solution {
public:
    int numDecodings(string str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = str.size();
        if (n == 0) return 0;
        
        int dways[n+1];
        dways[0] = 1;
        
        if ((int)(str[n-1]-'0') == 0 ) {
            dways[1] = 0;
        }else {
            dways[1] = 1;
        }
        
        for (int i=2;i<=n;i++) {
            int ci = (int)(str[n-i]-'0');
            if (ci == 0) {
                dways[i] = 0;
            } else if (ci == 1 || (ci == 2 && (int)(str[n-i+1]-'0') <= 6) ) {
                dways[i] = dways[i-1] + dways[i-2];
            } else {
                dways[i] = dways[i-1];
            }
        }
        
        return dways[n];
    }
};
