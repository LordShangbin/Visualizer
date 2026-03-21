#include <vector>
#include <Visualizer.h>

using namespace std;

const int maxn = 1005, modnum = 1e9 + 7;
int n, m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1)); // Define dp (Vector only)
    init(dp, {1, n+1}, {1, m+1}); //Init --> (dp, printing_range_i, printing_range_j)
    dp[0][1] = 1;
    Describe("dp[0] = 1"); //Description
    Visualize(dp, {}, {}); //Visualize
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % modnum;
            Describe("dp[i] = %d + %d", dp[i - 1][j], dp[i][j - 1]); //Description
            vector<pair<int, int>> purple = {{i - 1, j}, {i, j - 1}};
            vector<pair<int, int>> green = {{i, j}};
            Visualize(dp, purple, green); 
        }
    }
    cout << dp[n][m];
    while(!WindowShouldClose()) Visualize(dp, {}, {}); //ต้องใส่
    stop(); //ต้องใส่
}