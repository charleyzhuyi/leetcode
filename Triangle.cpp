/* Bottom Up approach, space O(n), time O(n) */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector<int> lastminv (triangle[n-1]);
        
        for (int k=n-2;k>=0;k--){
            
            int m = triangle[k].size();
            vector<int> tmpv (m);
            
            for (int i=0;i<m;i++){
                tmpv[i] = min(lastminv[i],lastminv[i+1]);
            }
            
            lastminv.clear();
            for (int i=0;i<m;i++){
                lastminv[i] = tmpv[i] + triangle[k][i];
            }
        }
        return lastminv[0];
    }
};
