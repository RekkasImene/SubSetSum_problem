#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
// Returns true if there is a subset of set[] with a sum equal to the given sum
/* inputs
 set--> set vector
 n--> set size
 sum--> sum to be found*/
int SubsetSum(int set[], int n, int sum)
{

 if (sum == 0) return 1;
 if ((n == 0 && sum != 0)||(sum < 0)) return 0;
 if (set[n] > sum) return SubsetSum(set, n-1, sum);
 return SubsetSum(set, n-1, sum) || SubsetSum(set, n-1, sum-set[n]);

}

int main()
{
  int set[] = {3,4,7,2,12,8,10};
  int sum = 14;
  int size = ARRAYSIZE(set);
  if (SubsetSum(set, size, sum) == 1)
  {
     printf("A subset with the given sum is found\n");
  }
  else
     printf("No subset with the given sum\n");
  return 0;
}
