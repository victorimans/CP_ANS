#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e5+10;
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
string s;
vector<pair<int,int>> v;
void solve(){
    n = read();
    m = read();
    vector<pair<int,int>>kc(n+1, {0,0});
    vector<pair<int,int>>bsr(n+1, {n+1,n+1});
    for(int i = 1; i <= m; i++){
        a = read();
        b = read();
        if(bsr[a].first > b){
            bsr[a].second = bsr[a].first;
            bsr[a].first = b;
        }else if(bsr[a].second > b){
            bsr[a].second = b;
        }
        if(kc[b].first < a){
            kc[b].second = kc[b].first;
            kc[b].first = a;
        }else if(kc[b].second < a){
            kc[b].second = a;
        }
        v.push_back({a, b}); 
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans += (ll)abs(kc[i].first-i)*abs(i-bsr[i].first);
        //cout << kc[i].first << " " << kc[i].second << " <-> " << bsr[i].first << " " << bsr[i].second << "\n";
    }
    for(auto [ax, bx] : v){
        if(bsr[ax].first != bx) continue;
        if(kc[bx].first != ax) continue;
        ll l = max(kc[ax].first, kc[bx].second);
        ll r = min(bsr[ax].second, bsr[bx].first);
        //cout << l  << " " << r << " " << ax << " " << bx << "\n";
        ans += (ll)abs(l-ax)*abs(r-bx)*2LL;
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

