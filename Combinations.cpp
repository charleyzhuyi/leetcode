class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> aComb;
        comb(n,k,aComb,1);
        return result;
    }
    
    void comb(int n,int k,vector<int> aComb,int step) {
        int length = aComb.size();
        if (length > k) return;
        if (length == k) {
            result.push_back(aComb);
            return;
        }
        
        for (int i=step;i<=n;i++) {
            aComb.push_back(i);
            comb(n,k,aComb,i+1);
            aComb.pop_back();
        }
    }
};
