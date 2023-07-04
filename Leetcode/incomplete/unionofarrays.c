#include <stdio.h>

int main()
{
	int i, j, m, n, k = 0, p;
	
	printf("Enter Numbe of elements in src1\n");
	scanf("%d", &m);	

	printf("Enter Numbe of elements in src2\n");
	scanf("%d", &n);	

	int src1[m], src2[n], temp[m+n];
	printf("src1: Enter {");
	for(i=0; i<m;i++)
		scanf("%d", &src1[i]);
	printf("}\n");
	
	printf("src2: Enter: {");
	for(i=0; i<n;i++)
		scanf("%d",&src2[i]);
	printf("}\n");

	printf("src1: display {");
	for(i=0; i<m;i++)
		printf("%d,", src1[i]);
	printf("}\n");
	printf("src2: display {");
	for(i=0; i<n;i++)
		printf("%d,", src2[i]);
	printf("}\n");

	i = 0; j=0;
	while(i<m && j<n) {
		p = 0;
		if(src1[i] <= src2[j]) {
			while(p != k) {
				if(temp[p] == src1[i]) {
					i++;
					continue;
				}
				p++;	 
			}
			if(p == k) {
				temp[k] = src1[i];
				i++;
			}
		} else {
			while(p != k) {
				if(temp[p] == src2[j]) {
					j++;
					continue;
				}
				p++;	 
			}
			if(p == k) {
				temp[k] = src2[j];
				j++;
			}
		}
		k++;
	}

	while(i<m) {
		temp[k] = src1[i];
		i++; k++;
	}
	
	while(j<n) {
		temp[k] = src2[j];
		j++; k++;
	}
	
	printf("k: %d{", k);
	for(i=0; i<k;i++)
		printf("%d,", temp[i]);
	printf("}\n");

	return 0;
}
