class Solution:
    def f(self, i, amount, coins, dp):
        if amount == 0:
            return 1

        if i == 0:
            if amount % coins[0] == 0:
                return 1
            return 0

        if dp[i][amount] != -1:
            return dp[i][amount]

        pick = 0
        if coins[i] <= amount:
            pick = self.f(i, amount - coins[i], coins, dp)

        not_pick = self.f(i - 1, amount, coins, dp)

        dp[i][amount] = pick + not_pick
        return dp[i][amount]

    def change(self, amount: int, coins: list[int]) -> int:
        n = len(coins)

        dp = [[-1] * (amount + 1) for _ in range(n)]

        return self.f(n - 1, amount, coins, dp)