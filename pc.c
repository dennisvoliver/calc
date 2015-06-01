#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct stack{
	double val;
	struct stack *next;
	struct stack *prev;
} BASE = {0, NULL, NULL};
struct stack *now = &BASE;

void push(double x)
{
	now->next = (struct stack *)malloc(sizeof(struct stack));
	now->next->prev = now;
	now->next->val = x;
	now->next->next = NULL;
	now = now->next;
}
double pop(void)
{
	if (now == &BASE)
		return 0;
	double tmp = now->val;
	struct stack *prev = now->prev;
	free(now);
	now = prev;
	now->next = NULL;
	return tmp;
}

int op(int c)
{
	double tmp;
	switch(c) {
		case '+':
			push(pop() + pop());
			break;
		case '-' :
			tmp = pop();
			push(pop() - tmp);
			break;
		case '*' :
			push(pop() * pop());
			break;
		case '/' :
			if ((tmp = pop()) != 0)
				push(pop() / tmp);
			else
				return -1;
				break;
		case '^' :
			tmp = pop();
			push(pow(pop(), tmp));
			break;
	}

	return 0;
}
/* an extremely simple and weak reverse polish calculator that reads from argv and not stdin */
int main(int argc, char **argv)
{
	char c;
	while (--argc > 0) {
		if (isdigit(**++argv))
			push(atof(*argv));
		else if(op(**argv) != 0)
			return -1;
	}
	printf("%g\n", pop());
	return 0;
}
