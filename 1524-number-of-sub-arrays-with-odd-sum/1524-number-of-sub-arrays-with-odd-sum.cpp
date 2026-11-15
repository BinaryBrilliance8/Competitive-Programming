class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even_count = 1; // Base case: prefix sum of 0 before starting is even
        int odd_count = 0;
        int parity = 0;
        int result = 0;
        int mod = 1e9 + 7;
        
        for (int num : arr) {
            // Update the parity of the current prefix sum
            parity = (parity + num) % 2;
            
            if (parity == 0) {
                // Current prefix sum is even. We can form an odd subarray 
                // by subtracting any previous odd prefix sum.
                result = (result + odd_count) % mod;
                even_count++;
            } else {
                // Current prefix sum is odd. We can form an odd subarray
                // by subtracting any previous even prefix sum.
                result = (result + even_count) % mod;
                odd_count++;
            }
        }
        
        return result;
    }
};