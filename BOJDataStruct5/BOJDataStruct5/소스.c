#include <stdio.h>
#pragma warning(disable:4996)
char stack[51];
int top = -1;
void push(char x) {
	stack[++top] = x;
}
char pop() {
	char  num;
	if (top < 0) return 0;
	num = stack[top--];
	return num;
}
void checkTop() {
	if (top == -1) printf("YES\n");
	else printf("NO\n");
}
int main() {
	int num = 0;
	int  i = 0;
	char c = 0;
	char str[51] = { 0 };

	scanf("%d", &num);
	while (num--) {
		scanf("%s", str);
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(') {
				push(str[i]);
			}
			else if (str[i] == ')') {
				c = pop();
				if (!c) {
					push(str[i]);
				}
				else if (c == ')') {
					push(c);
					break;
				}
			}
		}
		checkTop();
		top = -1;
	}

	return 0;
}