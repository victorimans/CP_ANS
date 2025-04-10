#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+10;
const ll md = 1e9+7;
map<ll, char> mp; 
priority_queue<ll,vector<ll>, greater<ll>>pq;
ll n, m, a, b, c, d, id;
string s;
string rec(int rn){
    if(rn == 2){
        return "x";
    }
    if(rn == 3){
        return "!";
    }
    if(rn == 4){
        return "+";
    }
    if(rn%2){
        return rec(rn-3)+"+";
    }else{
        return rec(rn/2)+"x";
    }
}
vector<char> ans;
void solve(){
    cin >> n;
    while(1){
        if(n == 2){
            ans.push_back('x');
            break;
        }
        if(n == 3){
            ans.push_back('!');
            break;
        }
        if(n == 4){
            ans.push_back('+');
            break;
        }
        if(n%2){
            ans.push_back('+');
            n -= 3;
        }else{
            ans.push_back('x');
            n/=2;
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans[0] == '!'){
        cout << "-";
    }else{
        for(auto i : ans){
            cout << i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        /* for(int i = 2; i <= 100; i++){
            n = i; */
            solve();
        //}
    }
} 