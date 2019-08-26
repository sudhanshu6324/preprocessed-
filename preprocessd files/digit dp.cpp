#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 200005
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
ll dp[2][22][10][2][10][513];
int MASK,K,digit[25];

ll fun(int tight,int idx,int prev,int type,int k,int mask){
    if(k > K){
        return 0;
    }
    if(idx == 20){
        if((mask&MASK) == MASK){
            return 1;
        }
        return 0;
    }
    ll &res = dp[tight][idx][prev][type][k][mask];

    if(res != -1) return res;      // ~res == non zero if res == -1

    res = 0;

    if(!mask){
            res += fun(tight|digit[idx]>0,idx+1,0,1,0,0);
    }
    for(int i=1;i<=9;i++){
        if(i!= prev && (tight || (!tight && i <= digit[idx]))){
            if(prev < i != type){
                res += fun(tight|i<digit[idx],idx+1,i,prev<i,2,mask|(1<<(i-1)));
            }else{
                res += fun(tight|i<digit[idx],idx+1,i,prev<i,k+1,mask|(1<<(i-1)));
            }
        }
    }

    return res;
}

ll func(ll x){

    for(int i=19;i>=0;i--){
        digit[i] = x%10;
        x /= 10;
    }
    mem1(dp);

    return fun(0,0,0,1,0,0);
}

int main()
{
    boost1;
    //boost2;
    int n,m,i,j,t,x,y,w;
    ll l,r;
    cin>>t;
    while(t--){
        cin>>m;
        MASK = 0;
        while(m--){
            cin>>x;
            MASK = MASK | (1<<(x-1));
        }
        cin>>K;
        cin>>l>>r;
        cout<<func(r) - func(l-1)<<endl;
    }
    return 0;
}
