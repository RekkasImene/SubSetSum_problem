#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

/* inputs
 set--> set vector
 n--> set size
 sum--> sum to be found*/

 int SubsetSum(int set[], int n, int sum,int *card)
{
int x1,x2;
   if (sum == 0) { *card=0; return 1;}
   if ((n == 0 && sum != 0)||(sum < 0)) {*card=0; return 0;}
   if (SubsetSum(set, n-1, sum,&x1)==1 && SubsetSum(set, n-1, sum-set[n],&x2)==1)
        {
        if (x1>(x2+1)) *card =x1;
        else *card=x2+1;
        return 1;
        }
   if (SubsetSum(set, n-1, sum-set[n],&x2)==1 && SubsetSum(set, n-1, sum,&x1)==0)
        {
    *card=x2+1;
        return 1;
        }
         if (SubsetSum(set, n-1, sum-set[n],&x2)==0 && SubsetSum(set, n-1, sum,&x1)==1)
        {
    *card=x1;
        return 1;
        }
   return 0;
}

int main()
{
  int set[] ={2,12,8,3,4,7,10};
  int size = ARRAYSIZE(set);
  int sum = 14;
  int card;
  if (SubsetSum(set, size, sum,&card) == 1)
  {
     printf("A subset with the given sum is found  \n\n");

     printf("la cardinalite maximale est : %d \n", card);

     printf("\n");
   }
  else
     printf("No subset with given sum\n");
  return 0;
}
