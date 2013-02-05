class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = mySearch(A,n,0,n-1,target,0);
        int right = mySearch(A,n,0,n-1,target,1);
        vector<int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
    
    int mySearch(int A[],int n,int left,int right,int target,bool side){
        if (left > right) return -1;
        if (left == right) {
            if (A[left]==target) return left;
            else return -1;
        }
        int med = (left+right)/2;
        if (A[med] < target) return mySearch(A,n,med+1,right,target,side);
        if (A[med] > target) return mySearch(A,n,left,med-1,target,side);
        //here A[med] == target;
        if (side == false){ //search for left value in range
            if (med==0 || A[med-1] < A[med]){
                return med;
            }else {
                //look for left;
                return mySearch(A,n,left,med-1,target,side);
            }
        } else { //search for right value in the range
            if (med==n-1 || A[med] < A[med+1]){
                return med;
            }else {
                //look for right
                return mySearch(A,n,med+1,right,target,side);
            }
        }
    }
};
