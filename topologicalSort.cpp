vector<int> topoSort(int n, vector<int> adj[]) 
{
    // https://practice.geeksforgeeks.org/problems/topological-sort/1#

    vector<int> Indegree(n,0);
    for(int i=0; i<n; i++){
	for(auto &x: adj[i]){
	    Indegree[x]++;
	}
    }
    queue<int> q; // find node with indegree 0 and push in the queue 
    vector<int> topo_list; // after pop out reduce its child's indegree by 1 
    for(int i=0; i<n; i++){ // also find the child with indegree 0 and push in the queue
	if(!Indegree[i]){
	    q.push(i);
	}
    }
    vector<bool> vis(n,false);
    while(!q.empty()){
	int val = q.front();
	q.pop();
	vis[val] = true;
	topo_list.push_back(val);
	for(auto &x: adj[val]){
	    if(vis[x]) continue;
	    Indegree[x]--;
	    if(!Indegree[x]){
		q.push(x);
	    }
	}
    }
    return topo_list;
}
