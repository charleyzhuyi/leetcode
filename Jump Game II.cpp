class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int curPos = 0;
        if (n==1) return 0;
        
        int numStep = 0;
        //when the last step can not reach to the end
        while (A[curPos] < n-1 - curPos) {
            
            
            int maxRange = curPos + A[curPos];
            int maxFrom = curPos;
            
            for (int i=1;i<=A[curPos];i++) {
                
                
                int aMaxRange = curPos + i+A[curPos+i];
                if (aMaxRange > maxRange) {
                    maxRange = aMaxRange;
                    maxFrom = curPos + i;
                }
                
            }
            
            curPos = maxFrom;
            numStep++;
            
            
        }
        
        return numStep+1;
        
        
    }
};
