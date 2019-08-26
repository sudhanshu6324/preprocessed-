#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 100005
#define mod 1000000007
#define vll         vector < ll >
#define vpll        vector < pair < ll ,ll> >
#define pii         pair < int,int >
#define pll         pair < ll,ll >
#define fi          first
#define se          second
#define pb(x)       push_back(x)
#define endl        "\n"
#define mem1(x)     memset(x,-1,sizeof x)
#define mem(x)      memset(x,0,sizeof x)
#define mem63(x)    memset(x,63,sizeof x)

int level[size1],p[size1],dp[19][size1];
vector<int> v[size1];

void dfs(int u,int par,int l){
    p[u] = par;
    level[u] = l;
    for(int i=0;i< v[u].size();i++){
        if(v[u][i] != par){
            dfs(v[u][i],u,l+1);
        }
    }
}

void pre(int n){
    int maxiHeight = log(n) + 1;
    int i,j;
    for(i=0;i<n;i++){
        dp[0][i] = p[i];
    }

    for(i=1;i<maxiHeight;i++){
        for(j=0;j<n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

int findLca(int n,int u,int v){
    if(level[v] < level[u]){
        swap(u,v);
    }
    int diff = level[v] - level[u];

    while(diff > 0){
        int log2 = log(diff);

        v = dp[log2][v];
        diff  = diff - (1<<log2);
    }

    while(u!=v){
        int i = log(level[u]);
        //debug(level[u]);
        for(;i>0 && dp[i][u] == dp[i][v];){
            i--;
        }

        u = dp[i][u];
        v = dp[i][v];
    }

    return u;
}
int main()
{
    //boost1;
    //boost2;
    int n,m,i,j,t,x,y,w,k=1,q;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>m;
            while(m--){
                cin>>x;
                x--;
                v[i].pb(x);
                v[x].pb(i);
            }
        }
        dfs(0,-1,1);
        pre(n);

        cin>>q;
        cout<<"Case "<<k++<<":"<<endl;
        while(q--){
            cin>>x>>y;
            x--;
            y--;
            cout<<findLca(n,x,y)+1<<endl;
        }
        for(i=0;i<n;i++){
            v[i].clear();
        }
    }
    return 0;
}
