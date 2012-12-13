class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        
        int maxProfit = 0;
        int profit = 0;
      
        
        for (int i=1; i< prices.size(); i++) {
            
          profit += prices[i]-prices[i-1];
          
          if (profit < 0)
            profit = 0;
          
          if (profit > maxProfit)
            maxProfit = profit;
            
            
        }
        
        return maxProfit;
    }
};
