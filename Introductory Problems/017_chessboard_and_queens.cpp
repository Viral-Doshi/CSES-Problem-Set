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

vector<string> board, bd;
int num = 0;

bool isSafe(int row, int col){
    if (board[row][col] == '*')
        return false;
    // horizontal
    for (int i = 0; i < col; i++){
        if (board[row][i] == 'Q')
            return false;
    }
    // diagonally-up
    int i=row, j=col;
    for (; i>=0 && j>=0; i--, j--){
        if (board[i][j] == 'Q')
            return false;
    }
    // diagonally-down
    i= row;
    j= col;
    for (; i<=7 && j>=0; i++, j--){
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}


void QueenPos(int col){
    // cout << "Ho";
    if (col == 8){
        num++;
        return;
    }
    for (int i=0; i<8; i++){
        if (isSafe(i,col)){
            board[i][col] = 'Q';
            QueenPos(col + 1);
            board[i][col] = '.';
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0; i<8; i++){
        string temp;
        cin >> temp;
        board.push_back(temp);
    }
    bd = board;
    QueenPos(0);
    cout << num;
    return 0;
}
