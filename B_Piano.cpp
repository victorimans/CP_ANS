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
ll w, m, a, b, c, d, n;
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
ll fen[ukr], ar[ukr], dsu[ukr], vis[ukr];
void upd(ll rn, ll vl){
    for(ll i = rn; i < ukr; i += (i&-i)){
        fen[i] += vl;
    }
}
ll get(ll rn){
    ll tot = 0;
    for(ll i = rn; i > 0; i -= (i&-i)){
        tot += fen[i];
    }
    return tot;
}
vector<int> v;
string s = "wbwbwwbwbwbw";
void solve(){
    cin >> w >> b;
    n = s.length();
    for(int i = 0; i < n; i++){
        int tmpw = w;
        int tmpb = b, idx = i;
        while(tmpw > 0 || tmpb > 0){
            if(s[idx] == 'w'){
                tmpw--;
            }else{
                tmpb--;
            }
            idx++;
            idx%=n;
        }
        if(tmpw == 0 && tmpb == 0){
            cout << "Yes";
            return;
        }
    }
    cout << "No";

}

//1, 110, 11100
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








/* 
1 1


 */