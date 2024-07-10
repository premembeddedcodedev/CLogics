//Problem: https://leetcode.com/problems/container-with-most-water/
//https://www.youtube.com/watch?v=ZHQg07n_tbg
#include <stdio.h>
#include <stdlib.h>

int calculate_area_water_1(int a[], int n)
{
	int start = 0, end = n-1, max_area=0, delta_off, volume;

	while(start < end) {
		delta_off = end - start;
		volume = a[end] > a[start] ? a[start] : a[end];
		max_area = max_area > (volume) ? max_area : (volume);
		if(a[start] < a[end])
			start++;
		else
			end--;
	}

	return max_area;
}

int calculate_area_water(int a[], int n)
{
	int start = 0, end = n-1, max_area=0, delta_off, volume;

	while(start < end) {
		delta_off = end - start;
		volume = a[end] > a[start] ? a[start] : a[end];
		max_area = max_area > (delta_off * volume) ? max_area : (delta_off * volume);
		if(a[start] < a[end])
			start++;
		else
			end--;
	}

	return max_area;
}

int main(int argc, char *argv[])
{
	int a[20] = {0}, n, i;

	printf("Enter the size of an array: \n");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0; i<n; i++)
		printf("%d ", a[i]);

	printf("max: %d\n",calculate_area_water_1(a, n));

	return 0;
}
