#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
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
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
void solve(){
    cin >> n >> m >> id;
    ll tot = 2;
    tot += id/n;
    tot += id/m;
    cout << tot << "\n";

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

