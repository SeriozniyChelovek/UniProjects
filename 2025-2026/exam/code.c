#include <stdio.h>

int main() {
	
	int a[10];
	int i, j, s=0;
	for (i=0; i<10; i++)
		a[i] = i + 1;
	for (i=10,j=0; i>j; i--,j++)
		s=s+(a[i]-a[j]);

	printf("%d\n\r", s);

	return 0;
}
