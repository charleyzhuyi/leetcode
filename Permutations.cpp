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