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
vector<ll> v;
string s;
ll ar[ukr], br[ukr];
set<ll> st;
map<ll,ll> mp;
deque<ll> dq;
void solve(){
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> ar[i];
        ar[i] %= m;
        st.insert(ar[i]);
    }
    for(auto i : st){
       v.push_back(i); 
    }
    reverse(all(v));
    ll tot = 0, cnt = 0;
    for(ll i = 1; i <= n; i++){
        cin >> br[i];
        mp[ar[i]] += br[i];
        tot += br[i];
        cnt += br[i]*ar[i];
    }
    ll ans = cnt, pre = 0;
    //dq.push_back(m);
    //if()
    for(ll i = 0; i < v.size(); i++){
        ll sel = (ll)max((m-v[i])-1-pre, 0LL);
        pre += sel;
        cnt += tot*sel;
        while(!dq.empty() && dq.front()+pre >= m){
            cnt -= mp[dq.front()]*m;
            dq.pop_front();
        }
        dq.push_back(v[i]);
        ans = max(ans, cnt);
        //cout << cnt << " " << pre<< " " << v[i] << "\n";
    }
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

