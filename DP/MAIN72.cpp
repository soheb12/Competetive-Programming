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
 
ll n,a[102];
 
void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum = 0;
        f(1,n+1)
        cin>>a[i],sum += a[i];
 
        ll dp[n+1][sum+1];
        f(0,n+1)
        dp[i][0] = 1;
        f(1,sum+1)
        dp[0][i] = 0;
 
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=sum;j++)
            {    
                if(j >= a[i])
                    dp[i][j] = dp[i-1][j-a[i]] ||  dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
 
 
        set<ll>s;
        f(1,sum+1)
        if(dp[n][i])
        s.insert(i);
 
        ll ans = accumulate(all(s),0);
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

// Problem Link : https://www.spoj.com/problems/MAIN72/
