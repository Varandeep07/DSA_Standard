	bool isBipartite(int n, vector<int>adj[]){
	    // https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#
	    vector<int> color(n,-1);
	    int col = 0;
	    for(int i=0; i<n; i++){
	        if(color[i]==-1){
	            queue<int> q; q.push(i);
	            color[i] = col;
	            while(!q.empty()){
	                int val = q.front();
	                q.pop();
	                for(auto child: adj[val]){
	                    if(color[child]==-1){
	                        color[child] = 1 xor color[val];
	                        q.push(child);
	                    }
	                    else{
	                        col = 1 xor color[val];
	                        if(color[child]!=col){
	                            return false;
	                        }
	                        color[child] = col;
	                    }
	                }
	            }
	            
	        }
	    }
	    return true;
	}
