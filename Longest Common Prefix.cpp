class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string pstr;
        if (strs.empty()) return pstr;
        string compStr = strs.back();
        strs.pop_back();
        bool stop = false;
        for (int i=0;i<compStr.size();i++){
            for (int j=0;j<strs.size();j++){
                string str = strs[j];
                if ( i >= str.size()) {stop = true; break;}
                if (compStr[i] != str[i]){stop = true; break;}
            }
            if (stop) break;
            else pstr = pstr + compStr[i];
        }
        return pstr;
    }
};
