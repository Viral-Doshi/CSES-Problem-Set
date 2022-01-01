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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n==1){
        cout << "1";
    }
    if (n <= 3){
        cout << "NO  SOLUTION";
    }
    else{
        for(int i=2; i<=n; i+=2){
            cout << i << " ";
        }
        for(int i=1; i<=n; i+=2){
            cout << i << " ";
        }
    }
    return 0;
}

