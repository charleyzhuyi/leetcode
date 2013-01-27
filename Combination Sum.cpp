using namespace std;

class Solution {
public:
    vector<vector<int> >result;
    int count;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> a;
        sort(candidates.begin(),candidates.end());
        findCombination(candidates,target,a,0);
        return result;
        
    }
    
    void findCombination(vector<int> candidates,int target,vector<int> set,int pos) {
        count++;
        for (int i=pos;i<candidates.size();i++){
            int newTarget = target - candidates[i];
            set.push_back(candidates[i]);
            if (newTarget <0) continue;
            if (newTarget ==0) {
                //Found!
                result.push_back(set);
                continue;
            }
            
            findCombination(candidates,newTarget,set,i);
            set.pop_back();
        }
    }
};
