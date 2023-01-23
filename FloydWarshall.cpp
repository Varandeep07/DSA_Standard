void shortest_distance(vector<vector<int>>&matrix){
  // Problem link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
	    int n = matrix.size(); 
	    vector<vector<int>> prev(n,vector<int>(n,1e9));
	    for(int i=0; i<n; ++i){
	        for(int j=0; j<n; ++j){
	            if(i==j){
	                prev[i][j] = 0; 
	            }
	            if(matrix[i][j]!=-1){
	                prev[i][j] = matrix[i][j]; 
	            }
	        }
	    }
	    // k -> intermediate vertex 
	    for(int k=0; k<n; ++k){
	        vector<vector<int>> cur(n,vector<int>(n,1e9)); 
	        for(int i=0; i<n; ++i){
	            for(int j=0; j<n; ++j){
	                if(i==k || j==k){
	                    cur[i][j] = prev[i][j]; 
	                }
	                else{
	                    cur[i][j] = min(prev[i][j],prev[i][k]+prev[k][j]); 
	                }
	            }
	        }
	        prev = cur; 
	    }
	    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
	        matrix[i][j] = (prev[i][j]==1e9?-1:prev[i][j]); 
	    }
	}
