#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // Min-heap to store available servers: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        // Min-heap to store busy servers: {free_time, weight, index}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy_servers;
        
        // Initially, all servers are free
        for (int i = 0; i < servers.size(); ++i) {
            free_servers.push({servers[i], i});
        }
        
        int m = tasks.size();
        vector<int> ans(m);
        long long curr_time = 0;
        
        for (int j = 0; j < m; ++j) {
            // Task 'j' arrives at second 'j'. Fast forward to 'j' if we are behind.
            curr_time = max(curr_time, (long long)j);
            
            // If no servers are available, jump time to when the next server becomes free
            if (free_servers.empty()) {
                curr_time = max(curr_time, get<0>(busy_servers.top()));
            }
            
            // Free the servers that have completed their tasks up to the `curr_time`
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= curr_time) {
                auto [time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, idx});
            }
            
            // Assign the current task to the best available free server
            auto [weight, idx] = free_servers.top();
            free_servers.pop();
            
            ans[j] = idx; // Log the assigned server index
            // Push the server into the busy queue with its new release time
            busy_servers.push({curr_time + tasks[j], weight, idx});
        }
        
        return ans;
    }
};