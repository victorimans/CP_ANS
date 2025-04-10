#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 3e5+1;
int read() {
    int _ = 0; bool __=0;
    register char ___ = getchar();
    while(___ == ' ' or ___ =='\n') ___ =getchar();
    if(___=='-'){__ = 1; ___ = getchar();}
    while(___ >= '0' and ___ <='9') { _ = (_<<3)+(_<<1)+___-'0'; ___ = getchar();}
    if(__) _*=-1;
    return _;
}   
void print(int _) {
    if (_ < 0) {putchar('-');_ = -_;}
    int __ = 0, ___[10];
    if (_ == 0) {putchar('0');return;}
    while (_ > 0) {___[__++] = _ % 10; _/=10;}
    while (__ > 0) {putchar('0' + ___[--__]);}
}
void File_Work(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
int n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
pair<int,int> ar[ukr];
string s;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ar[i].first;
        ar[i].second = i+1;
        if(ar[i].first%m == 0){
            ar[i].first = m;
            continue;
        }
        ar[i].first = (ar[i].first%m);
    }   
    sort(ar, ar+n, cmp);
    for(int i = 0; i < n; i++){
        cout << ar[i].second << " ";

    }
    cout << "\n";
    /* 
1 2 
1 2 
1 2 
1 2 
1 2 
2 1 
2 1 
2 1 
1 2 
1 2 
2 1 
2 1 
1 2 

1 2 
1 2 
1 2 
1 2 
1 2 
2 1 
2 1 
1 2 
2 1 
1 2 
1 2 
2 1 
2 1
     */
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    	int t =1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

