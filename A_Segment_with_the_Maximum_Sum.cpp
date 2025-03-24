#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
/* const ll md = 1000000; */
const int ukr = 1e6+1;
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
ll n, m, a, b, c, d, id, pgkt = 1;
ll tot = 0;
struct babi{
    ll ans, pf, sf, sum;
};
struct babis{
    ll x, y;
};
vector<int> v;
babi ar[ukr];
void upd(ll k, ll u, ll rn, ll lx, ll rx){
    if(lx == rx){ar[rn].ans = ar[rn].pf = ar[rn].sf = ar[rn].sum = u; return;}
    ll mid = (lx+rx)/2;
    if(k <= mid){
        upd(k, u, 2*rn, lx, mid);
    }else{
        upd(k, u, 2*rn+1, mid+1, rx);
    }
    ar[rn] = {max({ar[rn*2].ans, ar[rn*2+1].ans, ar[rn*2].sf + ar[rn*2+1].pf}), 
            max({ar[rn*2].pf, ar[rn*2].sum + ar[rn*2+1].pf}),
            max({ar[rn*2+1].sf, ar[rn*2+1].sum + ar[rn*2].sf}),
            ar[rn*2].sum + ar[rn*2+1].sum};
}
babi get(ll l, ll r, ll rn, ll lx, ll rx){
    if(l > rx || r < lx) return {0, 0, 0, 0};
    if(l <= lx && rx <= r) return ar[rn];
    ll mid = (lx + rx) / 2;
    babi kiri = get(l, r, 2*rn, lx, mid);
    babi kanan = get(l, r, 2*rn+1, mid+1, rx);
    return ar[rn]={max({kiri.ans, kanan.ans, kiri.sf + kanan.pf}), 
            max({kiri.pf, kiri.sum + kanan.pf}),
            max({kanan.sf, kanan.sum + kiri.sf}),
            kiri.sum + kanan.sum};
}
void solve(){
    cin >> n >> m;
    while(n > pgkt){
        pgkt *= 2;
    }
    //cout << pgkt << endl;
    for(ll i = 0; i < n; i++){
        cin >> ar[pgkt+i].sum;
        ar[pgkt+i].ans = ar[pgkt+i].pf = ar[pgkt+i].sf = ar[pgkt+i].sum;
    }
    for(ll i = pgkt-1; i > 0; i--){
        ar[i] = {max({ar[i*2].ans, ar[i*2+1].ans, ar[i*2].sf + ar[i*2+1].pf}), 
            max({ar[i*2].pf, ar[i*2].sum + ar[i*2+1].pf}),
            max({ar[i*2+1].sf, ar[i*2+1].sum + ar[i*2].sf}),
            ar[i*2].sum + ar[i*2+1].sum};
    }
    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        cout << max(ar[1].ans, (ll)0) << "\n";
        upd(a, b, 1, 0, pgkt-1);
    }
    cout << max(get(0, n-1, 1, 0, pgkt-1).ans, (ll)0) << "\n";

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

