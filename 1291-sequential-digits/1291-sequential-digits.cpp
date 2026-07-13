class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string res = "123456789";
        int n = res.size();
        vector<int> ans;
        for (int i=2; i<=n; i++) {
            for (int j = 0; j + i <= n; j++) {
                int num = stoi(res.substr(j, i));

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};