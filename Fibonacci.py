

def fib(n,dp):
    if dp[n] != -1:
        return dp[n]
    
    dp[n] = fib(n-1,dp) + fib(n-2,dp)
    return dp[n]


def main():
    dp = [0,0,1]
    for i in range(100002):
        dp.append(-1)
    t = int(input())
    n = list(map(int, input().strip().split(" ")))

    
        
    for num in n:
        print(fib(num,dp))
        
    
    
if __name__ == "__main__":
    main()
