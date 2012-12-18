class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result = "1";
        
        if (n == 1) return result;
        
        for (int i=1;i<n;i++)
            result = sayIt(result);
        
        return result;
    }
    
    string sayIt(string str) {
        
        string result;
        
        for (int i=0;i<str.size();i++) {
            
                
            int count = 1;
            while ( i+1 < str.size() && str[i] == str[i+1]) {
                count++;
                i++;
            }
            
            stringstream convert; // stringstream used for the conversion
             convert << count;
            result = result + convert.str() + str[i];
           
            
            
        }
        
        return result;
    }
    
};
