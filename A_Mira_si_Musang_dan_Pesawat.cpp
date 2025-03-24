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
    ll vl, x, as;
    bool operator < (const babi&other) const{
        return vl > other.vl;
    }
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
vector<vector<ll>> adj(ukr);
string s;
ll ar[ukr];
ll dp[ukr], dp2[ukr];
ll tg[ukr], tg2[ukr];
priority_queue<babi>pq;
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        dp[i] = dp2[i] = 1e18;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n == 1 || n == 2){
        cout << n-1 << "\n";
        return;
    }
    dp[1] = dp2[n] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        auto rn = pq.top();
        pq.pop();
        if(rn.vl == dp[rn.x]){
            for(auto i : adj[rn.x]){
                if(dp[i] > rn.vl+max(1ll, ar[i]-rn.vl)){
                    dp[i] = rn.vl+max(1ll, ar[i]-rn.vl);
                    tg[i] = max(rn.as, ar[i]);
                    pq.push({dp[i], i, tg[i]});
                }
            }
        }
    }
    pq.push({0, n, 0});
    while(!pq.empty()){
        auto rn = pq.top();
        pq.pop();
        if(rn.vl == dp2[rn.x]){
            for(auto i : adj[rn.x]){
                if(dp2[i] > rn.vl+max(1ll, ar[i]-rn.vl)){
                    dp2[i] = rn.vl+max(1ll, ar[i]-rn.vl);
                    tg2[i] = max(rn.as, ar[i]);
                    pq.push({dp2[i], i, tg2[i]});
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(tg[i] == tg2[i] && tg[i] == ar[i]){
            ans = min(ans, dp[i]+dp2[i]);
        }
        //cout << i << " " << dp[i] << " " << dp2[i] << " " << tg[i] << " " << tg2[i] << "\n";
    }

    cout << ans << "\n";
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

