    // Function to detect cycle in an undirected graph.
    // https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

    bool checkCycle(int start, vector<bool> &vis, vector<int> adj[]){
        queue<pair<int,int>> que; 
        que.push({start,start});
        vis[start] = true;
        
        while(que.size()){
            int sz = que.size();
            while(sz--){
                pair<int,int> P = que.front(); que.pop();
                for(auto &x: adj[P.first]){
                    if(x==P.second) continue;
                    if(vis[x]){
                        return true;
                    }
                    vis[x] = true;
                    que.push({x,P.first});
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                if(checkCycle(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
