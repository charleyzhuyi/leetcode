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
                
                aPermute.push_back(num[i]);
                recursivePermute(num,aPermute,pos+1,used);
                aPermute.pop_back();
                used[i] = false;
                
                while (i+1 < num.size() && num[i+1] == num[i])
                    i++;
                    
                
            }
        }   
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> aPermute;
        int pos = 0;
        
        bool used[num.size()];
        for (int i=0;i<num.size();i++)
            used[i] = false;
        
        sort(num.begin(),num.end());
        recursivePermute(num,aPermute,pos,used);
        
        return result;
    }
};
