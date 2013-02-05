class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = x;
        int root;
        while (low <=high){
            int med = low + (high-low)/2;
            if (med > 46340) {       			// 46340^2 ~= INT_MAX
				high = med - 1;
				continue;
			}
            int multi = med*med;
            if (multi == x){
                return med;
            }else if (multi < x){
                low = med+1;
                root= med;
            }else {
                high = med-1;
               
            }
        }
        return root;
    }
};
