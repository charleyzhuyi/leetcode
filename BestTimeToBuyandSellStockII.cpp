class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        
        
        int maxProfitValue = 0;
        int profit = 0;
        
        for (int i=1;i<prices.size();i++){
            
            int diff = prices[i]-prices[i-1];
            if ( diff >= 0)
                profit += diff;
            else {
                maxProfitValue += profit;
                profit = 0;
            }

        }
        
        if (profit > 0)
            maxProfitValue += profit;
     
        return maxProfitValue;
    }
};
