/* there must be a way to split each string into two part, and each part of both string is continuous with other part. */ 
class Solution {
public:
    bool isContinuedStr(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag= false;
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        if (n <= 2) {
      	return isContinuedStr(s1, s2);
		}
        
        for (int i=1;i<n;i++){
            if ( isContinuedStr(s1.substr(0,i),s2.substr(0,i)) && isContinuedStr(s1.substr(i),s2.substr(i))){
                bool left = isScramble(s1.substr(0,i),s2.substr(0,i));
                bool right = isScramble(s1.substr(i),s2.substr(i));
                if (left && right) return true;
            }
            if ( isContinuedStr(s1.substr(0,i),s2.substr(n-i,i)) && isContinuedStr(s1.substr(i),s2.substr(0,n-i))){
                bool left = isScramble(s1.substr(0,i),s2.substr(n-i,i));
                bool right = isScramble(s1.substr(i),s2.substr(0,n-i));
                if (left && right) return true;
            }
        }
        return false;
    }
};
