class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<bool>prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int p=2;p*p<=n;++p){
            if(prime[p]){
                for(int i=p*p; i<=n; i+=p) {
                    prime[i]=false;
                }
            }
        }
            vector<int>primes;
            for(int p=2; p<=n; ++p){
                if(prime[p]) primes.push_back(p);
            }
            vector<vector<int>> dp(s+1);
            vector<bool> valid(s+1,false);
            valid[0]=true;
            dp[0]={};
            auto is_better = [](const vector<int>&a, const vector<int>&b){
                if(b.empty()) return true;
                if (a.size() != b.size()) return a.size()<b.size();
                return a<b;
            };
            for (int p:primes){
                for(int sum=s;sum>=p;--sum){
                    if(valid[sum-p]){
                        vector<int>c=dp[sum-p];
                        c.push_back(p);
                        if(!valid[sum] || is_better(c,dp[sum])){
                            dp[sum]=c;
                            valid[sum]=true;
                        }
                    }
                }
            }
            for(int sum=s;sum>=0;--sum){
                if(valid[sum]&&!dp[sum].empty()){
                    return dp[sum];
                }
            }
            return {};
    }
};