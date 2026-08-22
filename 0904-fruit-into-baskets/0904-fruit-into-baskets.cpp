class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFreq = 0, left = 0, right = 0;
        int n = fruits.size();
        map<int, int> mpp;
        while (right < n) {
            mpp[fruits[right]]++;
            if (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxFreq = max(maxFreq, right - left + 1);
            right++;
        }
        return maxFreq;
    }
};