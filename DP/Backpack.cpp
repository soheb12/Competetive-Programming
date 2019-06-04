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

ll tot,n;

vector< pair<ll,ll> >orig;
vector< pair<ll,ll> >att[61];
ll dp[65][32005];
ll o;

ll give(ll ind,ll w)
{
    //cout<<ind<<" "<<w<<" "<<" "<<pro<<endl;
    if(w > tot)return LLONG_MIN;
    if(ind == o)
    {
        if(w > tot)
        return LLONG_MIN;
        else
        return 0;
    }
    if(dp[ind][w] != -1)return dp[ind][w];

    ll ans = 0;
    ans = max(ans,give(ind+1,w));//not taking ind
    ans = max(ans,orig[ind].Y + give(ind+1,w+orig[ind].X));//taking this with no attachments
    if(att[ind].size() == 1)
        ans = max(ans,orig[ind].Y + att[ind][0].Y + give(ind+1,w + orig[ind].X + att[ind][0].X));//taking this
    else if(att[ind].size() == 2)
    {
        ans = max(ans,orig[ind].Y + att[ind][0].Y + give(ind+1,w + orig[ind].X + att[ind][0].X));//taking this with first attachment
        ans = max(ans,orig[ind].Y + att[ind][1].Y + give(ind+1,w + orig[ind].X + att[ind][1].X));//taking this with second attchment
        ans = max(ans,orig[ind].Y + att[ind][0].Y + att[ind][1].Y + give(ind+1,w + orig[ind].X + att[ind][0].X + att[ind][1].X));//taking this with both attachments
    }
    return dp[ind][w] = ans;
}


void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        orig.clear();orig.pb(mp(-1,-1));
        cin>>tot>>n;
        for(ll i=0;i<=n+1;i++)
        for(ll j=0;j<=tot+1;j++)
        dp[i][j] = -1;
        f(0,n+2)
        att[i].clear();

        ll u,v,w;
        vector< pair< pair<ll,ll> , pair<ll,ll> > >inp;//(u,v) , (w,orig_numb)
        inp.pb(mp(mp(0,0),mp(0,0)));
        ll cur = 1;
        f(1,n+1)
        {
            cin>>u>>v>>w;
            if(w == 0)
            {
                inp.pb(mp(mp(u,v),mp(w,cur++)));
            }else
            {
                inp.pb(mp(mp(u,v),mp(w,-1)));
            }
        }
        f(1,n+1)
        {
            ll u = inp[i].X.X;
            ll v = inp[i].X.Y;
            ll w = inp[i].Y.X;
            ll c = inp[i].Y.Y;

            if(w == 0)
            {
                orig.pb(mp(u,u*v));
            }else
            {
                ll oo = inp[w].Y.Y;
                att[oo].pb(mp(u,u*v));
            }
        }

        o = orig.size();
        ll ans = give(1,0);
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
 
//Porblem link : https://www.spoj.com/problems/BACKPACK/
