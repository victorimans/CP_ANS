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
vector<vector<pair<int,int>>> adj(ukr);
string s;
int dp[101];
void dfs(int rn){
    for(auto i : adj[rn]){
        if(dp[i.first] == -1){
            dp[i.first] = dp[rn]+i.second;
            dfs(i.first);
        }
    }
}
void solve(){
    cin >> s;
    cin >> n;
    for(int i = 1; i <= (n-1)*n/2; i++){
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        dp[a] = 0;
        dfs(a);
        if(dp[b] == -1){
            cout << "PASS" << endl;
            cin >> s;
            if(s == "SERI"){
                adj[a].push_back({b, 0});
                adj[b].push_back({a, 0});
            }else{
                id = stoi(s);
                cin >> s;
                if(id == a){
                    adj[a].push_back({b, 1});
                    adj[b].push_back({a, 2});
                }else{
                    adj[a].push_back({b, 2});
                    adj[b].push_back({a, 1});
                }
            }
        }else{
            if(dp[b]%3 == 0){
                cout << "SERI" << endl;
            }else if(dp[b]%3 == 1){
                cout << a << " MENANG"<< endl; 
            }else{
                cout << b << " MENANG" << endl;
            }
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

