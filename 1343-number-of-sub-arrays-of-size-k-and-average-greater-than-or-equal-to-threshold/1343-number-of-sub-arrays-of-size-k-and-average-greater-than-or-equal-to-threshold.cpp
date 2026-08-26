class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0, right = 0, sum = 0, n = arr.size(), cnt= 0;
        while (right < n) {
            sum += arr[right];
            if (right - left + 1 == k) {
                if (sum >= k * threshold) {
                    cnt++;
                }
                sum -= arr[left];
                left++;
            }
            right++;
        }
        return cnt;
    }
};