class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int endPos = n-1;
        
        for (int i=n-2;i>=0;i--) {
            
            if (A[i] >= endPos - i) {
                
                endPos = i;
                
            }
            
            
        } 
        
        return endPos == 0; 
         
    }
};
