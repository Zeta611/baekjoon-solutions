#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	const long *la = a, *lb = b;
	return (*la > *lb) - (*la < *lb);
}

// Returns the index of the first occurence of `val` in [arr, arr + len).
long lower_bound(const long *arr, long len, long val)
{
	long first = 0;
	long last = len - 1;
	long mid = len / 2;

	while (first <= last) {
		if (arr[mid] == val) {
			return mid;
		} else if (arr[mid] < val) {
			first = mid + 1;
		} else {
			last = mid - 1;
		}
		mid = (first + last) / 2;
	}
	return first;
}

// Returns the length of the deduplicated array.
long unique(long *first, long *last)
{
	if (first == last) {
		return 0;
	}

	long len = 0;
	long *it = first;
	while (++first != last) {
		if (*it != *first) {
			*++it = *first;
			++len;
		}
	}
	return ++len;
}

int main(void)
{
	long cnt;
	scanf("%ld\n", &cnt);

	long *coord = malloc(cnt * sizeof *coord);
	for (long i = 0; i < cnt; ++i) {
		scanf("%ld", coord + i);
	}

	// Copy `coord` into `sorted` for sorting.
	long *sorted = malloc(cnt * sizeof *coord);
	memcpy(sorted, coord, cnt * sizeof *sorted);
	qsort(sorted, cnt, sizeof *coord, cmp);
	long len = unique(sorted, sorted + cnt);

	for (long i = 0; i < cnt; ++i) {
		printf("%ld ", lower_bound(sorted, len, coord[i]));
	}
	putchar('\n');
}
