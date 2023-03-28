class ancestors{
    public:
        int N,l,i,j;
        vector<vector<int>>up;
        map<int,vector<int>>adj;
        vector<int>deapth;
        vector<bool>vis;
 
        //initialization
        ancestors(int n){
            N=n+10;
            l=log2(N);
            up=vector<vector<int>>(N,vector<int>(l+1,0));
            vis=vector<bool>(N,false);
            deapth=vector<int>(N,0);
        }
 
        //running dfs to assign initial parents and deapths
        void dfs(int x,int d){
            deapth[x]=d;
            for(auto it : adj[x]){
                if(!vis[it]){
                    vis[it]=true;
                    up[it][0]=x;
                    dfs(it,d+1);
                }
            }
        }
 
        //assigning kth parents where k is power of 2 ( similar to that of sparse table)
        void make(){
            for(j=1;j<=l;j++){
                for(i=0;i<N;i++)        up[i][j]=up[up[i][j-1]][j-1];
            }
        }
 
        //to find kth ancestor of a particular node
        int kth_ancestor(int x,int k){
            j=0;
            while(k>0){
                if(k&1)     x=up[x][j];
                j++;k=k>>1;
            }
            return x;
        }
 
        //to find lowest common ancestor of two nodes
        int lca(int x,int y){
            int k,ans;
            if(deapth[x]>deapth[y]){
                k=deapth[x]-deapth[y];
                x=kth_ancestor(x,k);
            }
            else if(deapth[y]>deapth[x]){
                k=deapth[y]-deapth[x];
                y=kth_ancestor(y,k);
            }
            if(x==y)        return x;
            else{
                j=l;
                while(j>=0){
                    if(up[x][j]==up[y][j])        ans=up[x][j];
                    else{
                        x=up[x][j];y=up[y][j];
                    }
                    j--;
                }
            }
            return ans;
        }
};
