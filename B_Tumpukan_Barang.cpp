#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 5e5+10;
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
bool vis[ukr];
int dsu[ukr], val[ukr];
int cekies(int rn){
    if(rn == dsu[rn]) return rn;
    return dsu[rn] = cekies(dsu[rn]);
}
void join(int ax, int bx){
    int nwa = cekies(ax);
    int nwb = cekies(bx);
    if(val[nwa] < val[nwb]){
        dsu[nwa] = nwb;
        val[nwb] += val[nwa];
    }else{
        dsu[nwb] = nwa;
        val[nwa] += val[nwb];
    }
}
void solve(){
    /* ll ans = 0;
    while(n--){
        cin >> id;
        auto it = ms.lower_bound({id, LLONG_MAX});
        if(it == ms.end()){
            it = ms.upper_bound({id, id});
            if(it == ms.end()){
                ans++;
                ms.insert({id, id});
            }else{
                pair<int,int> rn = *it;
                if(rn.first == id) continue;
                if(rn.first == id+1){
                    ms.erase(rn);
                    ans -= (rn.second-rn.first+1)/2;
                    ans += (rn.second-rn.first)/2+1;
                    ms.insert({id, rn.second});
                }else{
                    ans++;
                    ms.insert({id,id});
                }
            }
        }else{
            pair<int,int> bwh =  *it;
            if(bwh.first <= id && id <= bwh.second) continue;
            if(bwh.second+1 == id){
                ans -= (bwh.second-bwh.first+1)/2;
                it = ms.upper_bound({id, id});
                if(it == ms.end()){
                    ans += (bwh.second-bwh.first)/2+1;
                    ms.insert({bwh.first, id});
                }else{
                    pair<int,int> rn = *it;
                    if(rn.first == id+1){
                        ms.erase(rn);
                        ans -= (rn.second-rn.first+1)/2;
                        ans += (rn.second-rn.first)/2+1;
                        ms.insert({id, rn.second});
                    }else{
                        ans++;
                        ms.insert({id,id});
                    }
                }
            }else{
                it = ms.upper_bound({id, id});
                if(it == ms.end()){
                    ans++;
                    ms.insert({id, id});
                }else{
                    pair<int,int> rn = *it;
                    if(rn.first == id) continue;
                    if(rn.first == id+1){
                        ms.erase(rn);
                        ans -= (rn.second-rn.first+1)/2;
                        ans += (rn.second-rn.first)/2+1;
                        ms.insert({id, rn.second});
                    }else{
                        ans++;
                        ms.insert({id,id});
                    }
                }
            }
        }
    } */
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < ukr; i++){
        dsu[i] = i;
        val[i] = 1;
        vis[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> id;
        if(vis[id]){
            cout << ans << " ";
            continue;
        }
        vis[id] = 1;
        if(vis[id-1] && vis[id+1]){
            int tot1 = val[cekies(id-1)];
            int tot2 = val[cekies(id+1)];
            ans -= (tot1+1)/2;
            ans -= (tot2+1)/2;
            ans += (tot1+tot2)/2+1;
            join(id-1, id);
            join(id, id+1);
        }else if(vis[id-1]){
            int tot1 = val[cekies(id-1)];
            ans -= (tot1+1)/2;
            ans += (tot1)/2+1;
            join(id-1, id);
        }else if(vis[id+1]){
            int tot1 = val[cekies(id+1)];
            ans -= (tot1+1)/2;
            ans += (tot1)/2+1;
            join(id+1, id);
        }else{
            ans++;
        }
        cout << ans << " ";
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

