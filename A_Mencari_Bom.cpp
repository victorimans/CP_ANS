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
vector<vector<pair<ll,ll>>> adj(5001);
string s;
ll dp[5001][101][2];
ll tmp[101][2];
ll anj[5001];
bool kck[5001];
void dfs(ll rn, ll par){
    //cout << rn << " " << par << "\n";
    for(auto i : adj[rn]){
        if(i.first == par) continue;
        dfs(i.first, rn);
    }
    for(auto i : adj[rn]){
        if(i.first == par) continue;
        for(int k = 0; k < 2; k++){
            for(int j = 0; j <= anj[rn]+anj[i.first]; j++){
                tmp[j][k] = 1e18;
            }
            for(int j = 1; j <= anj[i.first]; j++){
                dp[i.first][j][k] += (2-k)*i.second;
                //cout << dp[i.first][j][k] << endl;
            }
        }
        for(int j = 0; j <= anj[rn]; j++){
            for(int k = 0; k <= anj[i.first]; k++){
                tmp[j+k][1] = min({tmp[j+k][1], dp[rn][j][0]+dp[i.first][k][1], dp[rn][j][1]+dp[i.first][k][0]});
                tmp[j+k][0] = min(tmp[j+k][0], dp[rn][j][0]+dp[i.first][k][0]);
            }
        }
        anj[rn] += anj[i.first];
        for(int j = 0; j <= anj[rn]; j++){
            for(int k = 0; k < 2; k++){
                dp[rn][j][k] = tmp[j][k];
            }
        }
    }
}
void solve(){
    cin >> n >> m >> id;
    for(int i = 0; i < m; i++){
        cin >> a;
        anj[a] = 1;
    }
    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1, 1);
    /* for(int i = 1; i <= m; i++){
        cout << dp[1][i][0] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= m; i++){
        cout << dp[1][i][1] << " ";
    } */
    for(int i = m; i >= 0; i--){
        if(dp[1][i][1] <= id || dp[1][i][0] <= id){
            cout << i << "\n";
            return;
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

