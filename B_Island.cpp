#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+10;
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
ll n, m, a, b, c, d, id;
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
vector<pair<ll,ll>> v;
string s;
ll ar[ukr];
ll pulau[ukr];
ll nilai[ukr];
ll seg[ukr*5];
void upd(ll k, ll u, ll rn, ll lx, ll rx){
    if(lx == rx){seg[rn] = u; return;}
    ll mid = (lx+rx)/2;
    if(k <= mid){
        upd(k, u, 2*rn, lx, mid);
    }else{
        upd(k, u, 2*rn+1, mid+1, rx);
    }
    seg[rn] = max(seg[2*rn] ,seg[2*rn+1]);
}
ll get(ll l, ll r, ll rn, ll lx, ll rx){
    if(r < lx || l > rx){
        return -LLONG_MAX;
    }
    if(l <= lx && rx <= r){
        return seg[rn];
    }
    ll mid = (lx+rx)/2;
    return max(get(l, r, 2*rn, lx, mid), get(l, r, 2*rn+1, mid+1, rx));
}
void solve(){
    cin >> n >> id;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        ar[i] += ar[i-1];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({n+1, n+1});
    sort(all(v));
    ll l = 1, r = 1, idx = 0, cnt = 1;
    while(r <= n){
        if(r < v[idx].first){
            pulau[cnt] = r-l+1+pulau[cnt-1];
            nilai[cnt] = ar[r]-ar[l-1]+nilai[cnt-1];
            cnt++;
            l = r = r+1;
        }else{
            r = max(v[idx].second, r);
            idx++;
        }
    }
    ll pw2 =1;
    while(cnt > pw2){
        pw2 *= 2;
    }
    for(int i = 1; i < cnt; i++){
        seg[i+pw2] = nilai[i]; 
    }
    for(int i = pw2; i >= 1; i--){
        seg[i] = max(seg[i*2],seg[i*2+1]);
    }
    ll ans = 0;
    for(ll i = 1; i < cnt; i++){
        l = i, r = cnt-1, idx = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(pulau[mid]-pulau[i-1] <= id){
                l = mid+1;
                idx = mid;
            }else{
                r = mid-1;
            }
        }
        if(idx == -1) continue;
        ll gt = get(i, idx, 1, 0, pw2-1);
        ans = max(ans, gt-nilai[i-1]);
    }
    cout << ans;
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

