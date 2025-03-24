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
    ll x, pp, a, b, c, d;
    bool operator <(const babi &other) const{
        return x < other.x;
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
string s;
priority_queue<babi> pq;
ll ar[21];
int freq[101][21];
ll hit(ll ax, ll bx, ll cx, ll dx){
    return (ar[ax]|ar[bx]|ar[cx]|ar[dx]);
}
ll hit2(ll ax, ll bx, ll cx, ll dx){
    return (1 << ax)|(1 << bx)|(1 << cx)|(1 << dx);
}
ll hit3(ll ax, ll bx, ll cx){
    return (1 << ax)|(1 << bx)|(1 << cx);
}
int dp[1 << 20][2];
void solve(){
    cin >> n >> m;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    for(int i = 0; i < m; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            id = s[j]-'0';
            if(id)ar[i] += (1LL << j);
        }
        //cout << ar[i] << "\n";
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> id;
        if(id == 1){
            cin >> id;
            id--;
            freq[cnt][id]++;
        }else{
            cnt++;
        }
    }
    memset(dp, -1, sizeof(dp));
    ll rn = hit(a, b, c, d);
    ll asu = hit2(a, b, c, d);
    //cout << asu << "\n";
    dp[asu][0] = 0;
    for(int i = 0; i < m; i++){
        if(rn&(1LL << i)){
            dp[asu][0] += freq[0][i]; 
        }
    }
    //cout << dp[asu][0] << "\n";
    for(int i = 1; i <= cnt; i++){
        vector<int> v(1 << m, -1);
        for(int j = 0; j < m; j++){
            for(int k = j+1; k < m; k++){
                for(int z = k+1; z < m; z++){
                    for(int x = z+1; x < m; x++){
                        dp[hit2(j, k, z, x)][i%2] = dp[hit2(j, k, z, x)][(i+1)%2];
                        v[hit3(j, k, x)] = max(dp[hit2(j, k, z, x)][(i+1)%2],v[hit3(j, k, x)]);
                        v[hit3(j, k, z)] = max(dp[hit2(j, k, z, x)][(i+1)%2],v[hit3(j, k, z)]);
                        v[hit3(z, k, x)] = max(dp[hit2(j, k, z, x)][(i+1)%2],v[hit3(z, k, x)]);
                        v[hit3(j, z, x)] = max(dp[hit2(j, k, z, x)][(i+1)%2],v[hit3(j, z, x)]);
                    }
                }
            }
        }
        for(int j = 0; j < m; j++){
            for(int k = j+1; k < m; k++){
                for(int z = k+1; z < m; z++){
                    for(int x = z+1; x < m; x++){
                        ll rn = hit2(j, k, z, x);
                        int tot = 0;
                        ll pp = hit(j, k, z, x);
                        for(int y = 0; y < m; y++){
                            if(pp&(1 << y)){
                                tot += freq[i][y];
                            }
                        }
                        if(v[hit3(j, k, x)] != -1) {
                            dp[rn][i%2] = max(dp[rn][i%2], tot+v[hit3(j, k, x)]);
                        }
                        if(v[hit3(j, k, z)] != -1) {
                            dp[rn][i%2] = max(dp[rn][i%2], tot+v[hit3(j, k, z)]);
                        }
                        if(v[hit3(j, z, x)] != -1) {
                            dp[rn][i%2] = max(dp[rn][i%2], tot+v[hit3(j, z, x)]);
                        }
                        if(v[hit3(z, k, x)] != -1) {
                            dp[rn][i%2] = max(dp[rn][i%2], tot+v[hit3(z, k, x)]);
                        }
                        //cout << j << " " << k << " " << z << " " << x << " " << dp[rn][i%2] << "\n";
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < m; j++){
        for(int k = j+1; k < m; k++){
            for(int z = k+1; z < m; z++){
                for(int x = z+1; x < m; x++){
                    ans = max(ans, dp[hit2(j, k, z, x)][cnt%2]);
                }
            }
        }
    }
    cout << ans;
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

