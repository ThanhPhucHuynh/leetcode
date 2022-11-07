
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ans = (int**)malloc(sizeof(int*)*5000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*5000);
    //int **cur = ans;
    *returnSize = 0;
    for (int i = 0; i < numsSize-2; ++i) {
        if (i != 0 && *(nums+i) == *(nums+i-1)) continue;
        int j = i+1, k = numsSize-1;
        int target = -*(nums+i);
        while (j < k) {
            int sum = *(nums+j) + *(nums+k);
            if (sum == target) {
                if (*returnSize == 5000) {
                    ans = realloc(ans, sizeof(int *) * 100000);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * 100000);
                }
                // printf("%d %d %d\n", *(nums+i), *(nums+j), *(nums+k));
                // printf("%d\n", *returnSize);
                ans[*returnSize] = (int*)malloc(sizeof(int)*3);
                ans[*returnSize][0] = *(nums+i);
                ans[*returnSize][1] = *(nums+j);
                ans[*returnSize][2] = *(nums+k);
                //printf("here\n");
                //printf("%d %d %d\n", ans[count][0], ans[count][1], ans[count][2]);
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                j++;
                //k--;
                while (j < k && *(nums+j) == *(nums+j-1)) j++;
            }
            else if (sum > target) {
                k--;
            }
            else {
                j++;
            }
        }
    }
    return ans;
}


int main()
{
    int nums[] = {-1,0,1,2,-1,-4};
    int **res;
    int *colSize;
    int size;
    res = threeSum(nums,sizeof(nums)/sizeof(int),&size,&colSize);
    // print result and free 
    // printf("%d\n", **res);
}
