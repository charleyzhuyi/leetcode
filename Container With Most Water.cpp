class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() < 2) return 0;
        
        int left = 0;
        int right = height.size() -1;
        
        int globalMax = 0;
        
        
        while ( left < right ) {
            
            int area = (right-left)*min(height[right],height[left]);
            
            if (area > globalMax)
                globalMax = area;
            
            if (height[left] > height[right]) {
                right--;
            }else {
                left++;
            }
            
        }
        
        
        return globalMax;
    }
};
