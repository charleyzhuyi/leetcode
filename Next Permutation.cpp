class Solution {
public:

    void swap(vector<int> &num,int a,int b) {
        
        num[a] = num[a] ^ num[b];
        num[b] = num[a] ^ num[b];
        num[a] = num[a] ^ num[b];
    }

    void reverse(vector<int> &num,int begin,int end) {
        while (begin < end){
            swap(num,begin,end);
            begin++;
            end--;
        }
    }

    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        for (int i=n-1;i>=1;i--){
            if (num[i]> num[i-1]){
                reverse(num,i,n-1);
                for (int j=i;j<n;j++){
                    if (num[j]>num[i-1]){
                        swap(num,i-1,j);
                        return;
                    }
                }
            }
        }
        reverse(num,0,n-1);
    }
};
