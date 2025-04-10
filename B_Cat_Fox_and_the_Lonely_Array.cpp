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
int n, m, a, b, c, d, id;
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
ll ar[ukr][20];
string s;
bool cek(ll rn){
    ll ptk = 0;
    for(ll i = 0; i < 20; i++){
        if(ar[rn][i]){
            ptk |= (1LL << i);
        }
    }
    for(ll i = rn+1; i <= n; i++){
        ll sem = 0;
        for(ll j = 0; j < 20; j++){
            if((ar[i][j]-ar[i-rn][j])){
                sem |= (1LL << j);
            }
        }
        if(sem != ptk) return false;
    }
    return true;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> id;
        for(int j = 0; j < 20; j++){
            if(id&(1LL << j)){
                ar[i][j] = 1;
            }else{
                ar[i][j] = 0;
            }
            ar[i][j] += ar[i-1][j];
        }
    }
    ll l = 1, r = n-1, res = n; 
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(cek(mid)){
            r = mid-1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t =1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
        
    }
}

