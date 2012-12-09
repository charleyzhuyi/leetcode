class Solution {
public:

    int myCompareStr(string a, string b) {
      if (a.size() > b.size())
          return 1;
       else if (a.size() < b.size())
           return -1;
      else {
          return a.compare(b);
      }
    
    }

    string addBinary(string a, string b) {
               // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.size() == 0)
            return b;
        else if (b.size() == 0)
            return a;
        if (a.size() == 1 && a.at(0) == '0') {
            return b;
        }else if (  myCompareStr(a, b) > 0) {
            return addBinary(b, a);
        }
        
        string sumStr;
        string carryStr (1,'0');
        
        int sizeDiff = b.size() - a.size();
        
        for (int i=a.size()-1; i>= 0;i--) {
            
            
            
            if (a.at(i) == '1' && b.at(i+sizeDiff) == '1') {
                // 1 + 1
                sumStr = "0" + sumStr;
                carryStr = "1" + carryStr;
                
            } else if (a.at(i) == '0' && b.at(i+sizeDiff) == '0') {
                // 0 + 0
                sumStr = "0" + sumStr;
                carryStr = "0" + carryStr;
            } else {
                // 1+ 0 or 0 + 1
                sumStr = "1" + sumStr;
                carryStr = "0" + carryStr;
            }
        }
        
        for (int j = sizeDiff-1; j >= 0; j--){
            
            sumStr = b.at(j) + sumStr;
        }
        
        //remove duplicate 0s
        while (sumStr.at(0) == '0' && sumStr.size() > 1) {
            sumStr.erase(0,1);
        }
        while (carryStr.at(0) == '0' && carryStr.size() > 1) {
            carryStr.erase(0,1);
        }
        
        return addBinary(carryStr, sumStr);
        
    }
};