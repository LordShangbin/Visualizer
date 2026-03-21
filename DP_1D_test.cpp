#include <vector>
#include <thread>
#include <Visualizer.h>

using namespace std;
#define ll long long

const int maxn = 100;
int n, x;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> dp(n);
    init(dp, {0, dp.size()});
    dp[0] = 1;
    Describe("dp[0] = 1");
    Visualize(dp, {}, {0});
    for (int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
        Describe("dp[%d] = %d + %d + 1", i, dp[i - 2], dp[i - 1]);
        Visualize(dp, {i - 1, i - 2}, {i});
    }
    while(!WindowShouldClose()) Visualize(dp, {}, {});
    stop();
}