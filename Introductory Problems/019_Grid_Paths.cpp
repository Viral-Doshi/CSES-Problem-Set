#include<bits/stdc++.h>
#include<chrono>
using namespace std;
// ifstream fin ("test.txt");
// #define cin fin
#define ll long long
#define ld long double
#define all(v) (v).begin(), (v).end()
#define fshow(v) for(auto& x__x: v) cout << x__x << " "; cout << '\n'
#define finp(v,n) v.resize(n); for(int i=0;i<n;i++) cin>>v[i]
#define fsum(v) accumulate(all(v), 0LL)
#define fsort(v) sort(all(v))
#define fdsort(v) sort(all(v), greater<ll>())
#define fmax(v) *max_element(all(v))
#define fmin(v) *min_element(all(v))

struct mhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    uint64_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
string s;
int ans = 0, posx = 0, posy = 0;
vector<vector<char>> visited(7, vector<char>(7,false));

bool is_unreachable(int px, int py){
    if (px < 0 || px > 6 || py < 0 || py > 6 || visited[px][py])
        return true;
    return false;
}
bool is_goal(int px, int py){
    if (px == 0 && py == 6)
        return true;
    return false;
}
bool check_splits(int px, int py){
    if (is_unreachable(px, py+1) && is_unreachable(px, py-1) && !is_unreachable(px+1, py) && !is_unreachable(px-1, py))
        return true;
    if (!is_unreachable(px, py+1) && !is_unreachable(px, py-1) && is_unreachable(px+1, py) && is_unreachable(px-1, py))
        return true;
    return false;
}
bool check_void(int px, int py){
    int cnt = 0;
    if (is_unreachable(px,py) || is_goal(px,py))
        return false;
    if (is_unreachable(px-1,py))
        cnt ++;
    if (is_unreachable(px+1,py))
        cnt ++;
    if (is_unreachable(px,py-1))
        cnt ++;
    if (is_unreachable(px,py+1))
        cnt ++;

    if (cnt == 3 ||cnt == 4)
        return true;
    return false;
}

void findPaths(int i, int posx, int posy){
    if (is_unreachable(posx, posy))
        return;
    if (i == 48){
        if (posx == 0 && posy == 6){
            ans++;
        }
        return;
    }
    if (posx == 0 && posy == 6){
        return;
    }
    if (posx + 6 -posy > 48 - i){
        return;
    }
    if (check_void(posx-1, posy-1) || check_void(posx-1, posy+1) ||check_void(posx+1, posy-1) ||check_void(posx+1, posy+1)){
        return;
    }
    if (check_splits(posx, posy))
        return;
    visited[posx][posy] = true;

    if (s[i] != '?'){
        int px = posx, py = posy;
        if (s[i] == 'R')
            px++;
        else if (s[i] == 'L')
            px--;
        else if (s[i] == 'D')
            py++;
        else if (s[i] == 'U')
            py--;

        if (px < 0 || px > 6 || py < 0 || py > 6){
            visited[posx][posy] = false;
            return;
        }
        findPaths(i+1, px, py);
    }

    else{
        findPaths(i+1, posx+1, posy);
        findPaths(i+1, posx, posy+1);
        findPaths(i+1, posx-1, posy);
        findPaths(i+1, posx, posy - 1);
    }
    visited[posx][posy] = false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    findPaths(0,0,0);
    cout << ans;
}

