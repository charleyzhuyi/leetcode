class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string arr[10];
        arr[0] = "";
        arr[1] =  "";
        arr[2] = "abc";
        arr[3] = "def";
        arr[4] = "ghi";
        arr[5] = "jkl";
        arr[6] = "mno";
        arr[7] = "pqrs";
        arr[8] = "tuv";
        arr[9] = "wxyz";
        vector<string> results;
        results.push_back("");
        for (int i=0;i<digits.size();i++) {    
            char digit = digits[i];
            string numStr = arr[digit-'0'];
            vector <string> tmpV;
            for (int j=0;j<results.size();j++) {
                string result = results[j];
                for (int k=0; k<numStr.size();k++) {
                     tmpV.push_back(result + numStr[k]);
                }
            }
            results = tmpV;
        }
        return results;
    }
};
