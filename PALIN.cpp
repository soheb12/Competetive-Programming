#include<bits/stdc++.h>
#define ll long long
#define for(a,n) for(ll i=a;i<n;i++)
 
using namespace std;
 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll i,j;
        ll size = s.size();
        i=0;j=size-1;
 
        int inc=0;
        while(i<=j)
        {
            if(j-i>1)
            {
                if(inc==1 && s[i]==s[j])
                inc=1;
                else if(s[i]>s[j])
                inc=1;
                else
                inc=0;
                s[j]=s[i];
            }//not in centre
            if(j-i==1)
            {
                int x = (int)s[i] - 48;
                int y = (int)s[j] - 48;
 
                if(inc)
                {
                    if(x!=y)
                    {
                        if(x<y)
                        {
                            char c = (char)x + 48 + 1;
                            s[i]=c;
                            s[j]=c; // 2 5 -> 3 3
                        }
                        else
                        {
                            s[j]=s[i]; //3 2 -> 3 3
                        }
                    }
                }//number ahead is greater
                else
                {
                        if(x<=y)
                        {
                            if(x==y && x==9 && y==9)
                            {
                                s[i]='0';
                                s[j]='0';
                                ll ii=i,jj=j;
                                ii--;
                                jj++;
 
                                while(ii>=0 && jj<=size)
                                {
                                    if(s[ii]!='9')
                                    {
                                        s[ii]=s[ii]+1;
                                        s[jj]=s[ii];
                                        break;
                                    }
                                    else
                                    {
                                        s[ii] = '0';
                                        s[jj] = '0';
                                        ii--;
                                        jj++;
                                    }
                                }
                            }else
                            {
                            char c = (char)x + 48 + 1;
                            s[i]=c;
                            s[j]=c; // 2 5 -> 3 3 or 4 4 -> 5 5
                            }
 
                        }
                        else
                        {
                            s[j]=s[i]; //3 2 -> 3 3
                        }
                }//number ahead is smaler or equal
            }//i = j+1
            
            else if(j==i)
            {
                int x = (int)s[i] - 48;
                //cout<<"inc is : "<<inc<<endl;
                if(!inc)
                {
                    if(x < 9)
                    {
                        s[i] = s[i] +1;
                    }
                    else
                    {
                        s[i]='0';
                        ll ii=i,jj=j;
                        ii--;jj++;
                        while(ii>=0 && jj<=size)
                        {
 
                            if(s[ii]!='9')
                            {
                                s[ii] = s[ii]+1;
                                s[jj] = s[ii];
                                break;
                            }
                            else
                            {
                                s[ii]='0';
                                s[jj]='0';
                                ii--;
                                jj++;
                            }
                        }
                    }
                }
            }//i==j
            
            i++;
            j--;
        }//i<=j
 
        if(s[0]=='0')
        {
            s[size-1]='1';
            cout<<1<<s<<endl;
        }
        else
        cout<<s<<endl;
    }
} 
Source code | Plain text | Copy to submit
