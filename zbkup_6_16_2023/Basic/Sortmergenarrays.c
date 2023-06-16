#include <stdio.h>
#include <stdlib.h>

void display(int (*arraylist)[10], int num_array, int num_elements)
{
	int i, j;
	printf("\n Arrays as follows : \t {");
	for(i=0;i<num_array;i++) {
		for(j=0;j<num_elements;j++) {
			printf("%d, ", arraylist[i][j]);
		}
	}
	printf("}\n");
}

void sort_array(int src[], int num_elements)
{
	int i, j, temp;

	for(i=0;i<num_elements;i++) {
		for(j=i+1;j>=0;j--) {
			if(src[j] < src[j-1]) {
				temp = src[j];
				src[j] = src[j-1];
				src[j-1]= temp;
			} else
				break;
		}
	}
}

void swap(int *src, int *dst)
{
	int temp = *src;
	*src = *dst;
	*dst = temp;
}

void insertion_sort(int a[], int array_bound)
{
	int i, j;
#if 1
	for(i=1;i<array_bound; i++) {
		for(j=0; j<i; j++) {
			if(a[j] > a[i])
				swap(&a[j], &a[i]);
		}
	}
#else
	int lastoff = 0, maxoff= 0, swp, n = array_bound;
	for (i=0; i<n; i++) {
		lastoff = n-i;
		//findmaxoffset here
		for(j=0; j<=lastoff; j++) {
			//maxoff will update if the number is lessthan subsequent number in the array
			if(a[maxoff] < a[j])
				maxoff = j;
		}
		swp = a[maxoff];
		a[maxoff] = a[lastoff];
		a[lastoff] = swp;
		maxoff = 0;
	}

	printf("sorted: {");
	for(i=0;i<array_bound;i++)
		printf(",%d ",a[i]);
	printf("}\n");
#endif
}

//int n_ele, count = 0;

void sort_merge(int (*arraylist)[10], int m_list[], int off, int num_array, int num_elements, int count)
{
	int i, j;

	if(off < num_array)
		return;

	int *temp = arraylist[off++];
	insertion_sort(temp, num_elements);
	printf("{");
	for(i=0;i<num_elements;i++)
		printf(",%d ",temp[i]);
	printf("}\n");
	
	int *temp2 = arraylist[off++];
	insertion_sort(temp2, num_elements);
	printf("{");
	for(i=0;i<num_elements;i++)
		printf(",%d ",temp2[i]);
	printf("}\n");
	
	i = 0, j=0;

	while(i<num_elements && j<num_elements) {
		if(temp[i] < temp2[j]) {
			m_list[count++] = temp[i];
			i++;
		} else {
			m_list[count++] = temp2[j];
			j++;
		}
	}
	
	while(i<num_elements)
		m_list[count++] = temp[i++];
	while(j<num_elements)
		m_list[count++] = temp2[j++];

	printf("\nsort_merge: num_array: %d, count = %d\n", num_array, off);

	sort_merge(arraylist, m_list, off, num_array, num_elements, count);
}

void sort(int (*arraylist)[10], int num_array, int num_elements)
{
	int i = 0, j, m_list[num_array * num_elements];

	//n_ele = num_array;

	sort_merge(arraylist, m_list, 0, num_array, num_elements, 0);
	
	printf("{");
	for(i=0;i<(num_elements*num_array);i++)
		printf(",%d ",m_list[i]);
	printf("}\n");
}

int main()
{
	int ch, i, j;
	int num_elements, num_array;
	int (*arraylist)[10];

	while(1) {
		printf("Enter your choice:\
				1. Add arrays \
				2. sort \n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the num elements");
				scanf("%d", &num_elements);
				printf("Enter the num array\n");
				scanf("%d", &num_array);
				arraylist = (int (*)[num_elements])malloc(num_array * sizeof(*arraylist));
				if(!arraylist)
					return -1;

				for(i=0;i<num_array;i++) {
					for(j=0;j<num_elements;j++) {
						scanf("%d", &arraylist[i][j]);
					}
				}

				printf("\n Arrays as follows : \t {");
				for(i=0;i<num_array;i++) {
					for(j=0;j<num_elements;j++) {
						printf("%d, ", arraylist[i][j]);
					}
				}
				printf("}\n");

				break;
			case 2:
				sort(arraylist, num_array, num_elements);
				break;
			default:
				break;
		}
	}

	return 0;
}
