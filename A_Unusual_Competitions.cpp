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
int n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
string s;
deque<char> dq;
void solve(){
    dq.clear();
    cin >> n >> s;
    if(n%2){
        cout << -1 << "\n";
        return;
    }
    int tota = 0, totb = 0;
    for(int i = 0; i < n; i++){
        if(dq.empty()){
            dq.push_back(s[i]);
        }else if(dq.back() == ')' && s[i] =='('){
            tota++;
            dq.pop_back();
        }else if(dq.back() == ')' && s[i] == ')'){
            dq.push_back(s[i]);
        }else if(dq.back() == '(' && s[i] == ')'){
            dq.pop_back();
        }else{
            dq.push_back(s[i]);
        }
    }
    if(!dq.empty()){
        cout << -1 << "\n";
    }else{
        cout << tota*2 << "\n";
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
