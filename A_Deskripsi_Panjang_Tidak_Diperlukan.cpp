#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 1e6+10;
ll n, m, a, b, c, d, id;
ll pgkt(ll rnx, ll rny){
    if(rny == 0) return 1;
    ll nwrn = pgkt(rnx, rny/2)%md;
    if(rny%2){
        return ((nwrn*nwrn)%md*(rnx)%md)%md;
    }else{
        return (nwrn*nwrn)%md;
    }
}
map<int,int> mp;
ll pw2[ukr];
void solve(){
    cin >> n;
    ll ans = 0, pt = 2;
    for(ll i = n-2; i >= 1; i--){
        ans = (ans + ((pt*pw2[i])%md)%md)%md;
        //cout << ans << "\n";
        pt = (pt*2)%md;
    }
    //cout << ans;
    ans = (ans + pgkt(2, n)%md -2 + md)%md;
    cout << ans;

}
void pre(){
    pw2[1] = 2;
    ll pt = 4;
    for(int i = 2; i < ukr; i++){
        pw2[i] = (pw2[i-1] + pt)%md;
        pt = (pt*2)%md;
    }
    //cout << invfak[0] << " "<< fak[1] << "\n"; 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}