class Solution
{
public:
    int dp[10010];
    int help(vector<int> &coins, int amount)
    {

        int ans = INT_MAX;

        if (amount == 0)
        {
            return 0;
        }
        if (dp[amount] != -1)
            return dp[amount]; // when require return amount no further call
        for (int coin : coins)
        {
            if (amount - coin >= 0)
                ans = min(ans + 0LL, help(coins, amount - coin) + 1LL);
        }
        return dp[amount] = ans; // keep record of calculated value
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp)); // set t -1
        int x = help(coins, amount);
        if (x == INT_MAX)
            return -1;
        return x;
    }
};