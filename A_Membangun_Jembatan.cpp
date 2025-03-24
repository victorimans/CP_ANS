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
string s;
int dsu[ukr];
int cekies(int rn){
    if(dsu[rn] == rn) return rn;
    return dsu[rn] = cekies(dsu[rn]);
}
void join(int a, int b){
    int ax = cekies(a);
    int bx = cekies(b);
    if(ax == bx) return;
    if(ax < bx){
        dsu[bx] = ax;
    }else{
        dsu[ax] = bx;
    }
}
ll ar[ukr];
vector<vector<pair<ll,ll>>> v(ukr);
deque<ll> blm;
vector<pair<ll,ll>> sisa;
vector<vector<ll>> idx(ukr);
vector<pair<ll,ll>> ans;
void solve(){
    n = read();
    m = read();
    id = read();
    for(int i = 1; i <= n; i++){
        ar[i] = read();
        dsu[i] = i;
    }
    int tet = n;
    while(m--){
        a = read(); b = read();
        if(cekies(a) == cekies(b)){
            continue;
        }
        tet--;
        join(a, b);
    }
    if(tet == 1){
        cout << 0 << "\n" << 0 << "\n";
        return;
    }
    if(2*(tet-1) > n){
        cout << -1 << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        v[cekies(i)].push_back({ar[i], i});
    }
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].empty()) continue;
        sort(all(v[i]));
        tot += v[i][0].first;
        idx[i].push_back(v[i][0].second);
        for(int j = 1; j < v[i].size(); j++){
            sisa.push_back({v[i][j]});
        }
    }
    sort(all(sisa));
    // need edges 2*(tet-1) -> alrd taken tet so left with tet-2
    for(int i = 0; i < tet-2; i++){
        tot += sisa[i].first;
        idx[cekies(sisa[i].second)].push_back(sisa[i].second);
    }
    for(int i = 1; i <= n; i++){
        if(idx[i].size() > 1){
            if(blm.empty()){
                blm.push_back(idx[i][0]);
            }else{
                ans.push_back({blm.front(), idx[i][0]});
                blm.pop_front();
            }
            for(int j = 1; j < idx[i].size(); j++){
                blm.push_back(idx[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(idx[i].size() == 1){
            if(blm.empty()){
                blm.push_back(idx[i][0]);
            }else{
                ans.push_back({blm.front(), idx[i][0]});
                blm.pop_front();
            }
        }
    }
    cout << tot << "\n";
    cout << ans.size() << "\n";
    for(auto i : ans) {
        cout << i.first << " " << i.second << "\n";
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

