class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return 0;
        int left= 0;
        int right = n-1;
        while (left < right){
            int med = (left+right)/2;
            if (A[med] == target) return med;
            else if (A[med] < target) left= med+1;
            else  right = med-1;
        }
        if (target == A[left]) return left;
        if (target > A[left]) return left+1;
        else return left;
    }
};
