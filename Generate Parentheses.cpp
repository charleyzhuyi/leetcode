class Solution {
public:

    vector<string> result;
    
    void recursiveParenthesis(int numLeft, int numRight,string str) {
        
        if (numLeft == 0 && numRight == 0) return;
        if (numLeft == 0 && numRight > 0) {
            
            string newStr (str);
            for (int i=0;i<numRight;i++) {
                newStr = newStr + ')';
            }
            
            result.push_back(newStr);
            
            return;
        }
        if (numLeft > 0 && numRight == 0) {
            cout << "ERROR";
            return;
        }
        
        
        recursiveParenthesis(numLeft-1,numRight,str + '(');
        
        if (numRight > numLeft) 
            recursiveParenthesis(numLeft,numRight-1, str + ')');
        
        
        
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
         
        if ( n < 1) 
            return result;
        
       
        string mystring;
        
        result.clear();
        recursiveParenthesis(n,n,mystring);
        
        return result;
    }
};
