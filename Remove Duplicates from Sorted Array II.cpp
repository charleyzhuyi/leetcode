class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return 0;
        int i=1;
        int count = 0;
        for (int j=1;j<n;j++){
            if (A[j] != A[j-1]){
                A[i] = A[j];
                i++;
                count = 0;
            }else {
                if (count<=0) {  //can be changed to any number to allow to dupliate any times.
                    A[i]=A[j];
                    i++;
                }
                count++;
            }
        }
        return i;
    }
};
