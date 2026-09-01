class Solution {
public:
    int maxProduct(int n) {
        int x = n, prod = 1;
        int first = 0, second = 0;
        while (x) {
            int ld = x % 10;
            x /= 10;
            if (ld > first) {
                second = first;
                first = ld;
            } else if (ld > second) {
                second =ld;
            }
        }
        return first * second;
    }
};