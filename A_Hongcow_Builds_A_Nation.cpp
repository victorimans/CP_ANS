#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e3+10;
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
ll tot = 0;
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
vector<vector<int>> adj(ukr);
vector<int> v;
string s;
int vis[ukr];
ll dfs(ll rn){
    vis[rn] = 1;
    tot++;
    ll tet = adj[rn].size();
    for(auto i : adj[rn]){
        if(!vis[i]){
            tet += dfs(i);
        }
    }
    return tet;
}
void solve(){
    cin >> n >> m >> id;
    for(int i = 0; i < id; i++){
        cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll mx = 0, ans = 0;
    for(auto i : v){
        tot = 0;
        ll totsem = dfs(i);
        totsem /= 2;
        mx = max(mx, tot);
        //cout << tot << " " << totsem << "\n";
        ans += (((tot)*(tot-1)/2)-totsem);
    }
    //cout << ans << "\n";
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        tot = 0;
        ll totsem = dfs(i);
        totsem /= 2;
        ans += (((mx+tot)*(mx+tot-1)/2) - ((mx)*(mx-1)/2) -totsem);
        //cout << tot << " " << mx << " "<< ans <<" "<<totsem<<" "<<(mx+tot)*(mx+tot-1)/2<< "\n";
        mx += tot;
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

