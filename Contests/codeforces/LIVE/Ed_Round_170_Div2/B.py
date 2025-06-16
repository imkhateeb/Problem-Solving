MOD = 1000000007

def ans_using_dp(p, q):
    # Check for constraint limit (adjust as per problem's constraints)
    if p > 100000 or q > 100000:
        return 0
    
    dp = [[0] * (q + 1) for _ in range(p + 1)]

    for i in range(p + 1):
        dp[i][0] = 1

    for i in range(1, p + 1):
        for j in range(1, min(i, q) + 1):
            dp[i][j] = (dp[i][j - 1] % MOD + dp[i - 1][j - 1] % MOD) % MOD
  
    return dp[p][q]

# Main function
if __name__ == "__main__":
    T = int(input())
    p = list(map(int, input().split()))
    q = list(map(int, input().split()))

    for i in range(T):
        print(ans_using_dp(p[i], q[i]))
