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
int n, m, a, b, c, d, id, pt, pt2, tre = 0, tet = 0;
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
vector<int> v;
string s, t;
char ar[201][201];
int st[201][201][201];
int ot[201][201][201];
int vis[201][201];
queue<pair<int,int>> q;
bool debug = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool dfs(int rnx, int rny, int idx){
    if(idx == pt){
        st[rnx][rny][idx] = 2;
        q.push({rnx, rny});
        vis[rnx][rny] = 1;
        return 1; 
    }
    bool cek = 0;
    if(rnx+1 <= n && ar[rnx+1][rny] == s[idx]){
        if(!st[rnx+1][rny][idx+1]) cek |= dfs(rnx+1, rny, idx+1);
        else cek |= (st[rnx+1][rny][idx+1] == 2);
    }
    if(rnx-1 >= 1 && ar[rnx-1][rny] == s[idx]){
        if(!st[rnx-1][rny][idx+1]) cek |= dfs(rnx-1, rny, idx+1);
        else cek |= (st[rnx-1][rny][idx+1] == 2);
    }
    if(rny+1 <= m && ar[rnx][rny+1] == s[idx]){
        if(!st[rnx][rny+1][idx+1]) cek |= dfs(rnx, rny+1, idx+1);
        else cek |= (st[rnx][rny+1][idx+1] == 2);
    }
    if(rny-1 >= 1 && ar[rnx][rny-1] == s[idx]){
        if(!st[rnx][rny-1][idx+1]) cek |= dfs(rnx, rny-1, idx+1);
        else cek |= (st[rnx][rny-1][idx+1] == 2);
    }
    st[rnx][rny][idx] = 1+cek;
    return cek;
}
bool dfs2(int rnx, int rny, int idx){
    if(idx == pt2){
        ot[rnx][rny][idx] = 2;
        return 1; 
    }
    bool cek = 0;
    if(rnx+1 <= n && ar[rnx+1][rny] == t[idx]){
        if(!ot[rnx+1][rny][idx+1]) cek |= dfs2(rnx+1, rny, idx+1);
        else cek |= (ot[rnx+1][rny][idx+1] == 2);
    }
    if(rnx-1 >= 1 && ar[rnx-1][rny] == t[idx]){
        if(!ot[rnx-1][rny][idx+1]) cek |= dfs2(rnx-1, rny, idx+1);
        else cek |= (ot[rnx-1][rny][idx+1] == 2);
    }
    if(rny+1 <= m && ar[rnx][rny+1] == t[idx]){
        if(!ot[rnx][rny+1][idx+1]) cek |= dfs2(rnx, rny+1, idx+1);
        else cek |= (ot[rnx][rny+1][idx+1] == 2);
    }
    if(rny-1 >= 1 && ar[rnx][rny-1] == t[idx]){
        if(!ot[rnx][rny-1][idx+1]) cek |= dfs2(rnx, rny-1, idx+1);
        else cek |= (ot[rnx][rny-1][idx+1] == 2);
    }
    ot[rnx][rny][idx] = 1+cek;
    return cek;
}
void solve(){
    cin >> s;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
        }
    }
    cin >> s >> t;
    pt = s.length(); pt2 = t.length();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(ar[i][j] == s[0]){
                dfs(i, j, 1);
            }
            if(ar[i][j] == t[0]){
                dfs2(i, j, 1);
            }
        }
    }
    int ans = INT_MAX;
    for(int i = max(0, pt-pt2); i < pt; i++){
        bool cek = 0;
        int tmp = i;
        for(int j = 0; j < pt2; j++){
            if(tmp < pt){
                if(s[tmp] == t[j]){
                    tmp++;
                }else{
                    cek = 1; 
                    break;
                }
            }else break;
        }
        if(!cek){
            v.push_back(i);
        }
    }
    for(auto i : v){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                if(st[j][k][i+1] == 2 && ot[j][k][1] == 2){
                    //cout << i << " " << pt2 << "\n";
                    ans = min(ans, i+pt2);
                }
            }
        }
    }
    //cout << ans <<"\n";
    while(!q.empty()){
        auto[rnx, rny] = q.front();
        q.pop();
        //cout << rnx << " " << rny << " " << vis[rnx][rny]<< endl;
        if(rnx+1 <= n && !vis[rnx+1][rny]){
            vis[rnx+1][rny] = vis[rnx][rny]+1;
            q.push({rnx+1, rny});
        }
        if(rnx-1 >= 1 && !vis[rnx-1][rny]){
            vis[rnx-1][rny] = vis[rnx][rny]+1;
            q.push({rnx-1, rny});
        }
        if(rny+1 <= m && !vis[rnx][rny+1]){
            vis[rnx][rny+1] = vis[rnx][rny]+1;
            q.push({rnx, rny+1});
        }
        if(rny-1 >= 1 && !vis[rnx][rny-1]){
            vis[rnx][rny-1] = vis[rnx][rny]+1;
            q.push({rnx, rny-1});
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis[i][j] && ot[i][j][1] == 2){
                //cout << i << " " << j <<" "<< vis[i][j]<<"\n";
                ans = min(ans, pt+pt2+vis[i][j]-2);
            }
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
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

