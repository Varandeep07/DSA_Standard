// Problem - https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/

void dfs(int node, stack<int> &st, vector<bool> &vis, vector<int> G[], vector<int> &cycle){
        if(cycle.size()) return;
        vis[node] = true; // {0,3}
        st.push(node); // {0,3}
    
        for(auto &x: G[node]){
            if(cycle.size()) return;
           
            if(vis[x]){
                while(st.size() && st.top()!=x){
                    cycle.push_back(st.top());
                    st.pop();
                }
                cycle.push_back(x);
            }
            if(cycle.size()) {
                vis[node] = false; 
                return;
            }
            dfs(x,st,vis,G,cycle);
        }

        if(st.size()) 
            st.pop();
        vis[node] = false;
    }
