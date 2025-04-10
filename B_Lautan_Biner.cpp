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
vector<int> v;
string s;
ll cek(ll a, ll b){
    return (b < 0 ? 0 :((a&b) == 0));
}
ll get(ll x, ll y){
    //if(y < 0) return 0;
    if(y <= 0) return 0;
    if(x == 0) return 1;
    ll rn = y;
    for(int i = 30; i >= 0; i--){
        if(x&(1ll << i)) rn = (rn/(1ll << (i+1)))*(1ll << i) + min(rn%(1ll << (i+1)), (1ll << i));
    }
    ll pp = (ll)x&(-x);
    //cout << x << " " << y << " " << pp << " " << rn << "\n";
    return rn/pp+(rn%pp > 0 ? 1 : 0);
}
ll rec(ll hor, ll x1, ll x2){
    return get(hor, x2+1)-get(hor, x1)+(cek(hor, x1)&cek(hor, x1-1));
}
//0 1 2 4 , 0 1 4
ll hit(ll ki, ll ats, ll ka, ll bwh){
    //cout << rec(ki, ats, bwh)  << " " << rec(ats, ki, ka) << "\n";
    return rec(ki, ats, bwh) + rec(ats, ki, ka) - cek(ki, ats);
}
void solve(){
    n = read(); m = read(); id = read();
    
    for(int i = 0; i < id; i++){
        a = read(); b = read(); c = read(); d = read();
        cout << hit(a, b, c, d) << "\n";
    }
    //cout << get(1, 9) << " "<< get(1, 0)<< "\n";
    //cout << get(1, 0) << " " << get(1, 3) << "\n";
    //cout << rec(1, 0, 2)<< "\n";
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

