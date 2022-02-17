int bestW = 0;
vector<int> answer;

void calc(int N, int W, const vector<int>& w) {
  bestW = 0;
  answer.clear();
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
  for (int i = 0; i <= N; ++i) dp[i][0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = W; j >= 0; --j) {
      if (dp[i - 1][j] != -1) {
        dp[i][j] = -2;
      }
      if (j - w[i - 1] >= 0 && dp[i - 1][j - w[i - 1]] != -1 && dp[i][j] == -1) {
        dp[i][j] = i - 1;
      }
    }
  }
  for (int i = W; i >= 0; --i) {
    for (int j = 0; j <= N; ++j) {
      if (dp[j][i] != -1) {
        bestW = i;
        int Q = i, K = j;
        while (K > 0) {
          if (dp[K][Q] != -2) {
            answer.push_back(dp[K][Q]);
            Q -= w[dp[K][Q]];
          }
          --K;
        }
        break;
      }
    }
  }
}

void solve(int N, int W, const vector<int>& w) {
  calc(N, W, w);
  cout << "N = " << N << ", W = " << W << "\nw = [ ";
  for (int el : w) {
    cout << el << ' ';
  }
  cout << "]\nBest sum = " << bestW << "\nIndexes for this sum (from 1 to N):\n";
  for (int el : answer) {
    cout << el + 1 << ' ';
  }
  cout << '\n';
}
