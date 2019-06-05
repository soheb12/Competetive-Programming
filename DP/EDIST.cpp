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
 
string a,b;
ll dp[4002][4002];
ll n,m;
 
void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        n = a.size();
        m = b.size();
        a = "*" + a;
        b = "*" + b;
 
        f(1,4002)
        dp[0][i] = i,dp[i][0] = i;
        for(ll i=1;i<=m;i++)//if i had only oi charectors from target string
        {
            for(ll j=1;j<=n;j++)
            {
                if(b[i] == a[j])
                dp[i][j] = dp[i-1][j-1];
                else
                dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
        }
        cout<<dp[m][n]<<endl;
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
  
 //Problem Link : https://www.spoj.com/problems/EDIST/
