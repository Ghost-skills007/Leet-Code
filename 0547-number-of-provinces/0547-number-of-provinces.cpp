class Solution {
public:
    vector<int> parent;
    vector<bool> visited;
    int ans=0;
    
    int find(int x){
        return parent[x]==x? x:find(parent[x]);
    }
    
    int findCircleNum(vector<vector<int>>& adjMat) {
        int n=adjMat.size();
        parent=vector<int>(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(adjMat[i][j]==1){
                    int a=find(i);
                    int b=find(j);
                    
                    parent[a]=b;
                }
            }
        }
        visited=vector<bool>(n, false);
        int i=0;
        while(i<n){
            int a=find(i);
            if(!visited[a]){ 
                visited[a]=true;
                ans++;
            }
            i++;
        }
        
        return ans;
    }
};