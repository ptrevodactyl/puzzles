#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007

typedef long long int ll;

ll ncr(ll n){
    ll ans=n*(n-1);
    return ans/2;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t; cin >> t; while(t--) {
       ll n,a=0,b=0,c=0; cin>>n;
       string s;
       for(int i=0;i<n;i++){
           cin>>s;
           bool ok1=false,ok2=false;
           for(auto it:s){
               if(it=='0') ok1=true;
               else ok2=true;
           }
           if(ok1 && ok2) c++;
           else if(ok1) a++;
           else b++;
       }

       ll ans=ncr(a) + ncr(b) + ncr(c) + a * c + b * c;
       cout << ans << '\n';
    }
	return 0;

}
