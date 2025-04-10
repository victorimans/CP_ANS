#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e6+10;
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
vector<ll> v;
string s;
ll pf[ukr];
void solve(){
    cin >> n >> m;
    cin >> s;
    pf[0] = 0;
    for(int i = 1; i <= n; i++){
        pf[i] = pf[i-1] + (s[i-1]-'0');
    }
    string ans = "";
    int rn = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '0'){
            if(m <= pf[i]){
                //cout << cnt << " " << i << " " << rn  << " "<< pf[i] << " " << m << "\n";
                for(int j = 1; j <= cnt; j++){
                    ans += '0';
                }
                for(int j = 1; j <= pf[rn]; j++){
                    ans += '1';
                }
                for(int j = rn+1; j <= n; j++){
                    ans += s[j-1];
                }
              /*   cout << ans << "\n";
                cout << m << "\n"; */
                for(int j = i; m; m--){
                    swap(ans[j-1], ans[j-2]);
                    j--;
                }
                cout << ans << "\n";
                //01111010
                //01110110
                return;
            }else{
                m -= pf[i];
                rn = i;
                cnt++;
            }
        }
    }
    if(rn == 0){
        ans = s;
        cout << ans << "\n";
        return;
    }
    for(int j = 1; j <= cnt; j++){
        ans += '0';
    }
    for(int j = 1; j <= pf[n]; j++){
        ans += '1';
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

