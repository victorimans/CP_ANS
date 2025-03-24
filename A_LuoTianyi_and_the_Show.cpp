#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e5+1;
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
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
int ar[ukr];
ll pkt(ll y, ll z){
    if(z == 0) return 1;
    ll newy = pkt(y, z/2)%md;
    if(z%2){
        return (ll)((((ll)newy*newy)%md)*y)%md;
    }else{
        return (ll)(newy*newy)%md;
    }
}
void solve(){
    cin >> n >> m;
    int totl = 0, totr = 0, tot= 0;
    for(int i = 1; i <= n; i++){
        cin >> id;
        if(id == -1){
            totl++;
        }else if(id == -2){
            totr++;
        }else if(ar[id] == 0 && id <= m){
            ar[id]++;
            v.push_back(id);
        }
    }
    sort(all(v));
    int id = v.size(), sisa = m-v.size(), ma = max(totl, totr);
    tot += id;
    for(int i = 0; i < id; i++){
        int sem = min(v[i]-(i+1), totl);
        int sem2 = min(sisa-v[i]+(i+1), totr);
       // cout << sem << " " << sem2 << endl;
        ma = max(ma, sem+sem2);
    }
    cout << min(tot+ma, (int)m) << "\n";
    for(int i = 1; i <= m; i++){
        ar[i] = 0;
    }
    v.clear();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

