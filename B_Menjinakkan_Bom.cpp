#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+10;
const ll md = 1e9+7;
string s;
short n, m, id;
vector<short> v;
bool ask(short rn){
    cout << rn << endl;
    cin >> s;
    return (s == "BIP");
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    cin >> n >> m >> id;
    v.push_back(0);
    for(short i = 1; i <= n/2; i++)v.push_back(i);
    for(short i = n/2; i >= 1; i--)v.push_back(i);
    for(short i = n/2+1; i <= n; i++)v.push_back(i);
    for(short i = n; i >= n/2+1; i--)v.push_back(i);
    for(short i = 1; i <= n/2; i++)v.push_back(i);
    for(short i = n/2; i >= 1; i--)v.push_back(i);
    id = v.size();
    short cnt = 0;
    short idx[2];
    for(short i = 1; i < id; i++){
        if(ask(v[i])){
            idx[cnt++] = i;
            //cout << cnt << "\n";
            if(cnt == 2) break;
        }
    }
    short ans = 0;
    for(short i = 0; i < n; i++){
        if(idx[0]-i >= 1 && idx[1]-i >= 1 && v[idx[0]-i] == v[idx[1]-i]){
            ans = v[idx[1]-i];
            break;
        }
    }
    for(short i = 1; i <= 2*n; i++){
        ask(ans);
    }
}