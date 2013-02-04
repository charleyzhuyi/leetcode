class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return 0;
        int i=1;
        for (int j=1;j<n;j++){
            if (A[j] != A[j-1]){
                A[i] = A[j];
                i++;
            }
        }
        return i;
    }
};
