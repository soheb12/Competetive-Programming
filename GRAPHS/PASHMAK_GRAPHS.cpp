//LIS Path in a graph

// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")

// -------------------</optimizations>--------------------
#include<bits/stdc++.h>
#define f(a,b) for(ll i=a;i<b;i++)
#define fb(a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define pl pair<ll,ll>
#define all(v) v.begin(),v.end()
using namespace std;
const ll mod=(1e+9)+7;
const ll sz = 3e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m = mod) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}

vector< pair<ll,ll> >adj[sz];
ll dp[sz];
ll temp[sz];//to take care of same edges and process all same edges only once
vector< pair<ll , pl > >edges;

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll u,v,w;
    f(0,m)
    {
        cin>>u>>v>>w;
        edges.pb(mp(w,mp(u,v)));
    }
    sort(all(edges));
    f(0,m)
    {
        ll j = i;
        while(edges[j].X == edges[i].X && j < m)
        j++;
        //Now all edges with same weight are from i to j
        
        vector<ll>vec;
        for(ll k=i;k<j;k++)
        {
            ll u = edges[k].Y.X, v = edges[k].Y.Y;
            temp[v] = max(dp[u]+1,temp[v]);//temp also stores dp values and only edges of lesser weight can be considered for this vertex v
            vec.pb(v);
        }

        for(ll vv : vec)
        dp[vv] = max(dp[vv],temp[vv]);

        i = j-1;
    }

    ll ans = *max_element(dp,dp+n+1);
    cout<<ans<<endl;
}
 
int main()
{
    #ifdef JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec, Copyright %c 2019 Skyscraper. \n", double(end - beg) / CLOCKS_PER_SEC , 184);
    return 0;
}

//Problem link : https://codeforces.com/contest/459/problem/E
//Solved this Problem : https://www.codechef.com/status/DINCPATH,lmao_

