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
    cin >> n >> m;
    if(m < n){
        cout << (m-1)/2LL << "\n";
    }else{
        ll tot = 0;
        if(m%2){
            tot += max(min(n-m/2, m/2), 0ll);
        }else{
            // k = 4, n = 3
            tot += max(min(n-m/2, m/2-1), 0ll);
        }
        cout << tot << "\n";
    }

/* 
7
1 
2 7
3 6
4 5

8
1 8
2 7x`
3 6
4 5

9 
1
2 9
3 8
4 7
5 6

10
1 10
2 9
3 8
4 7
5 6


14
1





*/
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

