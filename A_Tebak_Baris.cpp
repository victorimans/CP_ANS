#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
ll n, m, id;
vector<int> v;
vector<int> ans = {3, 0, 2, 5, 1, 4};
// 0 2 3 
vector<pair<int,int>> jwb;
int ask(vector<int> &tmp){
    cout << "? " << tmp.size() << " ";
    for(auto i : tmp){
        cout << i << " ";
    }
    cout << endl;
   /*  id = 0;
    for(int i = 1; i < tmp.size(); i++){
        if(ans[tmp[i-1]] > ans[tmp[i]]) id++;
    }
    cout << id << endl; */
    cin >> id;
    return id;
}
void rec(ll rn){
    if(rn == n){
        return;
    }
    vector<int> tmp;
    tmp.push_back(v[0]);
    tmp.push_back(rn);
    for(int i = 1; i < rn; i++){
        tmp.push_back(v[i]);
        tmp.push_back(v[0]);
        tmp.push_back(rn);
    }
    //cout << rn+1 << "\n";
    int sk = ask(tmp);
    sk = (sk-rn+1);
    if(sk == rn) sk = 0;
    else sk++;
    v.insert(v.begin()+sk, rn);
   /*  cout << "nw - > ";
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl; */
    rec(rn+1);
}
void solve(){
    cin >> n;
    if(n == 1){
        cout <<"! 0" << endl;
        return;
    }
    cout << "? 2 " << 0 << " " << 1 << endl;
    cin >> id;
    if(id){
        v.push_back(1);
        v.push_back(0);
    }else{
        v.push_back(0);
        v.push_back(1);
    }
    rec(2);
    cout << "! ";
    int cnt = 0;
    //cout << v.size() << "\n";
    for(auto i : v){
        //cout << i << " ";
        jwb.push_back({i, cnt++});
    }
    //cout << "\n";
    sort(all(jwb));
    for(auto i : jwb){
        cout << i.second << " ";
    }
    cout << endl;
}
/* 
0 1 2 3 4 5 
3 0 2 5 1 4

0 2 5 0 3
3 2 4 3 5

0 1 2
3 1 2
1 0
1 2 0 
kasus 1  a0 < a1 < a2
        v    v    
a0 > a2 > a1 > a0 > a2
= 2

kasus 2 a0 < a2 < a1
             v    
a0 > a2 > a1 > a0 > a2
= 1

kasus 3 a2 < a0 < a1
   v         v    v
a0 > a2 > a1 > a0 > a2
= 3

kasus 1 a0 < a1 < a2 < a3
        v    v         v    v       
a0 > a3 > a1 > a0 > a3 > a2 > a0 > a3
= 2
kasus 2 a0 < a1 < a3 < a2
        v    v              v    
a0 > a3 > a1 > a0 > a3 > a2 > a0 > a3
= 1
kasus 3 a0 < a3 < a1 < a2
        v              v    
a0 > a3 > a1 > a0 > a3 > a2 > a0 > a3
= 0
kasus 4 a3 < a0 < a1 < a2
   v         v    v         v    v 
a0 > a3 > a1 > a0 > a3 > a2 > a0 > a3
= 3
 */
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}

