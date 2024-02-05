class disjoint_set{
    public:
        int n;
        vector<int>parent;
        vector<int>s;

        // this initializes initial parents to itself and sizes to 1.
        disjoint_set(int n){
            this->n=n;
            parent.resize(n+1);
            s=vector<int>(n+1,1);
            for(int i=1;i<=n;i++)       parent[i]=i;
        }

        int get(int x){
            return (parent[x]==x ? x : parent[x]=get(parent[x]));
        }

        //call this function to join group x and group y
        void join(int x,int y){
            x=get(x);y=get(y);
            if(s[x]>=s[y] && x!=y){
                parent[y]=x;s[x]+=s[y];
            }
            else if(x!=y){
                parent[x]=y;s[y]+=s[x];
            }
        }
};
