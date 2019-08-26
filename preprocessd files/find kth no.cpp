#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

using namespace __gnu_pbds;




typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 200005
#define mod 1000000007
#define vl          vector < ll >
#define vpl         vector < pair < ll ,ll> >
#define pi          pair < int,int >
#define pl          pair < ll,ll >
#define ff          first
#define ss          second
#define for(i,a,b)  for(ll i=a;i<b;i++)
#define pb(x)       push_back(x)
#define endl        "\n"

tree< pl , null_type, less< pl >, rb_tree_tag, tree_order_statistics_node_update> s;

ll sum[size1];
int main()
{
//    boost1;
//    boost2;

    ll n,m,i,j,t,b,c,x,y,w,l,r,ans1,ans2;
    cin>>n>>t;
//    for(i,0,n){
//        cin>>sum[i];
//    }
//    //sum[0] = 0;
//    for(i,1,n){
//        sum[i] += sum[i-1];
//    }

    ll ans = 0,tmp,g=0;
    //cout<<ans;
    for(i,0,n){
        cin>>tmp;
        s.insert({-g,i});
        g += tmp;
        y = s.order_of_key({t-g,0});

        debug(y);
        ans += y;
    }
    cout<<ans;
    return 0;
}
