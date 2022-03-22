#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//XXX: beware of number comparission with character = User needs to convert character into ointeger and do comparission
//Output: 
/*praveenv@praveenv-vm:~/sambashare/practice_nvidia$ ./a.out -739 9
pos: 4 - string length: 4
copy if loop: value:9 dst[4]: 9
dst[0] : 45      dst[1] : 7      dst[2] : 3      dst[3] : 9      dst[4] : 9

praveenv@praveenv-vm:~/sambashare/practice_nvidia$ ./a.out 739 9
Detected less numeber: 7
pos: 0 - string length: 3
copy if loop: value:9 dst[0]: 9
dst[0] : 9       dst[1] : 7      dst[2] : 3      dst[3] : 9
*/

void find_max_number(char *src, char *value)
{
	int i = 0, j = 0, pos = 0;
	char dst[10] = {0};

	if(src[0] == '-') {
		dst[0] = src[0];
		i = 1;
		while(src[i] != '\0') {
			if((src[i]) > *value)
				break;
			i++;
		}
		pos = i;
		i = j = 1;
	} else {

		while(src[i] != '\0') {
			if((src[i]) < *value) {
				printf("Detected less numeber: %c\n", src[i]);
				break;
			}
			i++;
		}
		pos = i;
		i = j = 0;
	}
	
	printf("pos: %d - string length: %ld\n", pos, strlen(src));

	while(i <= strlen(src)) {
		if(i == pos) {
			dst[j] = *value;
			printf("copy if loop: value:%c dst[%d]: %c\n", *value, j, dst[i]);
			j++;
		}
		dst[j] = src[i];
		j++; i++;
	}

	i = 0;

	while(i< j-1) {
		printf("dst[%d] : %c \t ", i, dst[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{

	if(argc != 3) {
		printf("./a.out requires 3 arguements\n");
		exit(-1);
	}

	find_max_number(argv[1], argv[2]);
}
