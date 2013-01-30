class Solution {
public:
    bool flag;
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag = false;
        checkInterleavee(s1,s2,s3);
        return flag;
    }
    
    void checkInterleavee(string s1, string s2, string s3) {
         if ( s3.empty()){
            if (s1.empty() && s2.empty()) {
                flag = true;   
                return;
            }
            else return;
        }
        if (s3[0] == s1[0])
            checkInterleavee(s1.substr(1),s2,s3.substr(1));
        if (s3[0] == s2[0])
             checkInterleavee(s1,s2.substr(1),s3.substr(1));
    }
};
