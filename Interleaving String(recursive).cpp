class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s1.empty() && s2.empty() && s3.empty()) return true;
        if (s1.empty() && s2.empty() && !s3.empty()) return false;
       
        if (s1.empty() && !s2.empty()) {
            
            if (s2.compare(s3) == 0)
                return true;
            else
                return false;
        }
        
        if (!s1.empty() && s2.empty()) {
            
            if (s1.compare(s3) == 0)
                return true;
            else
                return false;
        }
        
        char c1 = s1.at(0);
        char    c2 = s2.at(0);  
        char c3 = s3.at(0);
        bool sumResult = false;
  
        if (c1 == c3) 
            sumResult = sumResult || isInterleave(string(s1,1),s2,string(s3,1));
            
        if (c2 == c3) 
             sumResult = sumResult ||  isInterleave(s1,string(s2,1),string(s3,1));

        return sumResult;
        
    }
    
    
    
};
