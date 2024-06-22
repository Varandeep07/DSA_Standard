// Let's Code Varan!
// Z function 
// https://leetcode.com/problems/shortest-palindrome/description/
string shortestPalindrome(string s) {
    int n = s.size();
    string rev = s; reverse(rev.begin(),rev.end());
    string ns = s+"#"+rev; 
    int sz = ns.size();
    int zz[sz];
    memset(zz,0,sizeof(zz));

    int l = 0, r = 0;
    zz[0] = 0;
 
    for(int i=1; i<sz; ++i){
        // i lies in [l,r] range
        if(i<=r){
            int value = zz[i-l];
            zz[i] = value;
             
            if(i+value>r){
                int j = r-i+1;
                l = i;
                while(r+1<sz && ns[j]==ns[r+1]){
                    r++; ++j;
                }
                zz[i] = r-l+1;
            }
        }
        else{
            l = i; r = i;
            int j = 0; 
            while(j<sz && ns[j]==ns[r]){
                ++j; ++r;
            }
            --r;
            zz[i] = r-l+1;
        } 
    }
    int len = 0; 
    for(int i=sz-1; i>=n; --i){
        if(zz[i]==sz-i){
            len = max(len,sz-i);
        }
    }
    
    string shi = s.substr(len,n-len);
    reverse(shi.begin(),shi.end());
    return shi+s;
}
