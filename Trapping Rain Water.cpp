class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //check from left to right
        int con[n]; int upper=0;
        for (int i=0;i<n;i++){
            upper=max(upper,A[i]);
            con[i] = upper;
        }
        //check from right to left
        upper = 0;
        for (int i=n-1;i>=0;i--){
            upper = max(upper,A[i]);
            con[i] = min(con[i],upper);
        }
        //remove no water block and calc sum of water
        int sum = 0;
        for (int i=0;i<n;i++){
            con[i] = con[i] - A[i];
            sum +=con[i];
        }
        return sum;
    }
};
