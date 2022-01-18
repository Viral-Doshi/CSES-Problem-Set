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
vector<ll> dp;

ll f1(int n){
    for (int i= 1; i<=n; i++){
        for(int j= 1; j<=6 && i-j >= 0; j++){
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    return dp[n];
}

ll f2(int n){
    for (int i=1; i<7; i++)
        dp[i] = pow(2, i-1);
    for (int i=7; i<=n; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] +dp[i-5] + dp[i-6]) % MOD;
    // fshow(dp);
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    dp.resize(n+1);
    dp[0] = 1;    
    cout << f2(n);
    return 0;
}

