#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+10;
int read() {
    int _ = 0; bool __=0;
    register char ___ = getchar();
    while(___ == ' ' or ___ =='\n') ___ =getchar();
    if(___=='-'){__ = 1; ___ = getchar();}
    while(___ >= '0' and ___ <='9') { _ = (_<<3)+(_<<1)+___-'0'; ___ = getchar();}
    if(__) _*=-1;
    return _;
}   
void print(int _) {
    if (_ < 0) {putchar('-');_ = -_;}
    int __ = 0, ___[10];
    if (_ == 0) {putchar('0');return;}
    while (_ > 0) {___[__++] = _ % 10; _/=10;}
    while (__ > 0) {putchar('0' + ___[--__]);}
}
void File_Work(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
ll n, m, a, b, c, d, id;
struct cstm{
    ll x, y, id;
};
struct cstms{
    ll x, y;
};
ll gcd(ll a, ll b) {
    if(b == 0) return a;
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
void solve(){
    cin >> n;
    ll tot = 0;
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if(i*j != n){
                tot += i*j;
            }
        }
    }
    cout <<tot << "\n";
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

