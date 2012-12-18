class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool check[n+1];
        check[0] = true;
        
        for (int i=0;i<n;i++) {
            if (A[i]<0) continue;
            
            if (A[i] > n) continue;
            
            check[A[i]] = true;
            
        }
        
        for (int j=0;j<n+1;j++) {
            
            if (check[j] == false) return j;
        }
        
        return n+1;
        
    }
};
