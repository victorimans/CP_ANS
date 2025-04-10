#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define here cout << "anjai" << endl;
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
vector<vector<int>> adj(ukr);
vector<vector<pair<int,int>>> hub(ukr);
vector<pair<int,int>> v;
string s;
int chld[ukr], blg[ukr], wktu[ukr], cnt = 0, pp = 0;
int dfs(int rn){
    pp++;
    chld[rn] = 1;
    if(adj[rn].size() == 0){
        blg[rn] = cnt;
        wktu[rn] = pp;
        return cnt++;
    }
    int ma = 0, dd = -1;
    wktu[rn] = pp;
    for(auto i : adj[rn]){
        int idx = dfs(i);
        if(ma < chld[i]){
            ma = chld[i];
            dd = idx;
        }
    }
    chld[rn] += ma;
    blg[rn] = dd;
    return dd;
}
void solve(){
    cin >> n >> m >> id;
    for(int i = 2; i <= n; i++){
        cin >> a;
        adj[a].push_back(i);
    }
    dfs(1);
    //here
    for(int i = 1; i <= n; i++){
        hub[blg[i]].push_back({wktu[i],i});
    }
    ll ma = 0;
    for(int i = 0; i < cnt; i++){
        sort(all(hub[i]));
        ll sz = hub[i].size();
        ma += (sz*(sz-1))/2;
        v.push_back({sz, i});
    }
    sort(all(v));
    //cout << ma << "\n";
    //here
    if(ma < m){
        cout << "TIDAK";
        return;
    }
    cout << "YA\n";
    if(id){
        cnt = 1;
        //here
        for(int i = v.size()-1; i >= 0; i--){
            ll pt = (ll)v[i].first*((ll)v[i].first-1)/2;
            if(m == 0){
                for(int j = 0; j < v[i].first; j++){
                    wktu[hub[v[i].second][j].second] = cnt++; 
                }
            }else if(m >= pt){
                m -= pt;
                for(int j = v[i].first-1; j >= 0; j--){
                    wktu[hub[v[i].second][j].second] = cnt++; 
                }
            }else{
                ll l = 0, r = v[i].first, res = -1;
                while(l <= r){
                    ll mid = l + (r-l)/2;
                    if(mid*(mid-1)/2 <= m){
                        l = mid+1;
                        res = mid;
                    }else{
                        r = mid-1;
                    }
                }
               // here
                m -= res*(res-1)/2;
                //cout << m << " " << res << "\n";
                for(int j = res-1; j >= 0; j--){
                    wktu[hub[v[i].second][j].second] = cnt++;
                }
                for(int j = res; j < v[i].first; j++){
                    wktu[hub[v[i].second][j].second] = cnt++;
                }
                /* for(int j = 1; j <= n;j++){
                    cout << wktu[j] << " ";
                }
                cout << endl; */
                for(int j = res; m; m--){
                    swap(wktu[hub[v[i].second][j].second], wktu[hub[v[i].second][j-1].second]);
                    j--;
                }
            }
        }
        for(int i = 1; i <= n;i++){
            cout << wktu[i] << " ";
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

