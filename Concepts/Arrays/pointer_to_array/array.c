#include <string.h>
#include <stdio.h>

#define NUM_ELEM(ar) (sizeof(ar) / sizeof((ar)[0]))

int *put_off(const int newrow[2])
{
	static int mymatrix[3][2];
	static int (*rowp)[2] = mymatrix;
	int (* const border)[] = mymatrix + NUM_ELEM(mymatrix);

	memcpy(rowp, newrow, sizeof(*rowp));
	rowp += 1;
	if (rowp == border) {
		rowp = mymatrix;
	}

	return *rowp;
}

int main(int argc, char *argv[])
{
	int i = 0;
	int row[2] = {0, 1};
	int *rout;

	for (i = 0; i< 6; i++) {
		row[0] = i;
		row[1] += i;
		rout = put_off(row);
		printf("%d (%p): [%d, %d]\n", i, (void *) rout, rout[0], rout[1]);
	}

	return 0;
}
