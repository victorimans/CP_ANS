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
char ar[100][100];
queue<pair<int,int>> q;
bool cek(ll x, ll y){
    if(0 < x && x <= n && 0 < y && y <= m && ar[x][y] == '.'){
        return 1;
    }
    return 0;
}
void rec(ll x, ll y, ll rn){
    if(rn == id){
        a = x;
        b = y;
        return;
    }
    if(s[rn] == 'U' && cek(x-1, y)){
        rec(x-1, y, rn+1);
    }else if(s[rn] == 'L' && cek(x, y-1)){
        rec(x, y-1, rn+1);
    }else if(s[rn] == 'D'&& cek(x+1,y)){
        rec(x+1, y, rn+1);
    }else if(s[rn] == 'R' && cek(x, y+1)){
        rec(x, y+1, rn+1);
    }else{
        rec(x, y, rn+1);
    }
}
void solve(){
    cin >> n >> m;
    cin >> a >> b;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
        }
    }
    cin >> s;
    id = s.length();
    rec(a, b, 0);
    cout << a << " " << b << "\n";
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

