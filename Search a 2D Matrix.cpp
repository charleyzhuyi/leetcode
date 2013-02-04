class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        
        //binary search
        int left = 0;
        int right = numRow-1;
        int med;
        while (left <= right){
            med = (left+right)/2;
            if (matrix[med][0] > target){
                //look left
                right = med-1;
            }else if (matrix[med][numCol-1] < target){
                //look right
                left = med+1;
            }else break;
        }
        
        vector<int> poss = matrix[med];
        left = 0;
        right = matrix[med].size()-1;
        while (left <= right) {
            int med = (left+right)/2;
            if (poss[med] == target) return true;
            else if (poss[med] < target){
                left = med+1;
            }else {
                right = med-1;
            }
        }
        return false;
        
    }
};
