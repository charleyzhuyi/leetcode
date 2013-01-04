class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > triangle;
            if (numRows <=0) return triangle;
        for (int i=0;i<numRows;i++){
            if (triangle.empty()){
                vector<int> t;
                t.push_back(1);
                triangle.push_back(t);
                continue;
            }
            vector<int> tmp = triangle.back();
            int m = tmp.size();
            vector<int> t;
            for (int j=0;j<m;j++){
                if (j == 0)
                    t.push_back(1);
                if (j+1 < m)
                    t.push_back(tmp[j]+tmp[j+1]);
                if (j == m-1)
                    t.push_back(1);
            }
            triangle.push_back(t);
        }
        return triangle;
    }
};
