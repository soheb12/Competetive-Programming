#include<bits/stdc++.h>
#define f(a,n) for(ll i=a;i<n;i++)
#define watch(x) cout<< (#x) <<" is "<< (x) <<endl;
#define ll long long
#define pb push_back
#define mp make_pair
#define swap(a , b) a^=b;b^=a;a^=b;
#define X first
#define Y second
#define w(t) while(t)
#define VL vector<ll>
#define PL pair<ll,ll>
#define VP vector< PL >
#define ALL(V) v.begin(),v.end()
using namespace std;

const ll  INF = 0x3f3f3f3f; //10619567
const ll mod=(1e+9)+7;

//end of template

ll dp[100002];

void preprocess()
{
    ll i,j,k;
    i=j=k=0;
    dp[0]=1;
    
    ll next_2 = dp[i++]*2;
    ll next_3 = dp[j++]*3;
    ll next_5 = dp[k++]*5;
    
    
    for(ll x=1;x<100002;x++)
    {
            ll minv = min(next_2 , min(next_3 , next_5) );
                        dp[x] = minv;
            //cout<<minv<<" "<<next_2<<" "<<next_3<<" "<<next_5<<endl;
            if(minv == next_2)
            {
                i++;
                next_2=dp[i-1]*2;
            }
            if(minv == next_3)
            {
                j++;
                next_3=dp[j-1]*3;
            }
            if(minv == next_5)
            {
                k++;
                next_5=dp[k-1]*5;
            }
            
    }
    
}

void solve()
{
    int t;
    cin>>t;
    preprocess();
    w(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n-1]<<endl;
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
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
 
}
