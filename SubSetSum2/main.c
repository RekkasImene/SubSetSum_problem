#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
//Prints the bits table and the minimal subset with the sum given
int subset[]  ; //bits Table
/* inputs
 set--> set vector
 n--> set size
 sum--> sum to be found*/
int SubsetSum(int set[], int n, int sum)
{

   if (sum == 0) return 1;
   if ((n == 0 && sum != 0)||(sum < 0)) return 0;
   if (SubsetSum(set, n-1, sum)==1)
        {
        subset[n]=0;
        return 1;
        }
   if (SubsetSum(set, n-1, sum-set[n])==1)
        {
       subset[n]=1;
        return 1;
        }
   return 0;
}

int main()
{
  int set[] ={3,4,7,2,12,8,10};
  int size = ARRAYSIZE(set);
  int sum = 14;
  int i;

  for(i=0;i<size;i++)
     {
         subset[i]=0;
     }

  if (SubsetSum(set, size, sum) == 1)
  {
     printf("A subset with the given sum is found  \n\n");

     printf("Array of subset with bits 0/1: \n");
     for(i=0;i<size;i++)
     {
      printf("%d | ",subset[i]);
     }

     printf("\n\nArray of the minimal subset of set[] with a sum equal to the given sum : \n");
     for(i=0;i<size;i++)
     {
         if (subset[i]==1)  printf("%d | ",set[i]);
     }

     printf("\n");
   }
  else
     printf("No subset with given sum\n");
  return 0;
}
