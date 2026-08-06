class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> dir_adj(n), undir_adj(n);
        for (const auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            dir_adj[u].push_back(v);
            
            undir_adj[u].push_back(v);
            undir_adj[v].push_back(u);
        }
        int suspicious_count = 0;
        vector<bool> is_suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        is_suspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            suspicious_count++;
            
            for (int neighbor : dir_adj[curr]) {
                if (!is_suspicious[neighbor]) {
                    is_suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        int wcc_count = 0;
        vector<bool> wcc_visited(n, false);
        queue<int> uq;
        
        uq.push(k);
        wcc_visited[k] = true;
        
        while (!uq.empty()) {
            int curr = uq.front();
            uq.pop();
            wcc_count++;
            
            for (int neighbor : undir_adj[curr]) {
                if (!wcc_visited[neighbor]) {
                    wcc_visited[neighbor] = true;
                    uq.push(neighbor);
                }
            }
        }
        vector<int> ans;
        if (suspicious_count != wcc_count) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 0);
        } else {
            for (int i = 0; i < n; i++) {
                if (!is_suspicious[i]) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna