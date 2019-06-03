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
 
ll n,k;
ll pos[100];
ll dp[40][20][20];

ll ways(ll ind,ll o,ll c)
{
    if(ind == (2*n+1) && o == n && c == n)
    return 1;
    if(dp[ind][o][c] != -1)
    return dp[ind][o][c];

    ll v1 = 0,v2 = 0;
    if(pos[ind] == 1)
    return ways(ind+1,o+1,c);//have to place a opening

    if(o > c && c < n && pos[ind] != 1)//place a clossing
    v1 = ways(ind+1,o,c+1);
    if(o < n)
    v2 = ways(ind+1,o+1,c);
    return dp[ind][o][c] = v1 + v2;
}

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<40;i++)
        for(ll j=0;j<20;j++)
        for(ll k=0;k<20;k++)
        dp[i][j][k] = -1;
        cin>>n>>k;
        ll x;
        ll o = 0,c = 0;
        f(0,100)pos[i] = 0;
        f(0,k)
        {
            cin>>x;
            pos[x] = 1;
        }
        ll ans = ways(1,o,c);
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
 
//Porblem Link : https://www.spoj.com/problems/SQRBR/
