class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        mygen(n,n,"");
        return result;
    }
    
    void mygen(int left,int right,string str){
        if (left > right) return;
        if (left == 0 ) {
            while (right>0) {
                str += ')';
                right--;
            }
            result.push_back(str);
            return;
        }
        
        if (right>left) {
            mygen(left,right-1,str+')');
        }
        
        mygen(left-1,right,str+'(');
    }
};
