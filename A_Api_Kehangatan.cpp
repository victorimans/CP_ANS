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
vector<pair<int,int>> v;
vector<pair<int,int>> v2;
string s;
bool hit(double rn){
    int vis[n+1];
    for(int i = 0; i < n; i++){
        vis[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(auto j : v2){
            double skrg = hypot(abs(v[i].first-j.first), abs(v[i].second-j.second));
            if(skrg <= rn){
                vis[i] = 1;
                break;
            }
        }
        if(!vis[i]) return 0;
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v2.push_back({a, b});
    }
    long double l = 0, r = ukr*2, ans = -1;
    for(int i = 0; i < 90; i++){
        long double mid = ((long double)(l+r)/2.0);
        if(hit(mid)){
            r = mid;
            ans = mid;
        }else l = mid;
    }
    cout << fixed << setprecision(17) << ans;
   /*   2.23606797749978969
        2.23606797749978958 */

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

