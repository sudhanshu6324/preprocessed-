#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include<bits/stdc++.h>
#include <math.h>
#define  q  1000000007
#define  f(i,n)  for(ll i=0;i<n;i++)
#define ll long long
using namespace std;

int digit[10],k,m,a[11];
long long res;

void fun(int tight,int inc,int dec,int idx,int arridx){
    int i;
    if(idx == 18){
        return;
    }

    long long c= 0;
    long long res = 0;
    int last;

    for(i=0;i<m;i++){
        if(a[i] <= digit[idx]){
            last  = a[i];
        }else{
            break;
        }
    }
    if(!tight)
        last = 16;

    if(inc > 0){
        if(inc <k){
            for(i = arridx;i<m && i >=0 ;i++){
                if(a[i] < last){
                    fun(0,inc+1,0,idx+1,i+1);
                }else if(a[i] == last){
                    fun(1,inc+1,0,idx+1,i+1);
                }
            }
        }
       for(i = arridx-2;i>=0;i--){
            if(a[i] < last){
                fun(0,1,0,idx+1,i-1);
            }else if(a[i] == last){
                fun(1,inc+1,0,idx+1,i-1);
            }
        }

    }else if(dec > 0){
        if(dec < k){
            for(i = arridx-2;i>=0;i--){
                if(a[i] < last){
                    fun(0,0,dec+1,idx+1,i-1);
                }else if(a[i] == last){
                    fun(1,0,dec+1,idx+1,i-1);
                }
            }
        }
       for(i = arridx+2;i<m;i++){
            if(a[i] < last){
                fun(0,1,0,idx+1,i+1);
            }else if(a[i] == last){
                fun(1,1,0,idx+1,i+1);
            }
        }
    }else{
        fun(0,0,0,idx+1,0);
        //fun(1,0,0,idx+1,0);
    }
   res *= max(c,(long long)1);
}
int main(){
    int t,i;
    long long l,r;
    cin>>t;
    while(t--){
        cin>>m;
        for(i=0;i<m;i++){
            cin>>a[i];
        }
        sort(a,a+m);
        cin>>k;
        cin>>l>>r;
        memset(digit,0,sizeof digit);
        while(r!=0){
            digit[i] = r%10;
            r /= 10;
        }
        reverse(digit,digit+18);
        res = 1;
        fun(0,0,0,0,0);
        long long res1 = res;

        memset(digit,0,sizeof digit);
        l--;
        while(l!=0){
            digit[i] = l%10;
            l /= 10;
        }
        reverse(digit,digit+18);
        res = 1;
        fun(0,0,0,0,0);
        cout<<res <<" "<< res1<<endl;
    }

}

