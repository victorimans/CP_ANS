#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
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
vector<ll> v;
string s;
ll ar[ukr];
ll pp[ukr];
bool cek(ll rn){
    ll tmp = n;
    for(ll i = 0; i < m; i++){
        ll sk = (ll)(rn/pp[i] + 1LL);
        tmp -= ar[i]*sk;
        if(tmp <= 0){
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> ar[i];
    }
    ll mx = 0;
    for(int i = 0; i < m; i++){
        cin >> pp[i];
        mx = max((n+ar[i]-1)/ar[i] * pp[i], mx);
    }
    ll l = 0, r = mx, ans = mx;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(cek(mid)){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout << ans+1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t =1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
        
    }
}

