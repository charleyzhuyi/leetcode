class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        unordered_map<string, vector<string> > dict; //unordered_map has insert/access of O(1), hashtable
        
        
        for (int i=0;i<strs.size();i++){
          
            
            string sig ( strs[i]);
            //sort string
            sort(sig.begin(),sig.end());
            dict[sig].push_back( strs[i]);
        }
        
        unordered_map<string, vector<string> >::iterator it;
        for ( it = dict.begin(); it != dict.end(); it++){
            
            if (it->second.size() > 1){ //If the vector has more than one value; means it has anagrams
                while (it->second.size() != 0) {
                    string s (it->second.back());
                    it->second.pop_back();
                    result.push_back(s);
                }
            }
            
        }
        
        return result;
        
    }

};
