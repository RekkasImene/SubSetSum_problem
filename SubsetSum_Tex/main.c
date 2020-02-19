#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

 int SubsetSum_Recurcive(int set[], int n, int sum,int *card)
{
int x1,x2;
   if (sum == 0) { *card=0; return 1;}
   if ((n == 0 && sum != 0)||(sum < 0)) {*card=0; return 0;}
   if (SubsetSum_Recurcive(set, n-1, sum,&x1)==1 && SubsetSum_Recurcive(set, n-1, sum-set[n],&x2)==1)
        {
        if (x1>(x2+1)) *card =x1;
        else *card=x2+1;
        return 1;
        }
   if (SubsetSum_Recurcive(set, n-1, sum-set[n],&x2)==1 && SubsetSum_Recurcive(set, n-1, sum,&x1)==0)
        {
    *card=x2+1;
        return 1;
        }
         if (SubsetSum_Recurcive(set, n-1, sum-set[n],&x2)==0 && SubsetSum_Recurcive(set, n-1, sum,&x1)==1)
        {
    *card=x1;
        return 1;
        }
   return 0;
}


int MAX (int i,int j)
{
    if (i>j) return i;
    else return j;
}
// Returns true if there is a subset of set[] with sun equal to given sum
int SubsetSum_ProgDynamiq(int set[], int n, int sum)
{
	int subset[n+1][sum+1];
    int card[n+1][sum+1];
    int i,j;
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
   /* printf("Array of subsets\n");
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
	}*/

  printf("\ncard max = %d \n\n", card[n][sum]);

	return subset[n][sum];

}

int main()
{
  int set[] ={2,12,8,3,4,7,10,2,12,8,3,4,7,10,2,12,8,3,4,10,2,12,8,3};
  int card;
  int n=ARRAYSIZE(set);
  printf(" Sum== %d \n",14);
  clock_t start, end;

     /* Recording the starting clock tick.*/
    start = clock();

   int j = SubsetSum_Recurcive(set, 7,14,&card);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
double time_taken1 = (double)(end - start) / (double)(CLOCKS_PER_SEC);

    /* Recording the starting clock tick*/
    start = clock();

     j = SubsetSum_ProgDynamiq(set,7 , 14);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken2 = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    /* Recording the starting clock tick.*/
    start = clock();

   j = SubsetSum_Recurcive(set, 15,14,&card);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
double time_taken11 = (double)(end - start) / (double)(CLOCKS_PER_SEC);

    /* Recording the starting clock tick*/
    start = clock();

    j = SubsetSum_ProgDynamiq(set,15, 14);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken22 = (double)(end - start) / (double)(CLOCKS_PER_SEC);

       /* Recording the starting clock tick.*/
    start = clock();

  j = SubsetSum_Recurcive(set, n,14,&card);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
double time_taken111 = (double)(end - start) / (double)(CLOCKS_PER_SEC);

    /* Recording the starting clock tick*/
    start = clock();

    j = SubsetSum_ProgDynamiq(set,n, 14);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken222 = (double)(end - start) / (double)(CLOCKS_PER_SEC);
printf("\n\nPour n== 7 \n\n");
printf("Time taken by program Recurcive is : %f s \n" ,time_taken1);
printf("Time taken by program Dynamique is : %f s \n" ,time_taken2);
printf("\nPour n== 15 \n\n");
printf("Time taken by program Recurcive is : %f s \n" ,time_taken11);
printf("Time taken by program Dynamique is : %f s \n" ,time_taken22);
printf("\nPour n== size of set \n\n");
printf("Time taken by program Recurcive is : %f s \n" ,time_taken111);
printf("Time taken by program Dynamique is : %f s \n" ,time_taken222);
  return 0;
}
