#include<stdio.h>

int count_pieces(int length, int stick1, int stick2) {
    return (stick1 / length) + (stick2 / length);
}

int can_form_square(int length, int stick1, int stick2) {
    return count_pieces(length, stick1, stick2) >= 4;
}

int solution3(int A, int B) {
    
    for (int length = (A < B ? A : B); length > 0; length--) {
        if (can_form_square(length, A, B)) {
            return length;
        }
    }

    return 0;
}

int solution(int a, int b)
{
	int sticks = a+b;

	int maxlength = sticks/4;

	while(maxlength > 0) {
		int maxa = a/maxlength;
		int maxb = b/maxlength;

		if(maxa + maxb >= 4)
			return maxlength;

		maxlength--;
	}
	
	return 0;
}

int solution2(int a, int b)
{
	int max = 0;

	if(a >= b/3)
		max = max < b/3 ? b/3: max;

	if(a >= 2*(b/2))
		max = max < b/2 ? b/2 : max;
	if(b >= (a/3))
		max = max < a/4 ? a/4 : max; 

	return max;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("no: %d\n",solution3(a, b));
	return 0;
}
