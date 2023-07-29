// Function to detect cycle in a directed graph
    // https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    bool checkCycle(int i, vector<int> G[], vector<int> &colors){
        colors[i] = 1;
       
        for(auto &x: G[i]){
            if(colors[x]==0){
                if(checkCycle(x,G,colors)){
                    return true;
                }
            }
            else if(colors[x]==1){
                return true;
            }
        }
        
        colors[i] = 2;
        return false;
    }
    
    bool isCyclic(int V, vector<int> G[]) {
        vector<int> colors(V,0);
        
        for(int i=0; i<V; ++i){
            if(colors[i]==0 && checkCycle(i,G,colors)){
                return true;
            }
        }
        return false;
    }
