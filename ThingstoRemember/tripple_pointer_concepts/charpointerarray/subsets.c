#include <stdio.h>
void powerSet(string str, int index = -1, chat *curr)
{
	int n = strlen(str);

	if (index == n)
        	return;

	   for (int i = index + 1; i < n; i++) {

        curr += str[i];
        powerSet(str, i, curr);

        // Once all subsets beginning with
        // initial "curr" are printed, remove
        // last character to consider a different
        // prefix of subsets.
        curr.erase(curr.size() - 1);
    }
    return; 

}

int main()
{
	char *ptr = "abc";
	char *str = NULL;

	powerSet(str);

	return 0;
}
