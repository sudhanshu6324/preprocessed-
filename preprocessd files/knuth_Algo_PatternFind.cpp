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

    //debug(t);
    while(t--){
        cin>>str;
        cin>>pat;
        vector<int> v;
        //cout<<pat<<endl;
        n = str.length();
        m = pat.length();

        if(n < m){
            cout<<"Not Found"<<endl<<endl;
            continue;
        }
        a[0] = 0;
        i = 0;
        j = 1;
       // debug(m);
       mem(a);
        while(j<m){
            if(pat[j] == pat[i]){
                a[j] = i+1;
                j++;
                i++;
            }else{
                //i = a[i-1];

                if(i>0){
                    i = a[i-1];
                }else{
                    a[j] = 0;
                    j++;
                }
            }
        }

        j = 0;
        i = 0;
        while(i<n){

            if(j<m && i < n && pat[j] == str[i]){
                i++;
                j++;
            }

            if(j == m){
                v.pb(i-m);
                j = a[j-1];
            }

            if(i<n && j<m && pat[j] != str[i]){
                if(j!=0){
                    j = a[j-1];
                }else{
                    i++;
                }
            }
        }
        if(v.size() == 0){
            cout<<"Not Found"<<endl<<endl;
        }else{
            cout<<v.size()<<endl;
            for(i=0;i<v.size();i++){
                cout<<v[i]+1<<" ";
            }
            cout<<endl<<endl;
        }
    }
    return 0;
}
