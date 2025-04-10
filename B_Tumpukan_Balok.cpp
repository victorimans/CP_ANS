#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
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
vector<pair<ll,pair<int,int>>> v;
pair<ll,ll> seg[ukr*5];
ll pf[ukr*5];
void upd(ll k, ll u, ll rn, ll lx, ll rx){
    if(lx == rx){pf[rn] += u; return;}
    ll mid = (lx+rx)/2;
    if(k <= mid){
        upd(k, u, 2*rn, lx, mid);
    }else{
        upd(k, u, 2*rn+1, mid+1, rx);
    }
    pf[rn] = pf[2*rn] + pf[2*rn+1];
}
ll get2(ll l, ll r, ll rn, ll lx, ll rx){
    if(r < lx || l > rx){
        return 0;
    }
    if(l <= lx && rx <= r){
        return pf[rn];
    }
    ll mid = (lx+rx)/2;
    return  get2(l, r, 2*rn, lx, mid) + get2(l, r, 2*rn+1, mid+1, rx);
}
ll pw2 = 1;
pair<ll,ll> get(ll l, ll r, ll rn, ll lx, ll rx){
    if(r < lx || l > rx){
        return {LLONG_MAX, LLONG_MAX};
    }
    if(l <= lx && rx <= r){
        return seg[rn];
    }
    ll mid = (lx+rx)/2;
    pair<ll,ll> ki = get(l, r, 2*rn, lx, mid);
    pair<ll,ll> ka = get(l, r, 2*rn+1, mid+1, rx);
    if(ki.first < ka.first){
        return ki;
    }else return ka;
}
void rec(ll l, ll r){
    if(l > r) return;
    pair<ll,ll> gt = get(l, r, 1, 0, pw2-1);
    ll pp = get2(0, gt.second, 1, 0, pw2-1);
    gt.first -= pp;
    if(gt.first != 0){
        v.push_back({gt.first*(r-l+1), {l, r}});
        upd(l, gt.first, 1, 0, pw2-1);
        upd(r+1, -gt.first, 1, 0, pw2-1);
        rec(l, gt.second-1);
        rec(gt.second+1, r);
    }else{
        rec(l, gt.second-1);
        rec(gt.second+1, r);
    }
}
void solve(){
    cin >> n;
    while((n+2) > pw2){
        pw2 *= 2;
    }
    seg[pw2] = {LLONG_MAX, 0};
    seg[n+1+pw2] = {LLONG_MAX, n+1};
    for(int i = 1; i <= n; i++){
        cin >> seg[i+pw2].first;
        seg[i+pw2].second = i;
    }
    for(int i = pw2-1; i >= 1; i--){
        pair<ll,ll> ki = seg[i*2];
        pair<ll,ll> ka = seg[i*2+1];
        if(ki.first < ka.first){
            seg[i] = ki;
        }else seg[i] = ka;
    }
    v.push_back({0, {0, 0}});
    rec(1, n);
    // for(int i = 1; i <= n; i++){
    //     ll pp = get2(0, i, 1, 0, pw2-1);
    //     ll rn = seg[i+pw2].first-pp;
    //     if(rn == 0) continue;
    //     int j = n;
    //     while(i <= j){
    //         pair<ll,ll> dpt = get(i, j, 1, 0, pw2-1);
    //         ll gt = get2(0, dpt.second, 1, 0, pw2-1);
    //         dpt.first += gt;
    //         //cout << i << " " << j << " " << dpt.first << " " << dpt.second << "\n";
    //         if(dpt.first == 0){
    //             j = dpt.second-1;
    //             continue;
    //         }
    //         upd(i, -dpt.first, 1, 0, pw2-1);
    //         upd(j+1, dpt.first, 1, 0, pw2-1);
    //         v.push_back({dpt.first*(j-i+1), {i, j}});
    //         j = dpt.second-1;
    //     }
    // }
    cin >> m;
    n = v.size();
    for(int i = 1; i < n; i++){
        v[i].first += v[i-1].first;
    }
    while(m--){
        cin >> id;
        ll l = 0, r = n-1, res = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(v[mid].first >= id){
                r = mid-1;
                res = mid;
            }else{
                l = mid+1;
            }
        }
        id -= v[res-1].first;
        id--;
        id %= ((ll)v[res].second.second-v[res].second.first+1);
        cout << (ll)v[res].second.first+id << "\n";

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

