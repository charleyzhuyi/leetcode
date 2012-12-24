class Solution {
public:

    //classical O(n) solution
     int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i=0;i<n;i++) {
            sum += A[i];
            
            if (sum > maxSum)
                maxSum = sum;
                
            if (sum < 0)
                sum = 0;
            
        }
        return maxSum;
        
    }
}

class Solution {
public:
    //another O(n) soluton
     int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==1) return A[n-1];

        int maxSum = INT_MIN;
        int begin = A[0];
        for (int i=1;i<n;i++) {
            
            if (begin>maxSum)
                maxSum = begin;
            
            int combine = begin+A[i];
            if (combine > A[i]) {
                begin = combine;
                if (combine > maxSum)
                    maxSum = combine;
                
            }else {
                begin = A[i];
                if (A[i] > maxSum)
                    maxSum = A[i];
            }

        }
        
        return maxSum;
    }
};

//Divide and conquer solution, time complexity is O(nlgn)
class Solution {
public:
    int getCrossMedianMax( int A[],int n,int left,int right,int median) {
        
        int leftsum = INT_MIN;
        
        int sum = 0;
        for (int i=median;i>=left;i--) {
            sum += A[i];
            if (sum > leftsum)
                leftsum = sum;
        }
        
        int rightsum = INT_MIN;
        sum = 0;
        for (int i=median+1;i<=right;i++) {
            sum += A[i];
            if (sum > rightsum)
                rightsum = sum;
        }
        
        return leftsum+rightsum;
    }
    //Divide and conquer, 
    int getMaxArray(int A[],int n,int left,int right) {
        
        if (left > right) return 0;
        if (left == right) return A[left];
        
        int median = (left+right)/2;
        
        int left_max = getMaxArray(A,n,left,median);
        int right_max = getMaxArray(A,n,median+1,right);
        
        int cross_median = getCrossMedianMax(A,n,left,right,median);
        
        if (cross_median > max(left_max,right_max))
            return cross_median;
        else
            return max(left_max,right_max);
        
        
    }
    
    
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return getMaxArray(A,n,0,n-1);
    }
};
