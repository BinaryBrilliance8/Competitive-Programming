class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long tot = 0;
        for (int val:nums) tot+=val;
        long long window = 0;
        int n= nums.size();
        int half = n/2;
        for (int i=0; i<half;i++) {
            window+=nums[i];
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            if (2*window>tot) res++;
            window -= nums[i];
            window += (nums[(i + half) % n]);
        }
        return res;
    }
};