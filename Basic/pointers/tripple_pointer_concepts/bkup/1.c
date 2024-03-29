/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// O(n^2) for judge ispali[l][r] then dfs. 
int len;
char ***res;
int **rescolsize, resmaxsize,ressize,*list;
char **ispali;
char *s;
void add_result(int size){
	if (++ressize == resmaxsize) {
		resmaxsize <<= 1;
		res = realloc(res, sizeof(char**) * resmaxsize);
		*rescolsize = realloc(*rescolsize, sizeof(int) * resmaxsize);
	}
	(*rescolsize)[ressize - 1] = size;
	char **now = res[ressize - 1] = malloc(sizeof(char *) * size);
	int tmplen;
	list[size] = len;
	for (int i = 0; i < size; ++i) {
		tmplen = (list[i+1] - list[i] + 1);
		now[i] = malloc(sizeof(char) * tmplen);
		strncpy(now[i], s + list[i],tmplen-1);
		now[i][tmplen-1] = 0;
	}
}

void dfs(int now, int size) {
	if (now == len) {
		add_result(size);
		return;
	}
	list[size++] = now; 
	for (int i = 0 ; i < len - now; ++i)
		if (ispali[now][i])
			dfs(now + i + 1, size);
}

char *** partition(char * _s, int* returnSize, int** returnColumnSizes){
	len = strlen(_s);
	resmaxsize = 1;
	rescolsize=returnColumnSizes;
	*returnSize = ressize = 0;
	s = _s;
	*returnSize = 0;
	*returnColumnSizes = malloc(0);
	res = malloc(0);
	if (len == 0) return res;
	ispali = malloc(sizeof(char*) * len);
	for (int i = 0; i < len; i++)
		ispali[i] = calloc(len - i, sizeof(char)), ispali[i][0] = 1;
	for (int i = 1; i < len; ++i) {
		int l = i-1, r = i+1;
		while (l >= 0 && r < len && s[l] == s[r])
			ispali[l][r-l] = 1, --l, ++r;
		l = i-1; r = i;
		while (l >= 0 && r < len && s[l] == s[r])
			ispali[l][r-l] = 1, --l, ++r;
	}
	list = malloc(sizeof(int) * (len+1));
	dfs(0, 0);
	for (int i = 0; i < len; i++)
		free(ispali[i]);
	free(ispali);
	free(list);
	*returnSize = ressize;
	return res;
}
