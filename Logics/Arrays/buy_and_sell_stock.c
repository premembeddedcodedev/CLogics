#include <stdio.h>

//comparing the 0,1 - 1,2 - 2,3 - 3,4 and so on values. because if you buy a stock which is greater than older day then you have to sell right
//thats the logic


int max_profit_bf(int stock[], int days)
{
	int i, profit = 0;

	for(i=0;i<days;i++)
	{
		if(stock[i] <= stock[i+1]) {
			profit += (stock[i+1] - stock[i]);
		} 
	}
	
	return profit;
}

int main()
{
	int array_bound;

	printf("Enter the array bound: \n");
	scanf("%d", &array_bound);

	int stock[array_bound], i;
	
	printf("Enter the %d stock prices: \n", array_bound);

	for(i=0;i<array_bound;i++)
		scanf("%d", &stock[i]);

	printf("max profit: %d\n",max_profit_bf(stock, array_bound));

	return 0;
}
