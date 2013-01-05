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
