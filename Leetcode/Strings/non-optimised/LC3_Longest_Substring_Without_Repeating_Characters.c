/*
 * Given a string s, find the length of the longest substring
 without repeating characters.https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

 Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include <limits.h>
#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char* s)
{
	char hashset[256] = {0};
	int maxlen = INT_MIN;
	int i = 0, j = 0;

	for(i=0; i<strlen(s); i++) {
		memset(hashset, 0, sizeof(hashset));
		for(j=i; j<strlen(s); j++) {
			if(hashset[s[j]] == 1)
				break;
			if(maxlen < (j-i+1))
				maxlen = j - i + 1;
			hashset[s[j]] = 1;
		}
	}

	return maxlen;
}

int main()
{
	char *ptr = "cadbzabcd";//"abcabcbb";

	printf("length: %d\n",lengthOfLongestSubstring(ptr));

	return 0;
}

