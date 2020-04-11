#include <stdio.h>

// reads how many symbols are in the file
void chCount(){
	long nc = 0;
	int c;

	while ((c = getchar()) != EOF)
	{
		nc++;
	}
	printf("%ld", nc);
}

void lnCount(){
	int ln,c = 0;
	
	while((c = getchar()) != EOF){
		if (c == '\n')
		{
			++ln;
		}
	}
	printf("%d\n", ln);
}

void evCount()
{
	int ev, c = 0;

	while ((c = getchar()) != EOF)
	{
		if ((c == '\n') || (c == '\t') || (c == ' '))
		{
			++ev;
		}
	}
	printf("%d\n", ev);
}

void copy(){
	int c, inspace = 0;

	while ((c = getchar()) != EOF)
	{
		if ((c == ' ')&&(inspace == 0))
		{	
			inspace = 1;
			putchar(c);
		}else if(c != ' '){
			inspace = 0;
			putchar(c);
		}
	}
}
void changeSpecialSymbols()
{
	int c = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\\')
		{
			putchar('\\' + '\\');
		}
		// else if (c != ' ')
		// {
		// 	inspace = 0;
		// 	putchar(c);
		// }
	}
}

int main(){
	copy();
	return 0;
}
