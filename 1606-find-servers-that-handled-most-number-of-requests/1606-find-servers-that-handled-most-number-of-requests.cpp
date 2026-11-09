#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // Min-heap: {free_time, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        vector<int> counts(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            int arr = arrival[i];
            int duration = load[i];
            
            // Free up servers that are done
            while (!busy.empty() && busy.top().first <= arr) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) continue;
            
            // Find server >= i % k
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin(); // Wrap around
            }
            
            int server = *it;
            available.erase(it);
            counts[server]++;
            busy.push({arr + duration, server});
        }
        
        int max_req = *max_element(counts.begin(), counts.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_req) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};