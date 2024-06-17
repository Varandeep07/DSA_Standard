// Let's Code Varan!
// https://leetcode.com/problems/peaks-in-array/
// Writing a segtree class from scratch 

class SegTree{
public:
    int n;
    vector<int> v, Node;

    SegTree(vector<int> vv){
        v = vv;
        n = vv.size(); 
        Node = vector<int>(4*n+10,0);
    }
 
    int Calc(int idx){
        if(idx==0 || idx==n-1) return false;
        return v[idx]>v[idx-1] && v[idx]>v[idx+1];
    }

    void build(int Nid, int l, int r){
        if(l==r){
            Node[Nid] = Calc(l); return;
        }
        int mid = (l+r)/2;
        build(2*Nid,l,mid);
        build(2*Nid+1,mid+1,r);
        Node[Nid] = Node[2*Nid] + Node[2*Nid+1];
    }

    void buildSeg(){
        build(1,0,n-1);
    }

    int query(int nid, int curL, int curR, int ql, int qr){
        if(ql<=curL && qr>=curR){
            return Node[nid];
        }
        if(ql>curR || qr<curL){
            return 0;
        }
        int mid = (curL+curR)/2;
        int count = query(2*nid,curL,mid,ql,qr);
        count += query(2*nid+1,mid+1,curR,ql,qr);
        return count;
    }
    
    // final ans contains boundary elements !
    int CountPeak(int l, int r){
        if(l==r) return 0;
        return query(1,0,n-1,l,r)-Calc(l)-Calc(r);
    }

    void upd(int nid, int val, int curL, int curR, int idx){
        if(curL==curR && curL==idx){
            Node[nid] = val; return;
        }
        if(idx<curL || idx>curR){
            return;
        }
        int mid = (curL+curR)/2;
        upd(2*nid,val,curL,mid,idx);
        upd(2*nid+1,val,mid+1,curR,idx);
        Node[nid] = Node[2*nid] + Node[2*nid+1];
    }

    void update(int idx, int value){
        bool PrevPeak, NowPeak;
        if(idx>0 && idx<n-1){
            PrevPeak = v[idx]>v[idx-1] && v[idx]>v[idx+1];
            NowPeak = value>v[idx-1] && value>v[idx+1];
            if(PrevPeak!=NowPeak){
                upd(1,NowPeak,0,n-1,idx);
            }
        }
        if(idx-2>=0){
            PrevPeak = v[idx-1]>v[idx] && v[idx-1]>v[idx-2];
            NowPeak = v[idx-1]>value && v[idx-1]>v[idx-2];
            if(PrevPeak!=NowPeak){
                upd(1,NowPeak,0,n-1,idx-1);
            }
        }
        if(idx+2<n){
            PrevPeak = v[idx+1]>v[idx] && v[idx+1]>v[idx+2];
            NowPeak = v[idx+1]>value && v[idx+1]>v[idx+2];
            if(PrevPeak!=NowPeak){
                upd(1,NowPeak,0,n-1,idx+1);
            }
        }
        v[idx] = value;
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>>& queries){
        SegTree varan(nums);
        varan.buildSeg();
        vector<int> ans; 
        for(auto &x: queries){
            if(x[0]==1){
                ans.push_back(varan.CountPeak(x[1],x[2]));
            }
            else{
                varan.update(x[1],x[2]);
            }
        }
        return ans; 
    }
};
