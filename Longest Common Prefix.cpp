class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        if (strs.empty()) return result;
        
        result = strs.front();
        

        for (int i=1;i<strs.size();i++){
            
            string readStr = strs[i];
            
            for (int j=0;j<result.size();j++) {
                
                char readChar;
                if ( j >= readStr.size())
                    readChar = ' ';
                else
                    readChar = readStr[j];
                    
                if (result[j] != readStr[j]) {
                    result = result.substr(0,j);
                }  
                
            }
            
        }
        return result;
    }
};
