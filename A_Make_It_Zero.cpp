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
int n, m, a, b, c, d, id, pat;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<pair<int,int>> v;
ll ar[101];
int vis[101][101][9];
bool rec(ll rnx, ll rny, ll id, ll lst){
    //cout << rnx << " " << rny << " " <<id << " " << lst  << endl;
    if(lst == 0 && rnx == rny+1){
        cout << v.size() << "\n";
        for(auto i : v){
            cout << i.first << " " << i.second << "\n";
        }
        return true;
    }
    if(vis[rnx][rny][id] == pat) return false;
    if(id == 8) return false;
    vis[rnx][rny][id] = pat;
    ll nwx = lst;
    for(int i = rnx; i <= rny; i++){
        lst ^= ar[i];
        if((i-rnx)%2){
            v.push_back({rnx, i});
            if(rec(i+1, rny, id+1, 0)){
                return true;
            }
            v.pop_back();
        }else{
            v.push_back({rnx, i});
            if(rec(i+1, rny, id+1, lst)){
                return true;
            }
            v.pop_back();
        }
    }
    return false;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    if(n%2 == 0){
        cout << 2 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
        return;
    }else{
        cout << 4 << "\n";
        cout << 1 <<" "<< n-1 << "\n";
        cout << 1 <<" "<< n-1 << "\n";
        cout << n-1 << " " << n << "\n";
        cout << n-1 << " " << n << "\n";
    }
    /*  */
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        pat = i;
        solve();
    }
}

