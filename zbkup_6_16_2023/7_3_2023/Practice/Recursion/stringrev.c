#include<stdio.h>
#include <string.h>

void strrev(char *str, int start, int end, int mid)
{
	if(start > mid) // here should not be any =
		return;

	char temp = str[start];
	str[start] = str[end];
	str[end] = temp;

	strrev(str, ++start, --end, mid);
}

void parition_rev(char *str)
{
	int end = 0, start_offset = 0, len = strlen(str);
	
	printf("len: %d\n", len);

	while(end <= len) {	
		if(str[end] == ' ' ||  str[end] == '\0') {
			// convert mid as per the start offset given
			strrev(str, start_offset, end-1, start_offset + (end - 1 - start_offset)/2);
			start_offset = end + 1;
		}
		end++;
	}
}

int main()
{
	char src[] = "Qualcomm is Service based company";

	strrev(src, 0, strlen(src) - 1, (strlen(src)-1)/2);

	printf("%s\n", src);

	parition_rev(src);
	
	printf("%s\n", src);

	return 0;
}
