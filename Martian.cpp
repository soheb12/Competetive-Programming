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
const ll sz = 2e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m = mod) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}

ll n,m;
ll dp[502][502];
ll row[502][502];//row prefix sum of y
ll col[502][502];//cpl prefix sum of b
ll y[502][502];
ll b[502][502];

ll give(ll x,ll y)
{
    if(x == 0 || y == 0)
    return 0;
    if(dp[x][y] != -1)
    return dp[x][y];
    return dp[x][y] = max(row[x][y] + give(x-1,y) , col[x][y] + give(x,y-1));
}

void prep()
{
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++)
    dp[i][j] = -1;
}

void solve()
{
    while(1)
    {
        cin>>n>>m;
        if(n == 0 && m == 0)break;
        prep();
        for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        cin>>y[i][j];
        for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        cin>>b[i][j];

        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
            row[i][j] = row[i][j-1] + y[i][j];
            
        for(ll j=1;j<=m;j++)
            for(ll i=1;i<=n;i++)
            col[i][j] = col[i-1][j] + b[i][j];

        ll ans = give(n,m);
        cout<<ans<<endl;
    }
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
 
 Problem link : https://www.spoj.com/problems/MARTIAN/
