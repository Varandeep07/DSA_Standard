  bool isCyclic(int V, vector<int> G[]) {
  
  // https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/
  
      // using kahn's algo for topo sort
      // we can obtain topo sort only for DAG
      // so if we can't generate it--> conclude it has a cycle
      vector<int> Indegree(V,0);
      for(int i=0; i<V; i++){
          for(auto &x: G[i]){
              Indegree[x]++;
          }
      }
      queue<int> q;
      vector<int> vis(V,false);
      for(int i=0; i<V; i++){
          if(Indegree[i]==0){
              q.push(i);
          }
      }
      while(!q.empty()){
          int val = q.front();
          q.pop();
          vis[val] = true;
          for(auto &x: G[val]){
              if(vis[x]) continue;
              Indegree[x]--;
              if(!Indegree[x]){
                  q.push(x);

              }
          }
      }
      for(auto &x: vis){
          if(!x){
              return true;
          }
      }
      return false;
  }
