//Solved Using Partial Sums

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

ll dp[11][101][101];

void solve()
{
    ll n,q,c;
    cin>>n>>q>>c;
    ll x,y,si;
    f(0,n)
    cin>>x>>y>>si,dp[si][x][y]++;

    for(ll p=0;p<=c;p++)
    {
        for(ll i=1;i<=100;i++)
        for(ll j=1;j<=100;j++)
        dp[p][i][j] += dp[p][i-1][j] + dp[p][i][j-1] - dp[p][i-1][j-1];
    }

    ll t,x1,y1,x2,y2;
    while(q--)
    {
        cin>>t>>x1>>y1>>x2>>y2;
        ll ans = 0;
        for(ll p=0;p<=c;p++)
        {
            ll brightness = (p+t)%(c+1);//for one star with initial brighness p at moment t this the brightnes
            ll stars = dp[p][x2][y2] - dp[p][x1-1][y2] - dp[p][x2][y1-1] + dp[p][x1 - 1][y1 - 1];//from range x1-1,y1-1 we subtracted twice
            ans += stars*brightness;
        }
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
 
// Problem Link : https://codeforces.com/contest/835/problem/C
