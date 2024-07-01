/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */






int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

	int **retArray=(int**)malloc(sizeof(int*)*numsSize);





	*returnColumnSizes=(int*)malloc(sizeof(int)*numsSize);




	(*returnColumnSizes)[*returnSize]=3;



	retArray[*returnSize]=(int*) malloc(sizeof(int)*3);



	retArray[*returnSize][0]=nums[i];
	retArray[*returnSize][1]=nums[start];
	retArray[*returnSize][2]=nums[end];


	(*returnSize)++;


	*returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*total);
	retArray=(int**)realloc(retArray,sizeof(int*)*total);


}	

