class Solution {
public:
    vector<vector<int> > result;
    
    void recursivePermute(vector<int> &num, vector<int> aPermute, int pos, bool used[]){
        
        if (pos == num.size()){    
            result.push_back(aPermute);
            return;
        }
        
        for (int i=0;i<num.size();i++){
            if (used[i] == false){
                used[i] = true;
                aPermute[pos] = num[i];
                recursivePermute(num,aPermute,pos+1,used);
               
                used[i] = false;
            }
        }
        
        
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> aPermute (num.size());
        int pos = 0;
        
        bool used[num.size()];
        for (int i=0;i<num.size();i++)
            used[i] = false;
        
        recursivePermute(num,aPermute,pos,used);
        
        return result;
    }
};

/* Another solution */
class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        permute(num,0);
        return result;
    }
    void permute(vector<int> num,int locPos){
        if (locPos == num.size()-1){
            result.push_back(num);
            return;
        }
        for (int i=locPos;i<num.size();i++){
            swapVector(num,locPos,i);
            permute(num,locPos+1);
            swapVector(num,locPos,i);
        }
    }
    void swapVector(vector<int> &num,int a, int b){
        int tmp = num[a];
        num[a] = num[b];
        num[b] = tmp;
    }
};
