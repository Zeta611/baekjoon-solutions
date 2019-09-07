#include <stdio.h>
#include <math.h>

void hanoi(int n, int source, int dest)
{
	if (n == 1) {
		printf("%d %d\n", source, dest);
		return;
	}
	hanoi(n - 1, source, 6 - source - dest);
	hanoi(1, source, dest);
	hanoi(n - 1, 6 - source - dest, dest);
}

int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(n, 1, 3);
	return 0;
}
