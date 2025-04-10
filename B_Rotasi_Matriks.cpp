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
deque<pair<ll,ll>> v;
string s;
deque<pair<ll,ll>> spes;
ll ans[ukr];
ll ar[101][101];
ll tmp[101][101];
ll trgt[101][101];
int fl = 0;
void ubh(){
    if(!fl){
        for(int i = 0, sm = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                tmp[i][j] = ar[n-j-1][sm];
            }
            sm++;
        }
    }else{
        for(int i = 0, sm = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ar[i][j] = tmp[n-j-1][sm];
            }
            sm++;
        }
    }
    swap(n, m);
    fl ^= 1;
}
void solve(){
    cin >> n >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ar[i][j];
        }
    }
    cin >> n >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> trgt[i][j];
        }
    }
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

