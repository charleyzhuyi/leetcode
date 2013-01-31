class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        int width[n];
        stack<int> st1,st2;
        for (int i=0;i<n;i++){
            while (!st1.empty() && height[st1.top()] >= height[i]) st1.pop();
            width[i] = st1.empty()?i+1:i-st1.top();
            st1.push(i);
        }
        for (int j=n-1;j>=0;j--){
            while (!st2.empty() && height[st2.top()] >= height[j]) st2.pop();
            width[j] += st2.empty()?n-j:st2.top()-j;
            st2.push(j);
        }
        int maxArea = 0;
        for (int k=0;k<n;k++){
            int area = height[k]*(width[k]-1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
