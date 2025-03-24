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
vector<pair<ll,ll>> v;
vector<pair<ll,ll>> sl;
vector<ll> pp;
char s[10];
void solve(){
    scanf("%s", s);
    n = read();
    m = read();
    for(ll i = 0; i < n; i++){
        id = read();
        v.push_back({id, i});
    }
    sort(all(v));
    ll ps = 0, l = 0, r = 0;
    for(ll i = 0; i < n; i++){
        r = max(v[i].second, r);
        if(l == r){
            l++; r++;
            continue;
        }
        if(r == i){
            sl.push_back({l, r});
            l = r+1; r++;
        }
        //cout << l << " " << r << endl;
    }
    ll ans = 0;
    m -= sl.size();
    for(ll i = 0; i < sl.size(); i++){
        ans += sl[i].second-sl[i].first+1;
        if(i > 0){
            pp.push_back(sl[i].first-sl[i-1].second-1);
        }
    }
    sort(all(pp), greater<ll>());
    if(m >= 0){
        ans += m;
    }else{
        while(m < 0){
            m++;
            ans += pp.back();
            pp.pop_back();
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

