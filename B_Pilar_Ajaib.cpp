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
ll n, m, a, b, c, d, xs, ys, xf, yf;
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
vector<pair<pair<ll,ll>, ll>> v1;
vector<pair<pair<ll,ll>,ll>> v2;
vector<vector<ll>>adj(ukr);
vector<vector<ll>>adj2(ukr);
string s;
ll ar[ukr];
ll dp[ukr][2];
priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>>pq;
void dfs(ll rn, ll par){
    cout << rn << "\n";
    for(auto i : adj[rn]){
        if(i == par) continue;
        dfs(i, rn);
    }
}
void solve(){
    cin >> n >> xs >> ys >> xf >> yf;
    v1.push_back({{xs, xs}, 0});
    v1.push_back({{xf, xf}, n+1});
    v2.push_back({{ys, ys}, 0});
    v2.push_back({{yf, yf}, n+1});
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c >> ar[i];
        v1.push_back({{a-c, a+c}, i});
        v2.push_back({{b-c, b+c}, i});
        dp[i][0] = dp[i][1] = 1e18;
    }
    dp[n+1][0] = dp[n+1][1] = ar[0] = ar[n+1] = dp[0][1] = 1e18;
    sort(all(v1)); sort(all(v2));
    ll r = v1[0].first.second, tt = v1[0].second;
    for(int i = 1; i < v1.size(); i++){
        auto [rg, idx] = v1[i];
        if(rg.first <= r){
            adj2[tt].push_back(idx);
            adj2[idx].push_back(tt);
            if(rg.second > r){
                tt = idx;
                r = rg.second;
            }
        }else{
            r = rg.second;
            tt = idx;
        }
    }
    r = v2[0].first.second, tt = v2[0].second; 
    for(int i = 1; i < v2.size(); i++){
        auto [rg, idx] = v2[i];
        if(rg.first <= r){
            adj[tt].push_back(idx);
            adj[idx].push_back(tt);
            if(rg.second > r){
                tt = idx;
                r = rg.second;
            }
        }else{
            r = rg.second;
            tt = idx;
        }
    }
    dp[0][0] = 0;
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        auto[val, rn] = pq.top();
        pq.pop();
        if(dp[rn.first][rn.second] == val){
            if(rn.second){
                for(auto i : adj[rn.first]){
                    if(dp[i][0] > dp[rn.first][1] + ar[rn.first]){
                        dp[i][0] = dp[rn.first][1] + ar[rn.first];
                        pq.push({dp[i][0], {i, 0}});
                    }
                }
                for(auto i : adj2[rn.first]){
                    if(dp[i][1] > dp[rn.first][1]){
                        dp[i][1] = dp[rn.first][1];
                        pq.push({dp[i][1], {i, 1}});
                    }
                }
            }else{
                for(auto i : adj[rn.first]){
                    if(dp[i][0] > dp[rn.first][0]){
                        dp[i][0] = dp[rn.first][0];
                        pq.push({dp[i][0], {i, 0}});
                    }
                }
                for(auto i : adj2[rn.first]){
                    if(dp[i][1] > dp[rn.first][0] + ar[rn.first]){
                        dp[i][1] = dp[rn.first][0] + ar[rn.first];
                        pq.push({dp[i][1], {i, 1}});
                    }
                }
            }
        }
    }
    if(dp[n+1][0] == 1e18 && dp[n+1][1] == 1e18){
        cout << -1;
        return;
    }
    cout << min(dp[n+1][0], dp[n+1][1]);
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

