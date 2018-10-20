#include<bits/stdc++.h>
#define f(a,n) for(ll i=a;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const ll mod=(1e+9)+7;
const ll size = 1e+5;


ll setbits(ll n) 
{ 
  ll count = 0; 
  while (n) 
  { 
    count += n & 1; 
    n >>= 1; 
  } 
  return count; 
}

ll msb(ll n) 
{ 
    if (n == 0) 
        return 0; 
  
    ll m = 0; 
    while (n != 0) { 
        n = n / 2; 
        m++; 
    } 
  
    return m; 
} 

ll* decToBinary(ll n,ll x) 
{ 
    ll *binaryNum = new ll[x]; 
    f(0,x)
    binaryNum[i] = -1;
  
    ll i = 0; 
    while (n > 0) { 
          binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
      for (ll j = x-1; j >= 0; j--) 
      {
          if(binaryNum[j] == -1)
          binaryNum[j] = 0;
      }
      ll *temp = new ll[x];
      for(ll k=0;k<x;k++)
      temp[k] = binaryNum[x-k-1];
      return temp;
} 

ll dp[31][31][31][31][31][2];

ll find(ll w,ll x,ll y,ll z,ll ind,ll c,ll *a)
{
    if(w == -1 || x == -1 || y == -1 || z == -1)
    return 0;
    if( (w>0 || y>0 || x>0 || z>0) && ind == -1)
    return 0;
    //     cout<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<ind<<" "<<c<<endl;
    // cout<<a[ind]<<endl;
    if(w == 0 && x ==0 && y == 0 && z == 0 && ind == -1 && c == 0)
    return 1;
    if(a[ind] == 0)
    {
        if(c == 0)
        {
            return find(w-1,x,y,z,ind-1,0,a) + find(w,x,y,z-1,ind-1,1,a);
        }
        else//c==1
        {
            return find(w,x-1,y,z,ind-1,1,a) + find(w,x,y-1,z,ind-1,1,a);
        }
    }
    else//a[i] == 1
    {
        if(c == 0)
        {
            return find(w,x-1,y,z,ind-1,0,a) + find(w,x,y-1,z,ind-1,0,a);
        }
        else//c==1
        {
            return find(w-1,x,y,z,ind-1,0,a) + find(w,x,y,z-1,ind-1,1,a);
        }
    }
}

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=30;i++)
        {
            for(int j=0;j<=30;j++)
            {
                for(int k=0;k<=30;k++)
                {
                    for(int l=0;l<=30;l++)
                    {
                        for(int m=0;m<=30;m++)
                        {
                                for(int n=0;n<2;n++)
                                dp[i][j][k][l][m][n] = -1;
                        }
                    }
                }
            }
        }

        ll a,b,c;
        cin>>a>>b>>c;
        ll msb_a = msb(a);
        ll msb_b = msb(b);
        ll ones_a = setbits(a);
        ll ones_b = setbits(b);
        ll a_min=pow(2,ones_a)-1,b_min=pow(2,ones_b)-1,a_max=0,b_max=0;
        for(int i=msb_a-1;i>=msb_a-ones_a;i--)
        a_max += pow(2,i);
        for(int i=msb_b-1;i>=msb_b-ones_b;i--)
        b_max += pow(2,i);
        //cout<<a_min<<" "<<a_max<<" "<<b_min<<" "<<b_max<<endl;
        ll s = c - b_max;
        ll e = min(a_max , c - b_min);
        //cout<<s<<" "<<e<<endl;
        ll tot = max(msb_a,max(msb_b,msb(c)));
        //decToBinary(a,tot);cout<<endl;decToBinary(b,tot);cout<<endl;decToBinary(c,tot);cout<<endl<<endl;
        ll *aa = new ll[tot];
        ll *bb = new ll[tot];
        ll *cc = new ll[tot];
        aa = decToBinary(a,tot);
        bb = decToBinary(b,tot);
        cc = decToBinary(c,tot);
        ll w=0,x=0,y=0,z=0;
        f(0,tot)
        {
            if(aa[i] == 0 && bb[i] == 0)
            w++;
            else if(aa[i] == 0 && bb[i] == 1)
            x++;
            else if(aa[i] == 1 && bb[i] == 0)
            y++;
            else if(aa[i] == 1 && bb[i] == 1)
            z++;
        }
        // f(0,tot)
        // cout<<aa[i]<<" ";
        // cout<<endl;
        // f(0,tot)
        // cout<<bb[i]<<" ";
        // cout<<endl;
        // f(0,tot)
        // cout<<cc[i]<<" ";
        // cout<<endl;
        ll ans = 0;
        ll ww = w,xx = x,yy = y,zz = z;
        while(x>=0 && y>=0)
        {
            if(y+z > ones_a)
            break;
            if(x+z > ones_b)
            break;
            //cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
            ans += find(w,x,y,z,tot-1,0,cc);
            x--;y--;w++;z++;
        }
        w = ww,x = xx;y = yy;z = zz;
        w--;z--;x++;y++;
        while(w>=0 && z>=0)
        {
            if(y+z > ones_a)
            break;
            if(x+z > ones_b)
            break;
            ans += find(w,x,y,z,tot-1,0,cc);
            w--;z--;x++;y++;
        }
        cout<<ans<<endl;
        return;


        // cout<<"-------"<<endl;
        // ll ans = 0;
        // f(a_min,c-b_min+1)
        // {
        //     if(dp[i] == ones_a && dp[c-i] == ones_b)
        //     {ans++;
        //     decToBinary(i,tot);cout<<endl;decToBinary(c-i,tot);cout<<endl<<endl;;
        //     }
        // }
        // cout<<ans<<endl;

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

//https://www.codechef.com/SNCK1A19/problems/CHEFADD
