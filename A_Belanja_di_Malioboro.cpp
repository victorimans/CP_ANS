#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 5e6+1;
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
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
string s;
vector<ll> v1;
vector<ll> v2;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
ll ar[ukr];
void isi(){
    for(int i = 0; i <= 2*m; i++){
        ar[i] = -1;
    }
}
void solve(){
    cin >> s;
    cin >> m >> n >> id;
    isi();
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(b == 1) v1.push_back(a);
        else v2.push_back(a);
    }
    sort(all(v1)); sort(all(v2));
    a = v1.size(); b = v2.size();
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            int rn = (v2[j]-v1[i]+m)%m;
            q.push({0, rn});
            q.push({0, (rn+m)%(2*m)});
            //cout << rn << " " << (rn+m)%(2*m) << endl;
        }
    }
    ll mi = LONG_LONG_MAX;
    if(a >= 2){
        mi = min({(v1[0]-v1[a-1]+m)%m, (v1[a-1]-v1[0]+m)%m, mi});
    }
    if(b >= 2){
        mi = min({(v2[0]-v2[b-1]+m)%m, (v2[b-1]-v2[0]+m)%m, mi});
    }
    for(int i = 1; i < a; i++){
        mi = min({(v1[i]-v1[i-1]+m)%m, (v1[i-1]-v1[i]+m)%m, mi});
    }
    for(int i = 1; i < b; i++){
        mi = min({(v2[i]-v2[i-1]+m)%m, (v2[i-1]-v2[i]+m)%m, mi});
    }
    m *= 2;
    while(!q.empty() && q.top().first < mi){
        auto rn = q.top();
        q.pop();
        if(ar[rn.second] == -1){
            ar[rn.second] = rn.first;
            q.push({rn.first+1, (rn.second+1)%m});
            q.push({rn.first+1, (rn.second-1+m)%m});
            //cout << (rn.second+1)%m << " " << (rn.second-1+m)%m << endl;
        }
    }
    m/=2;
    while(id--){
        cin >> a;
        a %= m;
        cout << (ar[a*2] == -1 ? mi : ar[a*2]) << "\n";
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

