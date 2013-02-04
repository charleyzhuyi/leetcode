class Solution {
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        restoreIP(s,"",1);
        return result;
    }
    void restoreIP(string s,string t,int step){
        if (step == 5){
            if (s.empty()){
                t.erase(t.size()-1);
                result.push_back(t);
            }
            return;
        }
        
        int n = s.size();
        if (n >= 1){
            int a = atoi(s.substr(0,1).c_str());
            if ( a>=0 && a<=9) restoreIP(s.substr(1),t+s.substr(0,1)+".",step+1);
        }
        if (n >=2){
            int b = atoi(s.substr(0,2).c_str());
            if (b>=10 && b <= 99) restoreIP(s.substr(2),t+s.substr(0,2)+".",step+1);
        }
        if (n>=3){
            int c = atoi(s.substr(0,3).c_str());
            if (c>=100 && c<=255) restoreIP(s.substr(3),t+s.substr(0,3)+".",step+1);
        }
    }
};
