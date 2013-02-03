class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = rowIndex;
        vector<int> row(n+1);
        for (int i=0;i<=n;i++){
            if (i==0){
                row[0] = 1;
                continue;
            }
            for (int j=i;j>=0;j--){
                if (j==i) row[j]=1;
                else if (j==0) row[j]=1;
                else row[j] = row[j-1]+row[j];
            }  
        }
        return row;
    }
};
