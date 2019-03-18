#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

typedef long long ll;

ll N, M;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    bool relations[12][12] = {};
    
    /*N, Mの入力*/
    cin >> N >> M;
    
    /* x, yの入力 */
    ll x, y;
    REP(i, M) {
        cin >> x >> y;
        relations[x - 1][y - 1] = relations[y - 1][x - 1] = true;
    }
    
    ll max = 0;
    /* 大きい値から全探索 */
    for (int S = 1 << N; --S;) {
        ll t = bitset<12>(S).count();
        if (t <= max) {
            continue;
        }
        
        bool ok = true;
        /* 互いに知らない関係があったらfalseとする */
        REP(i, N) {
            REP(j, i) {
                if ((S >> i & S >> j & 1) && !relations[i][j]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            max = t;
        }
    }
   
    cout << max << endl;
}
