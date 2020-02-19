// A Dynamic Programming solution for subset sum problem
#include <stdio.h>

// Returns the Max
int MAX (int i,int j)
{
    if (i>j) return i;
    else return j;
}
// Returns true if there is a subset of set[] with sun equal to given sum
int SubsetSum(int set[], int n, int sum)
{
	int subset[n+1][sum+1];
    int card[n+1][sum+1];
    int i,j;
	// If sum is 0, then answer is true
	for (i = 0; i <= n; i++)
	subset[i][0] = 1;

    for (i = 0; i <= n; i++)
	card[i][0] = 0;
	// If sum is not 0 and set is empty, then answer is false
	for ( i = 1; i <= sum; i++)
	subset[0][i] = 0;

	for ( i = 1; i <= sum; i++)
	card[0][i] = -1;
	// Fill the subset table
	for (i = 1; i <= n; i++)
	{
	for ( j = 1; j <= sum; j++)
	{
		if(j<set[i-1])
		subset[i][j] = subset[i-1][j];
		if (j >= set[i-1])
		subset[i][j] = subset[i-1][j] ||
								subset[i - 1][j-set[i-1]];
	}
	}
// Fill the card table
	for (i = 1; i <= n; i++)
	{
	for ( j = 1; j <= sum; j++)
	{
		if(j<set[i-1])
		card[i][j] = card[i-1][j];
		if (j >= set[i-1])
            card[i][j]=MAX(card[i-1][j],card[i-1][j-set[i-1]]+1);

	}
	}

    //print table
    printf("Array of subsets\n");
	for (i = 0; i <= n; i++)
	{
	for ( j = 0; j <= sum; j++)
		printf ("%*d",4, subset[i][j]);
	printf("\n");
	}
	printf("\n\n");
	printf("Array of cards\n");
	for (i = 0; i <= n; i++)
	{
	for ( j = 0; j <= sum; j++)
		printf ("%*d",4, card[i][j]);
	printf("\n");
	}

printf("\ncard max = %d \n\n", card[n][sum]);

	return subset[n][sum];

}

int main()
{
    int set[] ={2,12,8,3,4,7,10};
int sum = 14;
int n = sizeof(set)/sizeof(set[0]);

if (SubsetSum(set, n, sum) == 1)
	printf("A subset with the given sum is found a\n");
else
	printf("No subset with the given sum\n");



return 0;
}
