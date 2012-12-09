class Solution {
public:
    vector<vector<int> > threeSum(vector<int> arr) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          sort(arr.begin(), arr.end());
    vector <vector<int> > triplets;
    vector<int> triplet(3);
    int n = (int)arr.size();
    for (int i = 0;i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum_two = arr[i] + arr[j];
            if (sum_two + arr[k] < 0) {
                j++;
            } else if (sum_two + arr[k] > 0) {
                k--;
            } else {
                
                triplet[0] = arr[i];
                triplet[1] = arr[j];
                triplet[2] = arr[k];
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
    return triplets;

    }
};