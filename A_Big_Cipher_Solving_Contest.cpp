#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define njs cout << "najis" << endl;
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+10;
int read() {
    int _ = 0; bool __=0;
    register char ___ = getchar();
    while(___ == ' ' or ___ =='\n') ___ =getchar();
    if(___=='-'){__ = 1; ___ = getchar();}
    while(___ >= '0' and ___ <='9') { _ = (_<<3)+(_<<1)+___-'0'; ___ = getchar();}
    if(__) _*=-1;
    return _;
}   
void print(int _) {
    if (_ < 0) {putchar('-');_ = -_;}
    int __ = 0, ___[10];
    if (_ == 0) {putchar('0');return;}
    while (_ > 0) {___[__++] = _ % 10; _/=10;}
    while (__ > 0) {putchar('0' + ___[--__]);}
}
void File_Work(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
ll n, m, a, b, c, d, id;
struct cstm{
    ll x, y, id;
};
struct cstms{
    ll x, y;
};
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll pgkt(ll rnx, ll rny){
    if(rny == 0) return 1;
    ll nwrn = pgkt(rnx, rny/2);
    if(rny%2){
        return (((nwrn*nwrn)%md)*rnx)%md;
    }else{
        return (nwrn*nwrn)%md;
    }
}
pair<ll,ll> br[ukr];
string s;
ll ar[ukr];
ll sf[ukr], pf[ukr];
ll anssf[ukr];
void solve(){
    n = read();
    m = read();
    for(ll i = 1; i <= n; i++){
       ar[i] = read();
        ar[i] %= m;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        id = read();
        br[i] ={ar[i], id};
        ans += ar[i]*id;
    }
    sort(br+1, br+n+1);
  /*   for(int i = 0; i <= n; i++){
        cout << br[i].first << " " << br[i].second << "\n";
    } */
    for(ll i = n; i >= 1; i--){
        sf[i] = sf[i+1] + br[i].second;
        pf[n-i+1] = pf[n-i] + br[n-i+1].second;
    }
    //njs
    // 1 1 3 3 4 4 
    // 4 4 2 2 1 1 
    // 3 9 1 1 2 4
    //        
    ll pt = 0;
    for(ll i = n, j = n, k = n+1; i >= 1; i--){
        //njs
        anssf[i] += anssf[i+1]+br[i].first*br[i].second;
        if(br[i].first == br[i-1].first) continue;
        ll ss = ((m-br[i-1].first-1)+m)%m;
        anssf[i] += ss*(sf[i]-sf[k]);
        ll sl = ss-pt;
        anssf[i] += sl*(sf[k]);
        k = i;
        pt += sl;
        //cout << "bef " << anssf[i] << "\n";
        while(j >= 1 && br[j].first+pt >= m){
            anssf[i] -= m*br[j].second;
            j--;
        }
        //cout << anssf[i] << "\n";
    }
    ll tot = 0;
    for(ll i = 1; i <= n; i++){
        tot += br[i].first*br[i].second;
        if(ar[i] != ar[i+1]){
            ll tmp = tot + pf[i]*(((m-br[i].first-1)+m)%m) + anssf[i+1];
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";


    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
        
    }
}

