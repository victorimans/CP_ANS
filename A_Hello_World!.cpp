#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const ll ukr = 1e5+10;
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
vector<vector<pair<ll,ll>>> adj(ukr);
string s;
ll dp[ukr], vis[ukr];
pair<ll,ll> ar[ukr];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
bool cek(ll rn){
    for(ll i = 0; i <= n; i++){
        dp[i] = (ll)md*ukr;
        vis[i] = 0;
    }
    for(ll i = 1; i <= rn; i++){
        pq.push({0, i});
        dp[i] = 0;
    }
    while(!pq.empty()){
        auto [ww, rn] = pq.top();
        pq.pop();
        if(vis[rn]) continue;
        vis[rn] = 1;
        for(auto [nxt, w] : adj[rn]){
            if(dp[nxt] > dp[rn]+w){
                dp[nxt] = dp[rn]+w;
                pq.push({dp[nxt], nxt});
            }
        }
    }
    for(int i = 1; i <= id; i++){
        if(dp[ar[i].first] > ar[i].second){
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> id;
    for(int i = 1; i <= id; i++){
        cin >> a >> b;
        ar[i] = {a, b};
    }
    ll l = 1, r = n,  res = -1;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(cek(mid)){
            r = mid-1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    //cout << res << "\n";
    for(int i = 0; i <= n; i++){
        dp[i] = (ll)md*ukr;
        vis[i] = 0;
    }
    for(ll i = 1; i <= res-1; i++){
        pq.push({0, i});
        dp[i] = 0;
    }
    while(!pq.empty()){
        auto [ww, rn] = pq.top();
        pq.pop();
        if(vis[rn]) continue;
        vis[rn] = 1;
        for(auto [nxt, w] : adj[rn]){
            if(dp[nxt] > dp[rn]+w){
                dp[nxt] = dp[rn]+w;
                pq.push({dp[nxt], nxt});
            }
        }
    }
    ll ans =  0;
    for(ll i = 1; i <= id; i++){
        if(dp[ar[i].first] > ar[i].second){
            ans = max(ans, i);
        }
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

