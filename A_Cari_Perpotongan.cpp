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
vector<vector<int>>v(ukr);
int ar[ukr*5];
string s;
int lst[ukr], sk[ukr];
void upd(ll k, ll val, ll rn, ll lx, ll rx){
    if(lx == rx){
        ar[rn] = val;
        return;
    }
    ll mid = (lx+rx)/2;
    if(k <= mid){
        upd(k, val, 2*rn, lx, mid);
    }else{
        upd(k, val, 2*rn+1, mid+1, rx);
    }
    ar[rn] = ar[2*rn] + ar[2*rn+1];
}
ll get(ll l, ll r, ll rn, ll lx, ll rx){
    if(r < lx || rx < l){
        return 0;
    }
    if(l <= lx && rx <= r){
        return ar[rn];
    }
    ll mid = (lx+rx)/2;
    return get(l, r, 2*rn, lx, mid) + get(l, r, 2*rn+1, mid+1, rx);
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> id;
            v[i].push_back(id);
        }
    }
    for(int i = 0; i < n; i++){
        lst[i] = v[i][0];
    }
    ll pw2 = 1;
    while(n > pw2){
        pw2 *= 2;
    }
    ll ans = 0;
    
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            upd(j, 0, 1, 0, pw2-1);
            sk[v[j][i]] = j;
        }
        for(int j = 0; j < n; j++){
            ans += get(sk[lst[j]], pw2-1, 1, 0, pw2-1);
            upd(sk[lst[j]], 1, 1, 0, pw2-1);
            lst[j] = v[j][i];
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

