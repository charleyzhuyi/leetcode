class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n-1;
        while (left <=right){
            int med = (left+right)/2;
            if (A[med]==target){
                return med;
            }else if (target >=A[0]){
                if (A[med] < target && A[med] >=A[0]){
                    left= med+1;
                } else right = med-1;
            }else {
                if (A[med] > target && A[med] < A[0]){
                    right = med-1;
                }else left = med+1;
            }
        }
        return -1;
    }
};
