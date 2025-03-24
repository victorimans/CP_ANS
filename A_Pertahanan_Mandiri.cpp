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
vector<int> v;
string s;
ll dp[3010][3010][2];
ll pf[3010][3010][2];
ll pf2[3010][3010][2];
int lsta = 0, lstb = 0;
void solve(){
    cin >> n >> m >> id;
    cin >> s;
    pf[1][0][0] = pf[1][0][1] = pf2[1][0][1] = pf2[1][0][0] = 1;
    for(int i = 2; i <= n+1; i++){
        for(int j = 0; j <= id; j++){
            if(s[i-2] == 'A' || s[i-2] == '?'){
                dp[i][j][0] = pf[i-1][j][1] - pf[max(max(i-m, lstb), 0)][j][1] + md;
                if(lstb <= i-m && j > 0){
                    if(i-m-lstb < j){
                        dp[i][j][0] += pf2[i-m][j-1][1]-pf2[lstb][j-1-((i-m)-lstb)][1]+md;
                    }else{
                        dp[i][j][0] += pf2[i-m][j-1][1];
                    }
                }
                dp[i][j][0] %= md;
            }
            if(s[i-2] == 'B' || s[i-2] == '?'){
                dp[i][j][1] = pf[i-1][j][0]-pf[max(max(i-m, lsta), 0)][j][0] + md;
                if(lsta <= i-m && j > 0){
                    if(i-m-lsta < j){
                        dp[i][j][1] += pf2[i-m][j-1][0]-pf2[lsta][j-1-((i-m)-lsta)][0]+md;
                    }else{
                        dp[i][j][1] += pf2[i-m][j-1][0];
                    }
                }
                dp[i][j][1] %= md;
            }
            if(s[i-2] == 'A') lsta = i-1;
            if(s[i-2] == 'B') lstb = i-1;
            pf[i][j][0] = (pf[i-1][j][0] + dp[i][j][0])%md;
            pf[i][j][1] = (pf[i-1][j][1] + dp[i][j][1])%md;
            pf2[i][j][0] = (pf2[i-1][j-1][0] + dp[i][j][0])%md;
            pf2[i][j][1] = (pf2[i-1][j-1][1] + dp[i][j][1])%md;
        }
    }
    cout << (dp[n+1][id][0]+dp[n+1][id][1])%md;
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

