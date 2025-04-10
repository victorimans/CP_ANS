#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e5+10;
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
ll n, m, a, b, c, d, id, e;
struct babi{
    ll x, y, id;
};
struct babis{
    ll id, x;
    bool operator < (const babis &other) const{
        return id > other.id;
    }
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
vector<vector<pair<ll,ll>>> adj(7*ukr);
int idx[2][3*ukr];
ll dp[7*ukr];
string s;
priority_queue<babis> pq;
void build(ll pp, ll rn, ll l, ll r){
    idx[pp][rn] = a++;
    if(l == r){
        if(pp){
            adj[idx[pp][rn]].push_back({l, 0});
        }else{
            adj[l].push_back({idx[pp][rn], 0});
        }
        return;
    }
    ll mid = (l+r)/2;
    build(pp, 2*rn, l, mid);
    build(pp, 2*rn+1, mid+1, r);
    if(pp){
        adj[idx[pp][rn]].push_back({idx[pp][2*rn], 0});
        adj[idx[pp][rn]].push_back({idx[pp][2*rn+1], 0});
    }else{
        adj[idx[pp][2*rn]].push_back({idx[pp][rn], 0});
        adj[idx[pp][2*rn+1]].push_back({idx[pp][rn], 0});
    }
}
void add(ll pp, ll u, ll w, ll l, ll r, ll rn, ll lx, ll rx){
    //cout << pp << " " << u << " " << w << " " << l <<" " << r << " " << rn << " " << lx << " " << rx << "\n";
    if(rx < l || r < lx) return;
    if(l <= lx && rx <= r){
        if(pp){
            adj[u].push_back({idx[pp][rn], w});
        }else{
            adj[idx[pp][rn]].push_back({u, w});
        }
        return;
    }
    ll mid = (lx+rx)/2;
    add(pp, u, w, l, r, 2*rn, lx, mid);
    add(pp, u, w, l, r, 2*rn+1, mid+1, rx);
}
void solve(){
    cin >> n >> m >> id;
    a = n;
    id--;
    ll pw2 = 1;
    while(n > pw2){
        pw2 *= 2;
    }
    build(0, 1, 0, pw2-1);
    build(1, 1, 0, pw2-1);
    //cout << "ANJAI "<< endl;
    while(m--){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            b--; c--;
            adj[b].push_back({c, d});
        }else{
            cin >> b >> c >> d >> e;
            b--; c--; d--;
            if(a == 2){
                add(1, b, e, c, d, 1, 0, pw2-1);
            }else{
                add(0, b, e, c, d, 1, 0, pw2-1);
            }
        }
    }
    for(ll i = 0; i < 7*ukr; i++){
        dp[i] = 1e18;
    }
    dp[id] = 0;
    pq.push({0, id});
    while(!pq.empty()){
        babis rn = pq.top();
        //cout << rn.x << endl;
        pq.pop();
        if(rn.id == dp[rn.x]){
            for(auto i : adj[rn.x]){
                if(dp[i.first] > dp[rn.x]+i.second){
                    dp[i.first] = dp[rn.x]+i.second;
                    pq.push({dp[i.first], i.first});
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << (dp[i] == 1e18 ? -1 : dp[i]) << " ";
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

