#include <stdio.h>
#pragma warning(disable:4996)
int arr1[5000];
int top;
int start;
void pop(int count, int max, int *arr) {
	int i;
	start = (start + count - 1)%max;
	arr1[top++] = arr[start];
	for (i = start+1; i < max; i++) {
		arr[i - 1] = arr[i];
	}
}
void print() {
	int i = 0;
	printf("<");
	for (i = 0; i < top; i++) {
		printf("%d", arr1[i]);
		if (i != top - 1)printf(", ");
	}printf(">");
}
int main() {
	int arr[5000];
	int max, count;
	int i = 0;
	scanf("%d %d", &max, &count);
	while (i++ < max)arr[i-1] = i;
	while (max > 0) {
		pop(count, max, arr);
		max--;
	}
	print();
	return 0;
}