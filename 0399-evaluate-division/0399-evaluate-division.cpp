class DSU {
public:
    vector<double> ratio, par;
    DSU(int n) {
        ratio.resize(n + 1);
        par.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            ratio[i] = 1.0;
        }
    }

    int findUPar(int node) {
        if (par[node] == node)
            return node;
        int root = findUPar(par[node]);
        ratio[node] *= ratio[par[node]];
        par[node] = root;
        return root;
    }

    void unionDSU(int u, int v, double val) {
        int rootU = findUPar(u);
        int rootV = findUPar(v);
        if (rootU == rootV)
            return;
        par[rootU] = rootV;
        ratio[rootU] = ratio[v] / ratio[u] * val;
    }
    
    double query(int u, int v){
        int rootU = findUPar(u);
        int rootV = findUPar(v);
        if(rootU != rootV) return -1.0;
        return ratio[u] / ratio[v];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, int> mp;
        int id = 0;
        for (auto& eq : equations) {
            if (mp.find(eq[0]) == mp.end())
                mp[eq[0]] = id++;
            if (mp.find(eq[1]) == mp.end())
                mp[eq[1]] = id++;
        }
        DSU dsu(id);
        int n = values.size();
        for (int i = 0; i < n; i++) {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            dsu.unionDSU(u, v, values[i]);
        }
        int m = queries.size();
        vector<double> ans(m, -1);
        for (int k = 0; k < m; k++) {
            string src = queries[k][0];
            string des = queries[k][1];
            if (mp.find(src) == mp.end() || mp.find(des) == mp.end())
                continue;
            ans[k] = dsu.query(mp[src], mp[des]);
        }
        return ans;
    }
};