#include <stdio.h>

int main(int argc, char **argv)
{
	char c;
	while (++argv != NULL) {
		if (isnum(**argv))
			push(atof(*argv));
		else {
			switch(**argv) {
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
