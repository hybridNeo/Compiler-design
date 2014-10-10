#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
typedef struct symbol{
	int val;
	char *name;
	struct symbol *next;
}symbol;
symbol *head;
head = (symbol *)malloc(sizeof(symbol));
void symCheck(char *a){
	printf("%s\n",a);
}
}

