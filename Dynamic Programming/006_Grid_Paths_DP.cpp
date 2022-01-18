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
#define MOD 1000000007

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
vector<string> maze;
int n;
vector<vector<ll>> memo;

bool oob(int px, int py){
    if (px < 0 || px > n-1 || py < 0 || py > n-1)
        return true;
    return false;
}

ll findpath(int px, int py){
    // cout << 1;
    if (oob(px,py))
        return 0;
    if (maze[px][py] == '*'){
        memo[px][py] = 0;
        return 0;
    }
    if (!px && !py)
        return 1;
    if (memo[px][py] != -1 )
        return memo[px][py];
    
    memo[px][py] = (findpath(px-1,py) + findpath(px,py-1)) % MOD;
    return memo[px][py];
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    maze.resize(n);
    memo = vector<vector<ll>>(n, vector<ll>(n,-1));
    for (int i=0; i<n; i++){
        cin >> maze[i];
    }
    memo[0][0] = 1;
    cout << findpath(n-1,n-1);

    return 0;
}