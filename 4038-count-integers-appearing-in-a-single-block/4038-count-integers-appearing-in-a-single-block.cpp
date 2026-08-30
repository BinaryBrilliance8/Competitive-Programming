class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int arr[101] = {0};
        arr[nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                arr[nums[i]]++;
            }
        }
        int ans = 0;
        for (int i=0; i<101; i++) {
            if (arr[i] == 1) {
                ans++;
            }
        }
        return ans;
    }
};