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
vector<pair<ll,ll>> v;
string s;
pair<ll,ll> dsu[ukr];
int cekies(int rn){
    if(rn == dsu[rn].first) return rn;
    return dsu[rn].first = cekies(dsu[rn].first);
}
void join(int a, int b){
    int ax = cekies(a);
    int bx = cekies(b);
    if(ax == bx) return;
    dsu[ax].first = bx;
    dsu[bx].second += dsu[ax].second;
}
vector<ll> idx[31];
void solve(){
    //memset(idx, -1, sizeof(idx));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> id;
        v.push_back({id, i});
    }
    for(int i = 0; i < n; i++){
        cin >> dsu[i].second;
        dsu[i].first = i;
    }
    sort(all(v));
    ll pp = (ll)(1ll << 30)-1;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < i; j++){
    //         if(((ll)v[i]^v[j]) > max(v[i],v[j])){
    //             join(i, j);
    //         }
    //     }
    // }
    // 543210
    // 000110 0
    // 100111 1
    // 001011 2
    // 111111 3
    // 000011 4
    // 100111 5
    // 000001 6
    // 101011 7
    for(int i = 0; i < n; i++){
        ll rn = (ll)v[i].first^pp;
        for(int j = 0; j < 30; j++){
            if(rn&(1LL << j)){
                //cout << "anjai" << j<< endl;
                if(!idx[j].empty()){
                    ll asem = idx[j].front();
                   
                    while(idx[j].size() > 1){
                        join(idx[j].back(), asem);
                        idx[j].pop_back();
                    }
                    //cout << idx[j] << " " << v[i].second << "\n";
                    join(asem, v[i].second);
                }
            }
        }
        ll asu = 0;
        /* for(int j = 29; j >= 0; j--){
            if(rn&(1LL << j)){
                cout << 1;
            }else cout << 0;
        }
        cout << "\n"; */
        //cout << "anjai" << endl;
        for(int j = 29; j >= 0; j--){
            if(v[i].first&(1LL << j)){
                asu = j;
                break;
            }
        }
        //cout << "anjai" << endl;
        //cout << asu << " <- " << i << "\n";
        idx[asu].push_back(v[i].second);
        //cout << "anjai" << endl;
    }
    for(int i = 0; i < n; i++){
        int rn = cekies(i);
        cout << dsu[rn].second << "\n";
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

