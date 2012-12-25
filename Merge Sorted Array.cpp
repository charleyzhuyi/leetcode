class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int posA = m-1;
        int posB = n-1;
        
        int last = m+n-1;
        
        while (last >=0) {
            
            if (posA >=0 && posB >=0) {
                if (A[posA] > B[posB]) {
                    A[last] = A[posA];
                    posA--;
                } else {
                    A[last] = B[posB];
                    posB--;
                }
            } else if (posA < 0){
                A[last] = B[posB];
                posB--;
            }
            
            last--;
            //Don't need to consider if posB < 0, because the sorted array area already in place.
            
        }
        
    }
};
