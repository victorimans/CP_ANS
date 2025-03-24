#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int ukr = 1e6+10;
const ll md = 1e9+7;
ll n, m, t, id, a, b;
vector<ll> x, y;
int vis[ukr];
int asu[ukr];
vector<pair<pair<int,int>,int>> w;
vector<pair<pair<int,int>,int>> s;
bool cek(ll rn){
    ll l = 0, r = 0;
    for(int i = 0; i < t; i++){
        vis[i] = 0;
    }
    set<pair<int,int>> st;
    for(int i = 0; i < n; i++){
        asu[i] = 0;
        st.insert({x[i], i});
    }
    int idx1 = t-1, idx2 = t-1;
    while(idx1 >= 0){
        int ss = s[idx1].first.first;
        int ww = s[idx1].first.second;
        int idx = s[idx1].second;
        if(vis[idx]){
            idx1--;
            continue;
        }
        auto it = st.lower_bound({ww, -1});
        if(it != st.end()){
            vis[idx] = 1;
            asu[it->second]++;
            if(asu[it->second] == rn){
                st.erase(it);
            }
        }
        idx1--;
    }
    st.clear();
    for(int i = 0; i < m; i++){
        asu[i] = 0;
        st.insert({y[i], i});
    }
    while(idx2 >= 0){
        int ss = w[idx2].first.second;
        int ww = w[idx2].first.first;
        int idx = w[idx2].second;
        if(vis[idx]){
            idx2--;
            continue;
        }
        auto it = st.lower_bound({ss, -1});
        if(it != st.end()){
            vis[idx] = 1;
            asu[it->second]++;
            if(asu[it->second] == rn){
                st.erase(it);
            }
        }
        idx2--;
    }
    for(int i = 0; i < t; i++){
        //cout << vis[i] << " " << rn << " " << i << "\n";
        if(vis[i] == 0){
            return false;
        }
    }
    return true;
}
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>, int> b){
    if(a.first.first == b.first.first){
        return a.first.second > b.first.second;
    }
    return a.first.first < b.first.first;
}
void solve(){
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        cin >> id;
        x.push_back(id-1);
    }
    for(int i = 0; i < m; i++){
        cin >> id;
        y.push_back(id-1);
    }
    sort(all(x)); sort(all(y));
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        w.push_back({{a, b}, i});
        s.push_back({{b, a}, i});
    }
    sort(all(w), cmp); sort(all(s), cmp);
    int l = 1, r = t+1, ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(cek(mid)){
            //cout << "anjai" << endl;
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
    /* 
    3 2 10
    6 2 9
    4 7
    4 6
    8 5
    2 3
    7 9
    1 8
    5 1
    3 3
    8 7
    7 6
    10 5
    
     */
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ct = 1;
    //cin >> t;
    while(ct--){
        solve();
    }
}