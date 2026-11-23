class ProductOfNumbers {
private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset prefix products; any future query spanning this 0 will return 0
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        // If k reaches back to or past the last 0, the product is 0
        if (k >= n) {
            return 0;
        }
        return prefix.back() / prefix[n - 1 - k];
    }
};