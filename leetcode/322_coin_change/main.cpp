// took 9 minutes
// Algorithm: dynamic programming
// - infinite knapsack
// - time complexity: O(nm), where n is the budget amount and m is the number of
// coin denominations

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
  // Initialize the memoization table
  vector<int> dp(amount + 1, -1);
  dp[0] = 0;

  // for each budget amount, find the minimum number of coins to cover that
  // amount
  for (int i = 1; i < amount + 1; i++) {
    int min_coins = numeric_limits<int>::max();
    for (int coin : coins) {
      if (i - coin >= 0 && dp[i - coin] != -1) {
        min_coins = min(min_coins, dp[i - coin] + 1);
      }
    }

    // if nothing worked, then this amount cannot be reached.
    if (min_coins == numeric_limits<int>::max()) {
      dp[i] = -1;
    } else {
      dp[i] = min_coins;
    }
  }

  for (auto i : dp) {
    cout << i << ' ';
  }
  cout << endl;

  return dp[amount];
}

int main(int argc, char *argv[]) {
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  cout << "result: " << coinChange(coins, amount) << endl;

  return 0;
}
