#include <stdio.h>
#include <stdlib.h>
int elemt[7]  ;
// Returns true if there is a subset of set[] with sun equal to given sum
int SubsetSum(int set[], int n, int sum)
{

   if (sum == 0)
     return 1;
     else{
   if ((n == 0 && sum != 0)||(sum < 0))

     return 0;
   else{

 if (SubsetSum(set, n-1, sum)==1) {
        elemt[n]=0;
 printf("%d | ",elemt[n]);
 return 1;}
 if (SubsetSum(set, n-1, sum-set[n])==1) {
        elemt[n]=1;
 printf("%d | ",elemt[n]);
 return 1;}
        return 0;
  /* return SubsetSum(set, n-1, sum) ||
                        SubsetSum(set, n-1, sum-set[n]);*/

   }

     }
}

int main()
{
 int i;
  int set[] = {3,4,7,2,12,8,10};
  for(i==0;i<7;i++) elemt[i]=0;
  int sum = 14;

  int n = sizeof(set)/sizeof(set[0]);
  if (SubsetSum(set, n, sum) == 1)
  {
     printf("\n Found a subset with given sum");

     for(i==0;i<n;i++)
     {
         if (elemt[i]==1);
         printf("%d | ",set[i]);
     }


   }
  else
     printf("No subset with given sum");
  return 0;
}
