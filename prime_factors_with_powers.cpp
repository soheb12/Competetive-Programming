#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#define f(a,n) for(ll i=a;i<n;i++)
#define watch(x) cout<< (#x) <<" is "<< (x) <<endl;
#define ll long long
#define ii __int128
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define swap(a , b) a^=b;b^=a;a^=b;
#define X first
#define Y second
#define w(t) while(t)
#define cin(n) scanf("%lld",&n)
#define print_cont(c) for(auto &e : c)cout<<e<<" "; cout<<endl;
#define VL vector<ll>
#define PL pair<ll,ll>
#define VP vector< PL >
#define ALL(V) v.begin(),v.end()
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) boost::math::lcm(x,y)
using namespace std;

const ll  max_val = 0x3f3f3f3f; //10619567
const ll maxn = (1e+5);
const ll mod=(1e+9)+7;
const ll size = 1e+5;
 
//end of template

map<int,int> prime_factors(int n)
{
    map<int,int>m;
    for(int i=2;i*i<=n;i++)
    {
        int count=0;
        while(n%i == 0)
        {
            count++;
            n=n/i;
        }
        m[i] = count;

    }
    if(n>2)
    m[n]=1;

    return m;
}


void solve()
{
    int n;
    cin>>n;
    map<int,int>dict = prime_factors(n);
    map<int,int>::iterator it = dict.begin();
    for(;it!=dict.end();it++)
    {
        cout<<(*it).X<<" "<<(*it).Y<<endl;
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
