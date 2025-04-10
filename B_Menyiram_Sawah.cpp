#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n, m, id, x, y, rx, ry;
int ar[1002][1002];
int vis[1001][1001];
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};
int pf[1002];
int sf[1002];
bool cekies(int rnx, int rny){
    if(x <= rnx && rnx <= rx && y <= rny && rny <= ry && !vis[rnx][rny]){
        return 1;
    }
    return 0;
}
void dfs(int rnx, int rny){
    vis[rnx][rny] = 1;
    for(int i = 0; i < 4; i++){
        int nw = rnx + mx[i];
        int ny = rny + my[i];
        if(ar[nw][ny] < ar[rnx][rny] && cekies(nw, ny)){
            dfs(nw, ny);
        }
    }
}
void isi(){
    for(int i = x; i <= rx; i++){
        for(int j = y; j <= ry; j++){
            vis[i][j] =  0;
        }
    }
}
bool jwb(){
    for(int i = x; i <= rx; i++){
        for(int j = y; j <= ry; j++){
            if(!vis[i][j]) return 0;
        }
    }
    return 1;
}
void solve(){
    cin >> s;
    cin >> n >> m >> id;
    if(n == 1){
        for(int i = 1; i <= m; i++){
            cin >> ar[1][i];
        }
        ar[1][0] = 1e9+7;
        for(int i = 1; i <= m; i++){
            pf[i] = pf[i-1] + (ar[1][i] > ar[1][i-1]);
            sf[i] = sf[i-1] + (ar[1][i] < ar[1][i-1]);
        }
        while(id--){
            cin >> x >> y >> rx >> ry;
            if(sf[ry]-sf[y] == ry-y){
                cout << "Kiri Atas\n";
                continue;
            }
            //cout << pf[ry] << " " << pf[y] << " " << ry << " " << y<<"\n";
            if(pf[ry]-pf[y] == ry-y){
                cout << "Kanan Bawah\n";
                continue;
            }
            cout << "Tidak Mungkin\n";
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
        }
    }
    for(int i = 1; i <= id; i++){
        cin >> x >> y >> rx >> ry;
        isi();
        dfs(x, y);
        if(jwb()){
            cout << "Kiri Atas\n"; 
            continue;;
        }
        isi();
        dfs(rx, ry);
        if(jwb()){
            cout << "Kanan Bawah\n"; 
            continue;;
        }
        cout << "Tidak Mungkin\n"; 
    }

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