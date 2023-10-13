int minCostClimbingStairs(int *cost, int n){
  	// If the size of the array  is 1, we simply return the cost of the first step. If the size is 2, we return the minimum of the costs of the first two steps.
	if (n <= 2){
		return (n == 1 ? cost[0] : fmin(cost[0], cost[1]));
	}
	
	//minCost of the same size as cost to store the minimum cost to reach each step of the staircase.
	int* dp = (int*) malloc(sizeof(int) * n);
	dp[0]= cost[0];
	dp[1] = cost[1];
	
	for (int i = 2; i < n; i++){
		dp[i] = cost[i] + fmin(dp[i - 1], dp[i - 2]);
	}
	
	int minCost = fmin(dp[n - 1], dp[n - 2]);
	free(dp);
	return minCost;
}

int main() {
    int cost[] = {10, 15, 20, 25, 30};
    int costSize = sizeof(cost) / sizeof(cost[0);

    int minCost = minCostClimbingStairs(cost, costSize);
    printf("Minimum cost to climb the stairs: %d\n", minCost);

    return 0;
}
