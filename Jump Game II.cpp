class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = 0;
        int count = 0;
        while (pos < n-1) {
            int range = A[pos];
            int select = pos+1;
            int maxRange = 0;
            for (int i=pos+1;i<=pos+range;i++){
                if (i == n-1) return count+1;
                
                int cRange = A[i]+i;
                if (cRange > maxRange) {
                    maxRange = cRange;
                    select = i;
                }
            }
            pos = select;
            count++;
        }
        return count;
    }
};
