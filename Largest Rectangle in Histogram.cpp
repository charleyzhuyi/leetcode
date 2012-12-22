//Time is O(n2), not a best solution, by using two stack, we can get a O(n) 
class Solution {
public:

    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea  = 0 ;
        int width[height.size()];
        
        for (int i=0;i<height.size();i++) {
            width[i] = 1; 
            //go left as far as possible
            int j = i;
            while ( j-1>=0 && height[j-1]>=height[i]) {  
                width[i]++;
                j--;
            }
            //go right as far as poosible
            int k = i;
            while (k+1 <height.size() && height[k+1] >= height[i]) {
                width[i]++;
                k++;
            }
        }
        
        for (int i=0;i<height.size();i++) { 
                int tmpArea = width[i]*height[i];
                if (tmpArea > maxArea)
                    maxArea = tmpArea;  
            }
            
        return maxArea;
        
        
    }
};
