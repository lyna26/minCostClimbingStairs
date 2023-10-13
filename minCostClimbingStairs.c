int minCostClimbingStairs(int *cost, int n){
  if (n <= 2){
		return (n == 1 ? cost[0] : fmin(cost[0], cost[1]));
	}
	
	int* dp = (int*) malloc(sizeof(int) * n);
	dp[0]= cost[0];
	dp[1] = cost[1];
  
	for (int i = 2; i < n; i++){
		dp[i] = cost[i] + fmin(dp[i - 1], dp[i - 2]);
	}
  
	int minCost = fmin(dp[n - 1], dp[n - 2]);
  
  return minCost;
}
