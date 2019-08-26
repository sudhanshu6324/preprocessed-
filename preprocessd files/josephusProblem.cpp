#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 1005
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

int dp[size1][size1];

int a[size1];
int main()
{
//    boost1;
//    boost2;
    string str,pat;
    int n,m,i,j,t,x,y,w,o;
    cin>>t;

    debug(t);
    while(t--){
        //cin>>str;
        cin>>pat;
        cout<<pat<<endl;
    //    n = str.length();
        m = pat.length();

//        if(n < m){
//            cout<<"Not Found"<<endl;
//            continue;
//        }
        a[0] = 0;
        i = 0;
        j = 1;
        debug(m);
        while(j<m){
            if(pat[j] == pat[i]){
                a[j] = i+1;
                j++;
                i++;
            }else{
                //i = a[i-1];
                j++;
                if(i>0){
                    i = a[i-1];
                }
            }
        }
        for(i=0;i<m;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
