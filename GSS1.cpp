#include<bits/stdc++.h>
#define f(a,n) for(ll i=a;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define X first
#define Y second
#define w(t) while(t)
#define cin(n) scanf("%lld",&n)
#define VL vector<ll>
#define PL pair<ll,ll>
#define VP vector< PL >
#define ALL(V) v.begin(),v.end()
#define max3(a,b,c) max(a,max(b,c))
 
using namespace std;
const ll  max_val = (1e+15);
const ll mod=(1e+9)+7;
const ll size = 1e+5;
const ll maxn = 5e+5;
const ll min_val = -(1e+15);
//end of template
 
ll a[maxn+5];
struct node
{
    ll sum;
    ll bestpresum;
    ll bestsufsum;
    ll maxsum;
    node()
    {
        sum=bestpresum=bestsufsum=maxsum=0;
    }
    node(ll v)
    {
        sum=bestpresum=bestsufsum=maxsum=v;
    }
    void merge(node l,node r)
    {
        sum=l.sum+r.sum;
        bestpresum=max(l.bestpresum,l.sum+r.bestpresum);
        bestsufsum=max(r.bestsufsum,r.sum+l.bestsufsum);
        maxsum=max3(l.maxsum,r.maxsum,l.bestsufsum+r.bestpresum);
    }
 
}tree[4*maxn];
 
void build(ll cur,ll a_beg,ll a_end)
{
    
    if(a_beg==a_end)
    {
            tree[cur]=node(a[a_beg]);
            return;
    }
 
    else
    {
        ll mid=(a_beg+a_end)/2;
        build(2*cur,a_beg,mid);
        build(2*cur+1,mid+1,a_end);
 
        tree[cur] = node() ; 
        tree[cur].merge( tree[2*cur] , tree[2*cur+1] );
    }
}
 
node query(ll cur,ll a_beg,ll a_end,ll q_beg,ll q_end)
{
 
 
    if(a_beg > q_end || a_end < q_beg)
    {
        node temp(-99999);
        temp.sum=0;
        return temp;
    }
    else if(a_beg>=q_beg && a_end <=q_end)
    return tree[cur];
   
    else
    {
        ll mid=(a_beg+a_end)/2;
        node l,r,ans;
        l = query(2*cur,a_beg,mid,q_beg,q_end);
        r = query(2*cur+1,mid+1,a_end,q_beg,q_end);
        ans = node();
        ans.merge(l,r);
        return ans;
    }
}
 
 
void solve()
{
    ll n;
    cin>>n;
    f(1,n+1)
    cin>>a[i];
    build(1,1,n);
 
    ll q;
    cin>>q;
    ll x,y;
   
    while(q--)
    {
        cin>>x>>y;
        cout<<query(1,1,n,x,y).maxsum<<endl;          
    }
}
 
int main()
{
 
    #ifdef JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
	  cin.tie(NULL);
	  cout.tie(NULL);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
 
} 
