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
int n, m, c, d, id, s;
int tot = 0;
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
ll a[151], b[151];
ll dpa[151][15001], dpb[151][15001];
void solve(){
    cin >> n >> m >> id >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    memset(dpa, 0, sizeof(dpa));
    memset(dpb, 0, sizeof(dpb));
    dpa[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dpa[i][j] += dpa[i-1][j];
            dpa[i][j] %= md;
            if(j - a[i] >= 0){
                dpa[i][j] += dpa[i-1][j-a[i]];
                dpa[i][j] %= md;
            }
        }
    }
    dpb[0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= s; j++){
            dpb[i][j] += dpb[i-1][j];
            dpb[i][j] %= md;
            if(j - b[i] >= 0){
                dpb[i][j] += dpb[i-1][j-b[i]];
                dpb[i][j] %= md;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= s; i++){
        int j = s-i;
        if(abs(i-j) > id) continue;
        ans = (ans + (dpa[n][i]*dpb[m][j])%md)%md;
    }
    cout << ans << "\n";
    
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

