class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxp = 0;
        int trackprofit = 0;
        int mbuy,msell;
        int buyPos = 0;
        int sellPos;
        
        for (int i=1; i< prices.size();i++) {
            trackprofit +=  prices[i] - prices[i-1];
            
            if (trackprofit >=0) {
                
                sellPos = i;
                if (trackprofit > maxp) {
                    maxp = trackprofit;
                    mbuy = buyPos;
                    msell = sellPos;
                }
            }
            
            if (trackprofit <0) {
                
                trackprofit = 0;
                buyPos = i;
            }
            
        }
        if (maxp <=0) return 0;
        
        int tracklost = 0;
        trackprofit = 0;
        int max2lost = 0;
        int max2p = 0;
        
        for ( int i=1; i<prices.size();i++) {
            int diff = prices[i] - prices[i-1];
            if ( i <= mbuy || i > msell) {
                // out of range, check max profit
                 trackprofit += diff;
                if (trackprofit >=0) {
                   
                    if (trackprofit > max2p) {
                        max2p = trackprofit;
                    }
                }
                
                if (trackprofit <0) {
                    trackprofit = 0;
                }
                
            } else {
                //in range, check max lost
                tracklost += diff;
                if (tracklost <=0) {
                    
                    if (max2lost > tracklost) {
                        max2lost = tracklost;
                    }
                    
                } 
                
                if (tracklost >0) {
                    tracklost = 0;
                }
            }
        }
        
        if (-max2lost > max2p) {
            return maxp - max2lost;
        } else {
            return maxp + max2p;
        }
    }
};
