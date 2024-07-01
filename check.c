#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int i,start,end,sum,t,total=64;

    qsort(nums,numsSize,sizeof(int),cmp); // sorting the array
    *returnSize=0;
    int **retArray=(int**)malloc(sizeof(int*)*numsSize);
    *returnColumnSizes=(int*)malloc(sizeof(int)*numsSize);

    // if input array size is 3
    if (numsSize == 3)
    {
        t = nums[0]+nums[1]+nums[2];
        if (t == 0)
        {
            //add to the array
            // here 3 because array will be containing 3 values
            // *returnSize is the column, start at 0 and so on.. so for first case retArray[0][0],
            // retArray[0][1], retArray[0][2],
            (*returnColumnSizes)[*returnSize]=3;
            retArray[*returnSize]=(int*) malloc(sizeof(int)*3);
            retArray[*returnSize][0]=nums[0];
            retArray[*returnSize][1]=nums[1];
            retArray[*returnSize][2]=nums[2];
            (*returnSize)++;
        }
    }

    // -3 because, to consider the case when i 3 position from last.
    // [-4,-1,-1,0, 1,   2]
    //           i start end
    for(i=0;i<numsSize-3;i++)
    {

        if ((i == 0) || (nums[i] > nums[i-1]))
        {
            // setting start and end pointers.
            start = i+1;
            end = numsSize -1;

            while (start < end)
            {
                t = nums[i]+nums[start]+nums[end];
                if (t == 0)
                {
                    //add to the array
                    // here 3 because array will be containing 3 values
                    // *returnSize is the column, start at 0 and so on.. so for first case retArray[0][0],
                    // retArray[0][1], retArray[0][2],
                    (*returnColumnSizes)[*returnSize]=3;
                    retArray[*returnSize]=(int*) malloc(sizeof(int)*3);
                    retArray[*returnSize][0]=nums[i];
                    retArray[*returnSize][1]=nums[start];
                    retArray[*returnSize][2]=nums[end];
                    (*returnSize)++;
                    if((*returnSize)==total)
                    {
                        total*=2;
                        *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*total);
                        retArray=(int**)realloc(retArray,sizeof(int*)*total);
                    }
                    int currstart = start;
                    while ((nums[start] == nums[currstart]) && start <end) // avoiding array out of bound
                        start++;
                    int currend = end;
                    while ((nums[end] == nums[currend]) && start <end) // avoiding array out of bound
                        end--;
                }
                if (t < 0)
                {// start needs to be increamented, avoiding duplicates
                    int currstart = start;
                    while ((nums[start] == nums[currstart]) && start <end) // avoiding array out of bound
                        start++;
                }
                else if (t > 0)
                {// end needs to be decreamented, avoiding duplicates
                    int currend = end;
                    while ((nums[end] == nums[currend]) && start <end) // avoiding array out of bound
                        end--;
                }
            }
        }
    }
    return retArray;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int main()
{
	int nums[] = {-1,0,1,2,-1,-4}, target = 0, returnSize = 0, *returnColumnSizes[3];
	//int nums[] = {0,1,1}, target = 0, returnSize = 0, *returnColumnSizes[4];
	//int nums[] = {0,0,0}, target = 0, returnSize = 0, *returnColumnSizes[4];

	int **result = threeSum(nums, sizeof(nums)/sizeof(int), &returnSize, returnColumnSizes);

        printf("return size: %d\n coloumn size", returnSize);
        for(int i = 0; i< returnSize; i++) {
                printf("%d, ", sizeof(*returnColumnSizes[i]));
        }

        printf("3sum is: \n \t");
        for(int i=0; i<returnSize; i++) {
                printf("[ ");
                for(int j = 0; j<(*returnColumnSizes)[i]; j++)
                        printf("%d,", result[i][j]);
                //free(result[i]);
                printf(" ]\n\t");
        }
        free(*returnColumnSizes);
        printf("\n");

	return 0;
}
