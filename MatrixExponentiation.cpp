#define int long long
vector<vector<int>> multiplyMat(vector<vector<int>> &t1, vector<vector<int>> &t2){
    int r1 = t1.size(), r2 = t2.size(), c1 = t1[0].size(), c2 = t2[0].size();
    vector<vector<int>> ans(r1,vector<int>(c2,0));
    for(int i=0; i<r1; ++i){
        for(int j=0; j<c2; ++j){
            int val = 0;
            for(int k=0; k<c1; ++k){
                val = add(val,mul(t1[i][k],t2[k][j]));
            }
            ans[i][j] = val;
        }
    }
    return ans;
}

vector<vector<int>> binExp(vector<vector<int>> &t1, int power){
    if(power==1){
        return t1;
    }
    if(power==0){
        int m = t1[0].size();
        vector<vector<int>> I(m,vector<int>(m,0));
        f(i,0,m) I[i][i] = 1;
        return I;
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

int fib(int n) {
        vector<vector<int>> mat(2,vector<int>(2,0));
        mat[0][0] = 1; mat[0][1] = 1;
        mat[1][0] = 1; mat[1][1] = 0;
        if(n==0 || n==1) return n;
        vector<vector<int>> T = binExp(mat,n-1);
        return T[0][0]*1+T[0][1]*0;
}
