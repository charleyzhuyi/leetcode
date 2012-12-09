class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(arr.begin(), arr.end());
        vector <vector<int> > triplets;
        vector<int> triplet(4);
        int n = (int)arr.size();
        for (int m = 0; m < n; m++) {
            
            
            for (int i = m+1;i < n; i++) {
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    int sum_three = arr[m] + arr[i] + arr[j];
                    if (sum_three + arr[k] < target) {
                        j++;
                    } else if (sum_three + arr[k] > target) {
                        k--;
                    } else {
                        
                        triplet[0] = arr[m];
                        triplet[1] = arr[i];
                        triplet[2] = arr[j];
                        triplet[3] = arr[k];
                        triplets.push_back(triplet);
                        
                        while( arr[j+1] == arr[j] && j+1 < k)
                            j++;
                        
                        j++;
                        
                        while(arr[k-1] == arr[k] && j < k-1)
                            k--;
                        
                        k--;
                    }
                }
                
                while (i+1 < n && arr[i+1] == arr[i])
                    i++;
            }
            
            while ( m+1 < n && arr[m+1] == arr[m])
                m++;
            
        }
        return triplets;
    }
};