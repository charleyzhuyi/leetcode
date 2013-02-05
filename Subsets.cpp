/* Using recursion */
class Solution {
public:
    vector<vector<int> >result;
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> aSub;
        sort(S.begin(),S.end());
        getsubset(S,aSub,0);
        return result;
    }
    void getsubset(vector<int> &S,vector<int>aSub,int step){
        if (step == S.size()){
            result.push_back(aSub);
            return;
        }
        
        //int not selected
        getsubset(S,aSub,step+1);    
        //int selected
        aSub.push_back(S[step]);
        getsubset(S,aSub,step+1);
    }
};

/* Iteration */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        vector<vector<int> >resultSubsets;
        int n = S.size();
        int max = ( 1 << n);
        
        for (int i=0;i<max;i++){
                
                vector<int> oneSubset;
                int k = i;
                int pos = n-1;
                while ( k > 0) {
                    if ( (k & 1) > 0) {
                        oneSubset.insert(oneSubset.begin(),S[pos]);
                    }
                    pos--;
                    k >>= 1;
                }
                
                resultSubsets.push_back(oneSubset);
        }
        
        return resultSubsets;
    }
};
