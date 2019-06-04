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
 
ll a[2002],n;
ll dp[2002][2002];
 
ll give(ll i,ll j)
{
    if(i == j)return a[i]*n;
    if(dp[i][j] != 0)return dp[i][j];
 
    ll y = n - (j-i);
    return dp[i][j] = max(a[i]*y + give(i+1,j) , a[j]*y + give(i,j-1));
}
 
void solve()
{
    cin>>n;
    f(1,n+1)
    cin>>a[i];
    ll ans = give(1,n);
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
 
Problem Link : https://www.spoj.com/problems/TRT/
