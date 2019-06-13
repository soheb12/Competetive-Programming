// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")
 
// -------------------</optimizations>--------------------
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> //lower_bound , upper_bound
using namespace __gnu_pbds;//kth smallest : *pd.find_by_order(k-1) , no. of elem < X : pd.order_of_key(X) , delete X : pd.erase(X).
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define f(a,b) for(ll i=a;i<b;i++)
#define fb(a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define pl pair<ll,ll>
#define all(v) v.begin(),v.end()
const ll mod=(1e+9)+7;
const ll sz = 2e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m = mod) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}
 
void solve()
{
    pbds pd;
    ll q,val;
    char ch;
    cin>>q;
    while(q--)
    {
        ll zz = pd.size();
        cin>>ch>>val;
        if(ch == 'I')//insert val
        {
            pd.insert(val);
        }
        if(ch == 'D')//if val is already in pd then delete val
        {
            pd.erase(val);
        }
        if(ch == 'K')//val th smallest element in pd
        {
            if(val > zz || val == 0)
            cout<<"invalid"<<endl;
            else
            {
                ll ans = *pd.find_by_order(val-1);
                cout<<ans<<endl;
            }
            
        }
        if(ch == 'C')//count of elements smaller than val
        {
            ll ans = pd.order_of_key(val);
            cout<<ans<<endl;
        }
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

//Problem Link : https://www.spoj.com/problems/ORDERSET/

