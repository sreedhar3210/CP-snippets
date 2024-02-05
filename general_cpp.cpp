#include<bits/stdc++.h>
using namespace std;

//<------------------------------------------------Definations---------------------------------------------------->

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

//<------------------------------------------------Definations---------------------------------------------------->

//<------------------------------------------------Constants---------------------------------------------------->

const int N=2e5+10;
const ll MOD=1e9+7,INF=2e18;
const double pi = 3.14159265358979323846264338327950;

//<------------------------------------------------Constants---------------------------------------------------->

//<---------------------------------------------useful functions------------------------------------------------>

bool is_square(ll x){ll y=sqrt(x);   return (x==(y*y));}
ll lcm(ll x,ll y){return  ((x/__gcd(x,y))*y);}
ll ceil_div(ll x,ll y){return ((x/y)+((x%y)!=0));}      //returns ceil(x/y);
ll fast_pow(ll b, ll p) {
    if(p == 0) return 1;
    if(p == 1) return (b%MOD);
    ll r = fast_pow(b, p / 2);
    if(p % 2) return ((((r*r)%MOD)*(b%MOD)) % MOD);
    else return ((r*r) % MOD);
}
ll inv_mod(ll x){return fast_pow(x,MOD-2);}
bool is_regular(string s){                              //checks if the given bracket sequence is regular
    int res=0;
    for(auto it : s){
        res+=(it=='(' ? 1 : -1);
        if(res<0)       return false;
    }
    return res==0;
}
string num_to_bin_str(ll x,int len){
    string ans="";
    while(x>0){
        ans.push_back(x&1 ? '1' : '0');
        x>>=1;
    }
    while(ans.size()<len)       ans.push_back('0');
    reverse(ans.begin(),ans.end());
    return ans;
}
bool is_add_overflow(ll x, ll y){return ((INF-y) < x);}
bool is_mul_overflow(ll x, ll y){return ((INF/y) < x);}
//<---------------------------------------------useful functions------------------------------------------------>

void run_case(){
    
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)      run_case();
    return 0;
}
