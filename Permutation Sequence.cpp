class Solution {
public:

    inline int Factorial(int x) {
        if (x == 1 || x == 0)
            return 1;
        else
            return x * Factorial(x - 1);
        
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ps;
        string result;
        for (int i=1;i<=n;i++){
            ps.push_back(i);
        }
        
        for (int i=0;i<n;i++){
            int j = 0;
            int f = Factorial(n-i-1);
            while (j * f < k){
                j++;
            }
            j--;
            
            
            result.append(1,ps[j] + '0');
            ps.erase(ps.begin()+j);
            k = k-j*f;
        }
        
        
        return result;
    }
};


/* recursion solution */
class Solution {
public:
    string result;
    int factorial(int n){
        if (n == 0 || n==1 ) {
            return 1;
        }else {
            return factorial(n-1)*n;
        }
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = "";
        vector<int>num;
        for (int i=1;i<=n;i++){
            num.push_back(i);
        }
        myPermutation(num,k);
        return result;
    }
    
    void myPermutation(vector<int>num,int k){
        int n = num.size();
        if (n == 1) {
            result += (char)(num[0]+'0');
            return;
        }
        int width = factorial(n)/n;
        int nbegin = (k-1)/width;
        result += (char)(num[nbegin]+'0');
        num.erase(num.begin()+nbegin);
        
        int newk = k % width;
        if (newk==0) {
            newk = width;
        }
        
        myPermutation(num,newk);
    }
};
