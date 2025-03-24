#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 3e5+10;
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
pair<ll,ll> dsu[ukr];
int cekies(int rn){
    if(dsu[rn].first == rn) return rn;
    return dsu[rn].first = cekies(dsu[rn].first);
}
void join(int a, int b){
    int ax = cekies(a);
    int bx = cekies(b);
    if(ax == bx) return;
    if(ax > bx){
        dsu[ax].first = bx;
        dsu[bx].second += dsu[ax].second;
    }else{
        dsu[bx].first = ax;
        dsu[ax].second += dsu[bx].second;
    }
}
string s;
ll ar[ukr];
vector<pair<ll,pair<ll,ll>>> v;
ll ans[ukr];
void solve(){
    cin >> n >> m;
    ll ma = 0, idx = 0;
    for(int i = 0; i < n; i++){
        cin >> dsu[i].second;
        dsu[i].first = i;
        if(dsu[i].second > ma){
            ma = dsu[i].second;
            idx = i;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    cin >> id;
    for(int i = 0; i < id; i++){
        cin >> a;
        v.push_back({a, {-1, i}});
    }
    sort(all(v), greater<pair<ll,pair<ll,ll>>>());
    for(auto i : v){
        if(i.second.first == -1){
            ans[i.second.second] = idx;
        }else{
            join(i.second.first, i.second.second);
            ll rn = cekies(i.second.first);
            if(dsu[rn].second > ma){
                ma = dsu[rn].second;
                idx = rn;
            }else if(dsu[rn].second == ma){
                idx = min(idx, rn);
            }
        }
    }
    for(int i = 0; i < id; i++){
        cout << ans[i] << "\n";
    }
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

