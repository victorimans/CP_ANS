#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e6+10;
int read() {
    int ketek = 0; bool ne=0;
    register char c = getchar();
    while(c == ' ' or c =='\n') c =getchar();
    if(c=='-'){ne = 1; c = getchar();}
    while(c >= '0' and c <='9') { ketek = (ketek<<3)+(ketek<<1)+c-'0'; c = getchar();}
    if(ne) ketek*=-1;
    return ketek;
}   
void print(int x) {
    if (x < 0) {putchar('-');x = -x;}
    int len = 0, buf[10];
    if (x == 0) {putchar('0');return;}
    while (x > 0) {buf[len++] = x % 10; x/=10;}
    while (len > 0) {putchar('0' + buf[--len]);}
}
void File_Work(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
int n, m, a, b, c, d, id;
struct babi{
    ll x, y, id;
};
struct babis{
    ll x, y;
};
ll gcd(ll a, ll b) {
   if (b == 0) return a;
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
vector<pair<int,pair<int,int>>> v;
string s;
ll dp[ukr];
void upd(ll k, ll vl, ll rn, ll l, ll r){
    if(l == r){
        dp[rn] = min(dp[rn], vl); 
        return;
    }
    ll mid = (l+r)/2;
    if(k <= mid){
        upd(k, vl, 2*rn, l, mid);
    }else{
        upd(k, vl, 2*rn+1, mid+1, r);
    }
    dp[rn] = min(dp[2*rn], dp[2*rn+1]);
}
ll get(ll l, ll r, ll rn, ll lx, ll rx){
    //cout << l << " " << r << " " << rn << " " << lx << " " << rx << endl;
    if(rx < l || r < lx){
        return 1e18;
    }
    if(l <= lx && rx <= r){
        return dp[rn];
    }
    ll mid = (lx+rx)/2;
    return min(get(l, r, 2*rn, lx, mid), get(l, r, 2*rn+1, mid+1, rx));
}
void solve(){
    cin >> n >> m >> id;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v.push_back({a, {b, c}});
    }
    sort(all(v));
    ll pw2 = 1;
    while(n+1 > pw2){
        pw2 *= 2;
    }
    for(ll i = 0; i < pw2; i++){
        dp[i+pw2] = 1e18;
    }
    dp[pw2] = 0;
    for(ll i = pw2-1; i >= 1; i--){
        dp[i] = min(dp[i*2], dp[i*2+1]);
    }
    for(int i = 1, j = 0; i <= n; i++){
        while(j < m && v[j].first == i){
            ll gt = get(v[j].first-1, v[j].second.first-1,1, 0, pw2-1);
            upd(v[j].second.first, gt+v[j].second.second, 1, 0, pw2-1);
            j++;
        }
        upd(i, dp[i-1+pw2]+id, 1, 0, pw2-1);
    }
    cout << dp[n+pw2] << "\n";
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

