class Solution {

public:

        
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        string romanStr;
        string digits[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        
        romanStr = digits[num%10];
        num = num/10;
        romanStr = tens[num%10] + romanStr;
        num = num/10;
        romanStr =  hundreds[num%10] + romanStr; 
        num = num/10;
        for (int i=0; i<num%10;i++)
            romanStr =  "M" + romanStr;      
        
        return romanStr;
        
    }
};
