class Solution {
public:
 
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1.empty() || num2.empty()) return "";
        if (num1.size() > num2.size()) return multiply(num2,num1);
        
        
        int n = num1.size();  //Smaller number
        int m = num2.size();  //Larger number
        int c[n+m];
        for (int i=0;i<n+m;i++)
            c[i] = 0;
        
        for (int i=n-1;i>=0;i--){
            int carry = 0;
            for (int j=m-1;j>=0;j--){
                
                int n1 = num1[i]-'0';
                int m1 = num2[j]-'0';
                int r = n1*m1+carry+c[i+j+1];
                c[i+j+1] = r%10;
                carry = r/10;
                
            }
            if ( carry != 0 )
                c[i] = carry;
            
        }
        
        
        string result;
        bool flag = true;
        for (int k = 0;k<n+m;k++){
            if (c[k] == 0) {
                if (flag)
                    continue;
            }else  {
                flag = false;
            }
            char nc = c[k] + '0';
            result = result + nc;
        }
        
        
        return result.empty()?"0":result;
        
        
    }
};
