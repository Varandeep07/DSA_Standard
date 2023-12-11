https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size(); 
	    for(int k=0; k<n; ++k){
	        for(int i=0; i<n; ++i){
	            for(int j=0; j<n; ++j){
	                if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
	                int dist = matrix[i][k] + matrix[k][j];
	                if(matrix[i][j]==-1){
	                    matrix[i][j] = dist;
	                }
	                else{
	                    matrix[i][j] = min(matrix[i][j],dist);
	                }
	            }
	        }
	    }
	}
