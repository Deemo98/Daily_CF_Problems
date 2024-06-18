#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
const int N=26;
int g[N][N];

int main()
{
    string s,t;
    cin>>s>>t;
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<N;i++)
    {
        g[i][i]=0;
    }
    int m=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string a,b;
        int x,y,w;
        cin>>a>>b>>w;
        x=a[0]-'a';
        y=b[0]-'a';
        g[x][y]=min(g[x][y],w);
    }
    if(s.size()!=t.size())
    {
        cout<<-1<<'\n';
        return 0;
    }
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    long long ans=0;
    bool ok=true;
    string p="";
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        int y=t[i]-'a';
        int res=inf;
        char c=0;
        for(int i=0;i<26;i++)
        {
            if(g[x][i]+g[y][i]<res)
            {
                res=g[x][i]+g[y][i];
                c='a'+i;
            }
        }
        if(res==inf)
        {
            ok=false;
            break;
        }
        ans+=res;
        p.push_back(c);
    }
    if(ok)
    {
        cout<<ans<<'\n';
        cout<<p<<'\n';
    }
    else
        cout<<-1<<'\n';
    return 0;
}
