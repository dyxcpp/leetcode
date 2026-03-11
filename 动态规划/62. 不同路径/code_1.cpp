
// // 题解一：动态规划。
// // 思考思路: 首先考虑到达finish点(m,n)的路径=(m, n-1) + (m-1, n),则可以递推
// //           需要创建一个二维dp数组，且初始化的时候需要初始第一行和第一列都为1(只能往右或往左)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         // 判断如果只是一维的，则直接返回
//         if(m == 1 || n == 1) return 1;
//         // 直接初始化全为1，这样后面的也会被覆盖掉，第一行第一列的也能都初始化为1
//         vector<vector<int>> dp(m, vector<int>(n, 1));
//         for(int i = 1; i < m; ++i) {
//             for(int j = 1; j < n; ++j) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };


// // 对题解一进行空间优化: 采用滚动数组，只用一维就可以计算
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         // 判断如果只是一维的，则直接返回
//         if(m == 1 || n == 1) return 1;
//         // 直接初始化全为1，这样后面的也会被覆盖掉，第一行第一列的也能都初始化为1
//         vector<int> dp(n, 1);
//         for(int i = 1; i < m; ++i) {
//             for(int j = 1; j < n; ++j) {
//                 dp[j] += dp[j-1];
//             }
//         }
//         return dp[n-1];
//     }
// };

// 题解二：数学解法。对于m*n的地图，走到终点需要m+n-2步，而因为地图高度为m，则其中必须要向下走m-1步，所以路径数就可以转化成求从m+n-2中选m-1个数有多少种组合，即求C(m+n-2, m-1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long a = 1; // 初始化分子，由于需要连乘，分子会很大，所以用longlong
        int b = m-1;
        int s = m+n-2;
        // int count = m-1;
        for(int i = 0; i < m-1; i++) {
            a *= s--;
            while(b != 0 && a % b == 0) {
                a /= b;
                b--;
            }
        }
        return a;
    }
};
