#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int x, y, rx, ry;
int memo[1010][1010];
void solve(){
    cin >> s;
    cin >> x >> y >> rx >> ry;
    x++; y++;
    memo[x][y] += 1;
    memo[rx+1][y] += -1;
    memo[rx+1][ry+1] += 1;
    memo[x][ry+1] += -1;
    cin >> x >> y >> rx >> ry;
    x++; y++;
    memo[x][y] += 1;
    memo[rx+1][y] += -1;
    memo[rx+1][ry+1] += 1;
    memo[x][ry+1] += -1;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            memo[i][j] += memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1];
            if(memo[i][j] == 2){
                cout << "SENGKETA\n";
                return;
            }
        }
    }
    cout << "DAMAI\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}