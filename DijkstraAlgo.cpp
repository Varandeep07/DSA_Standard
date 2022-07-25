vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // idea: greedy pick the least distance from queue of distances and try to minimize the child's distance from source
    vector<int> ans(V+1,1e9);
    vector<bool> vis(V+1,false);
    ans[S] = 0; vis[S] = true; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
    pq.push({0,S});
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop(); 
        vis[node] = true;
        for(auto &child: adj[node]){
            if(!vis[child[0]]){ 
                if(distance+child[1]<ans[child[0]]){
                    pq.push({distance+child[1],child[0]});
                    ans[child[0]] = distance+child[1]; 
                }
            }
        }
    }
    return ans;
}
