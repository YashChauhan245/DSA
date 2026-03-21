https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


// Math -->o(n)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: sum of array
        long long sum_arr = accumulate(arr.begin(), arr.end(), 0LL);
        
        // Step 2: sum of 1 to n
        long long sum_n = (long long)n * (n + 1) / 2;
        
        // x - y
        long long S = sum_arr - sum_n;
        
        // Step 3: square sum of array
        long long sq_sum_arr = 0;
        for (int x : arr) {
            sq_sum_arr += 1LL * x * x;
        }
        
        // Step 4: square sum of 1 to n
        long long sq_sum_n = (long long)n * (n + 1) * (2*n + 1) / 6;
        
        // x^2 - y^2
        long long P = sq_sum_arr - sq_sum_n;
        
        // x + y
        long long sum_xy = P / S;
        
        // Solve
         /* Calculate X and Y from X + Y and X - Y
         X = ((X + Y) + (X - Y)) / 2
         Y = X - (X - Y)*/
        long long x = (S + sum_xy) / 2;  // repeating
        long long y = sum_xy - x;        // missing
        
        return {(int)x, (int)y};
    }
};



//XOR-->o(n)

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size(); 

        int xr = 0;
        //step-1) basic zor
        for (int i = 0; i < n; i++) {
            // XOR of all elements in nums
            xr = xr ^ arr[i]; 
            
            // XOR of numbers from 1 to n
            xr = xr ^ (i + 1);  
        }

        //step-2)
        // Get the rightmost set bit in xr
        int number = (xr & ~(xr - 1));

        //Group the numbers based on the differentiating bit
        // Number that falls into the 0 group
        int zero = 0; 
        
        // Number that falls into the 1 group
        int one = 0;  

        for (int i = 0; i < n; i++) {
            
            /* Check if nums[i] belongs to the 1 group
            based on the differentiating bit*/
            if ((arr[i] & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ arr[i];
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ arr[i]; 
            }
        }

        // Group numbers from 1 to n based on differentiating bit
        for (int i = 1; i <= n; i++) {
            
            /* Check if i belongs to the 1 group 
            based on the differentiating bit*/
            if ((i & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ i; 
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ i; 
            }
        }

        // Count occurrences of zero in nums
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (arr[i] == zero) {
                cnt++;
            }
        }

        if (cnt == 2) {
            /*zero is the repeating number,
            one is the missing number*/
            return {zero, one}; 
        }
        
        /* one is the repeating number, 
        zero is the missing number*/
        return {one, zero}; 
    }
};
  
