vector<vector<int>> binExp(vector<vector<int>> &t1, int power){
        if(power==1){
            return t1;
        }
        
        vector<vector<int>> temp = binExp(t1,power/2);
        vector<vector<int>> value = multiplyMat(temp,temp);
        if(power%2){
            return multiplyMat(value,t1);
        }
        else{
            return value;
        }
    }

    vector<vector<int>> multiplyMat(vector<vector<int>> &t1, vector<vector<int>> &t2){
        int n = t1.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int val = 0;
                for(int k=0; k<n; ++k){
                    val+=(t1[i][k]*t2[k][j]);
                }
                ans[i][j] = val;
            }
        }
        return ans;
    }

    int fib(int n) {
        vector<vector<int>> mat(2,vector<int>(2,0));
        mat[0][0] = 1; mat[0][1] = 1;
        mat[1][0] = 1; mat[1][1] = 0;
        if(n==0 || n==1) return n;
        vector<vector<int>> T = binExp(mat,n-1);
        return T[0][0]*1+T[0][1]*0;
    }
