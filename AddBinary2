class Solution {
public:
    int bitAtIndex(string s,int i){
        
        if (i >= s.size())
            return 0;
        else if ( s.at(i) == '0')
            return 0;
        else
            return 1;
    }

    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (a.size() == 0 && b.size() == 0)
            return "0";
        else if (a.size() == 0)
            return b;
        else if (b.size() == 0)
            return a;
        
        
        int carry = 0;
        string sumStr;
        
        for (int i=0; i<max(a.size(),b.size());i++) {
            
            int ai = bitAtIndex(a, a.size()-1-i);
            int bi = bitAtIndex(b, b.size()-1-i);
            
            int tmpSum = ai ^ bi ^ carry;
            carry = (ai + bi + carry) /2;
            
            ostringstream oss;
            oss << tmpSum;
            
            
            sumStr = oss.str() + sumStr;

        }
        
        if (carry == 1){
            sumStr = "1" + sumStr;
        }
        
        return sumStr;

    }
};