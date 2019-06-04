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
const ll mod= 11380;
const ll sz = 2e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m = mod) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}

ll a,b,c,d;
ll dp[11][11][11][11][11][11][31];

ll give(ll ao,ll ac,ll bo,ll bc,ll co,ll cc,ll dd)
{
    if(ao == a && bo == b && co == c && ao == ac && bo == bc && co == cc && dd == d)
        return 1;

    if(dp[ao][ac][bo][bc][co][cc][dd] != -1)return dp[ao][ac][bo][bc][co][cc][dd];

    ll ans = 0;
    if(ao == ac && bo == bc && co < c)//place {
    {
        ll cur = co - cc + 1;
        cur = max(cur,dd);
        ans = (ans + give(ao,ac,bo,bc,co+1,cc,cur) )%mod;
    }
    if(ao == ac && bo == bc && co > cc)//place }
    {
        ans = (ans + give(ao,ac,bo,bc,co,cc+1,dd) )%mod;
    }

    if(ao == ac && bo < b)//place [
    {
        ll cur = (co-cc) + (bo - bc) + 1;
        cur = max(cur,dd);
        ans = (ans + give(ao,ac,bo+1,bc,co,cc,cur) )%mod;
    }
    if(ao == ac && bo > bc)//place ]
    {
        ans = (ans + give(ao,ac,bo,bc+1,co,cc,dd) )%mod;
    }

    if(ao < a)//place (
    {
        ll cur = (co-cc) + (bo - bc) + (ao - ac) + 1;
        cur = max(cur,dd);
        ans = (ans + give(ao+1,ac,bo,bc,co,cc,cur) )%mod;
    }
    if(ao > ac)//place )
    {
        ans = (ans + give(ao,ac+1,bo,bc,co,cc,dd) )%mod;
    }

    return dp[ao][ac][bo][bc][co][cc][dd] = ans;
}

void solve()
{
    for(ll t=0;t<10;t++)
    {
        for(ll i=0;i<11;i++)
        for(ll j=0;j<11;j++)
        for(ll k=0;k<11;k++)
        for(ll l=0;l<11;l++)
        for(ll m=0;m<11;m++)
        for(ll n=0;n<11;n++)
        for(ll o=0;o<33;o++)
        dp[i][j][k][l][m][n][o] = -1;

        cin>>c>>b>>a>>d;//a = () , b = [] , c = {} , d = depth
        ll ans = give(0,0,0,0,0,0,0);//ao,ac,bo,bc,co,cc
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
 
//Problem Link : https://www.spoj.com/problems/AEROLITE/
