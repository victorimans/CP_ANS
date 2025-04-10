#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 998244353;
const int ukr = 6e5+10;
const int ukr2 = 3e5+10;
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
vector<int> v;
string s;
ll pf[ukr];
ll fak[ukr2],invfak[ukr2], ar[ukr2];
void solve(){
    n = read();
    m = read();
    for(int i = 1; i <= n; i++){
        ar[i] = read();
    }
    for(ll i = 1; i <= n; i++){
        pf[i] = pf[i-1]+ar[i];
    }
    for(ll i = 1; i <= n; i++){
        pf[i+n] = pf[i-1+n]+ar[i];
    }
    if(pf[n]%2 == 0){
        ll kel = pf[n]/2;
        ll pr = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ll l = i, r = 2*n;
            while(l <= r){
                ll mid = l + (r-l)/2;
                if(pf[mid]-pf[i] == kel){
                    pr++;
                    break;
                }
                if(pf[mid]-pf[i] < kel){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        pr /= 2;
        //cout << pr << endl;
        ll tdk = n-(2*pr);
        for(ll i = 0; i <= min(pr, m); i++){
            ll ss = pr-i;
            ll val1 = ((fak[pr]*invfak[i])%md*invfak[pr-i])%md;
            ll val2 = (fak[m]*invfak[m-i])%md;
            ll val3 = pgkt(((ll)(m-i)*((ll)m-i-1))%md, ss);
            ll val4 = pgkt(m-i, tdk);
            ans = (ans+(((val1*val2)%md*val3)%md*val4)%md)%md;
            //cout << ans << "\n";
        }
        cout << ans << "\n";
    }else{
        cout << pgkt(m, n) << "\n";
    }
}
void pre(){
    fak[0] = 1;
    for(ll i = 1; i < ukr2; i++){
        fak[i] = ((ll)fak[i-1]*i)%md;
    }
    invfak[ukr2-1] = pgkt(fak[ukr2-1], md-2);
    for(ll i = ukr2-2; i >= 0; i--){
        invfak[i] = ((ll)invfak[i+1]*(i+1))%md;
    }
    //cout << invfak[0]<<"\n";
    //cout << invfak[2]<<pgkt(2, md-2) << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
	int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

