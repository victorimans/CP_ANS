#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 5e5+1;
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
ll tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
string s;
ll dp[27][27]={0};
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        a = s.length();
        int de = s[0]-'a';
        int be = s[a-1]-'a';
        for(int i = 0; i < 26; i++){
            if(dp[i][de] != 0){dp[i][be] = max(dp[i][be],(ll)dp[i][de] + a);}
        }
        dp[de][be] = max(dp[de][be], (ll)a);
    }
    for(int i = 0; i < 26; i++){
        tot = max(tot, dp[i][i]);
    }
    cout << tot << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
    memset(dp, sizeof(dp), 0);
	while(t--) solve();
}

