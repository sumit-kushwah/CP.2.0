#include<bits/stdc++.h>
typedef long long ll;
const ll M = 1000000007;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n, m;
  cin >> n >> m;
  if (n > m)
    swap(n, m);
  
  ll matrix[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      matrix[i][j] = 0;
      if (i == 1 && j >= 1)
        matrix[i][j] = j - 1;
      if (j == 1 && i >= 1)
        matrix[i][j] = i - 1;
      // cout << matrix[i][j] << " ";
    }
    // cout << endl;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      ll temp = INT_MAX;
      if (i != j) {
        for (int k = i - 1; k >= 1; k--) {
          temp = min(temp, 1LL + matrix[k][j] + matrix[i - k][j]);
        }
        for (int k = j - 1; k >= 1; k--) {
          temp = min(temp, 1LL + matrix[i][k] + matrix[i][j - k]);
        }
        matrix[i][j] = temp;
      } else {
        matrix[i][j] = 0;
      }
    }
  }

  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= m; j++) {
  //     cout << matrix[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << matrix[n][m] << endl;
  return 0;
}