class Solution {
public:

    int generateGrayCode (unsigned int num) {
        
        return (num >> 1) ^ num;
    }
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        unsigned total = pow(2,n);
        
        for (int i=0;i<total;i++){
            result.push_back(generateGrayCode(i));
        }
        
        return result;
    }
};
