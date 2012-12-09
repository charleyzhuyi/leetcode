class Solution {
public:
    int threeSumClosest(vector<int> &arr, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         sort(arr.begin(), arr.end());
         vector<int> triplet(3);
         int n = (int)arr.size();
         int diff;
         for (int i = 0;i < n; i++) {
            int j = i + 1;
            int k = n - 1;
             while (j < k) {
                 int sum = arr[i] + arr[j] + arr[k];
              
                 if (abs(target-sum) < abs(diff))
                     diff = target - sum;
              
                 if (sum < target) {
                        j++;
                 } else if (sum > target) {
                      k--;
                 } else {
                return target;
                }
            }
         }
        
    return target-diff;

    }
};