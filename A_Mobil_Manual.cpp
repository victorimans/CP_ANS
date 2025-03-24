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
vector<pair<int,int>> v;
string s;
vector<pair<int,int>> nwv;
void solve(){
    n = read();
    for(int i = 0; i < n; i++){
        a = read(); b = read();
        v.push_back({a, b});
    }
    sort(all(v));
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(l == v[i].first){
            r = v[i].second;
        }else if(r < v[i].second){
            nwv.push_back({l, r});
            l = v[i].first; r = v[i].second;
        }
    }
    nwv.push_back({l, r});
    int ans = 0;
    int mi = INT_MAX, ma = -INT_MAX;
    m = read();
    for(int i = 0; i < m; i++){
        id = read();
        l = 1, r = nwv.size()-1;
        int res = 0;
        mi = min(mi, id);
        ma = max(ma, id);
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nwv[mid].first <= mi){
                res = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        //cout << nwv[res].first << " " <<  mi << " " << ma <<" "<< nwv[res].second << "\n";
        if(nwv[res].first <= mi && ma <= nwv[res].second){
            continue;
        }else{
            ans++;
            l = 1, r = nwv.size()-1;
            int res = 0;
            ma = mi = id; 
            while(l <= r){
                int mid = l + (r-l)/2;
                if(nwv[mid].first <= mi){
                    res = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            if(nwv[res].first <= mi && ma <= nwv[res].second){
                continue;
            }else{
                cout << -1 << "\n";
                return;
            }
        }
    }
    //cout << "anjai "<< endl;
    cout << ans << "\n";
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

