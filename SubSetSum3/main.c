#include <stdio.h>
#include <stdlib.h>

//Subset Sum : using backtracking and variable size tuple vector
//to print all the subsets existing with the sum given

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
static   int j=0;
static int total_nodes;
// prints subset found
void printSubset(int E[], int size)
{
    int i;
	for( i = 0; i < size; i++)
	{
		printf("%*d", 4 , E[i]);
	}

	printf("  |");
}

/* inputs
 set--> set vector
 t--> tuplet vector
 s_size--> set size
 t_size--> tuplet size so far
 sum--> sum so far
 cpt--> nodes count
 target_sum--> sum to be found*/

void subset_sum(int set[], int t[],int s_size, int t_size,int sum, int cpt,int const target_sum)
{

	total_nodes++;
	if( target_sum == sum )
	{
	    if(j==0){
		// We found a subset
		printSubset(t, t_size);
		j++;}
		// Exclude previously added item and consider next candidate
		subset_sum(set, t, s_size, t_size-1, sum - set[cpt], cpt + 1, target_sum);
	}
	else
	{
	    int i;
		// generate nodes along the breadth
		for(  i = cpt; i < s_size; i++ )
		{
			t[t_size] = set[i];
        // consider next level node (along depth)
			subset_sum(set, t, s_size, t_size + 1, sum + set[i], i + 1, target_sum);
		}
	}
}

//Prints subsets that sum to target_sum
void generateSubsets(int set[], int size, int target_sum)
{
	int *tuplet_vector = (int *)malloc(size * sizeof(int));

	subset_sum(set, tuplet_vector, size, 0, 0, 0, target_sum);

	free(tuplet_vector);
}

int main()
{
	int set[] ={3,4,7,2,12,8,10};
	int sum=14;
	int size = ARRAYSIZE(set);
	printf("Subsets with given sum : \n");
	generateSubsets(set, size,sum);
	printf("\n \nNodes generated :  %d nodes\n", total_nodes);
	return 0;
}


