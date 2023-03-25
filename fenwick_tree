class fen_tree{
    //always start indexing from 1 in the case of fenwick trees.
    public:
        int N;
        vector<ll>fen;
        fen_tree(int n){
            N=n;
            fen=vector<ll>(N+1,0);
        }

        void update(int ind,ll x){
            while(ind<=N){
                fen[ind]+=x;
                ind+=(ind & (-ind));
            }
        }

        ll query(int ind){
            ll ans=0;
            while(ind>0){
                ans+=fen[ind];
                ind-=(ind & (-ind));
            }
            return ans;
        }
        
        ll binary_lifting(ll x){
            //for findging the smallest index with sum==x
            ll y=h_pow_2_less_x(N),cur=0,cur_pos=0,ans=0;
            while(y>0){
                if(cur_pos+y<=N && cur+fen[cur_pos+y]<x){
                    cur_pos+=y;ans=cur_pos;
                    cur+=fen[cur_pos];
                }
                y=y>>1;
            }
            return ans+1;
        }
};
