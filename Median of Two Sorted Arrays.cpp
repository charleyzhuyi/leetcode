class Solution {
public:
    float get(int C[],int pos,int size){
        if (pos >= size) return INT_MAX;
        else if (pos < 0) return INT_MIN;
        else return C[pos];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0; int end = m-1;
        int i=0; int j=0;
        int mid = (m+n)/2;
        //search if median number is in array A[]
        while (start <= end) {
            int i= (start+end)/2;
            j = mid - i -1;
            if (get(A,i,m) < get(B,j,n)) {
                //need to look right
                start = i+1;
            } else if (get(A,i,m) > get(B,j+1,n)){
                //need to look left
                end = i-1;
            } else {
                if ((m+n)%2==0) {
                    //even number, median should be average of two middle in combined sorted array
                    int other =get(A,i-1,m)>get(B,j,n)?get(A,i-1,m):get(B,j,n);
                    return (get(A,i,m)+other)*0.5;
                } else {
                    return get(A,i,m);
                }
            }
        }
        //median number not found in array A, need to search it in array B
        return findMedianSortedArrays(B,n,A,m);
    }
};
