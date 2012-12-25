class Solution {
public:
    void resetArr(string T, int table[]){
        for (int i=0;i<256;i++)
            table[i] = 0;       
        for (int i=0;i<T.size();i++) {
            table[T[i]] += 1;
        }
        
      
    }

   string minWindow(string S, string T) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string resultStr;
    int table[256];
    int m = T.size();
    int leftMatchNum = m;
    //reset table to +1 mode
    resetArr(T,table);
    int wTable[256];
    for (int i=0;i<256;i++)
        wTable[i] = 0;  
    int left = -1;
    int right = -1;
    //bool firstSearch = true;
    for (int i=0;i<S.size();i++){
        //if found match   
        //Hit
        if (table[S[i]] > 0) {
            wTable[S[i]]++;   
            if (left == -1) left = i;
            
        }
        if (wTable[S[i]] <=table[S[i]]){
            
            bool done = true;
                    for (int j=0;j<256;j++) {
                        if (table[j] > 0) {
                            if (wTable[j] < table[j]){
                                done = false;
                            }
                        }
                    }
            
            if (done) {
                right = i;
                //purge
                /*
                for (int j=left;j<right;j++){
                    //if Hit
                    if (table[S[j]] > 0) {
                        if (wTable[S[j]] >table[S[j]]){
                            wTable[S[j]]--;
                            left = j+1;
                        }else {
                            break;
                        }
                        
                    }else {
                        left = j+1;
                    }
                }*/
                
                if (resultStr.empty() || right-left+1 < resultStr.size())
                    resultStr = S.substr(left,(right-left+1));

            }
            
            
        }else {
            if (S[i] == S[left]) {
                //found another one, need purge
                right = i;
                
                //purge
                for (int j=left;j<right;j++){
                    
                    //if Hit
                    if (table[S[j]] > 0) {
                        if (wTable[S[j]] >table[S[j]]){
                            wTable[S[j]]--;
                            left = j+1;
                        }else {
                            
                            break;
                        }
                        
                    }else {
                        left = j+1;
                    }
                }
                
                if (right-left+1 < resultStr.size())
                    resultStr = S.substr(left,(right-left+1));
            }
        }
        
        
        
        
        
    }
    
    if (left == -1 || right == -1) return "";
    
    
    return resultStr;
}
};
