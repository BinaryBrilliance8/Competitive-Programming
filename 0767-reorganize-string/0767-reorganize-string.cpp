class Solution {
public:
    typedef pair<int, char> p;

    string reorganizeString(string s) {

        int n = s.size();

        vector<int> count(26, 0);

        // Count characters
        for (char ch : s) {
            count[ch - 'a']++;

            // Too many of one character → impossible
            if (count[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        // Max heap
        priority_queue<p, vector<p>> pq;

        // Put characters into heap
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] > 0) {
                pq.push({count[ch - 'a'], ch});
            }
        }

        string res = "";

        // Take two most frequent characters
        while (pq.size() >= 2) {

            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            res += p1.second;
            res += p2.second;

            p1.first--;
            p2.first--;

            if (p1.first > 0)
                pq.push(p1);

            if (p2.first > 0)
                pq.push(p2);
        }

        // One character may remain
        if (!pq.empty()) {
            res += pq.top().second;
        }

        return res;
    }
};