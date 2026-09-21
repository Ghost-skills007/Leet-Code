class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<c.size();i++)
        {
          adj[c[i][0]].push_back({c[i][1],0});
          adj[c[i][1]].push_back({c[i][0],1});
        }
        int cnt=0;
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]++;
        while(!q.empty())
        {
           int node=q.front();
           q.pop();
           for(auto i:adj[node]){
            if(vis[i.first]==0)
            {
                q.push(i.first);
                vis[i.first]++;
                if(i.second==0)cnt++;
            }
           }
        }
        return cnt;
    }
};