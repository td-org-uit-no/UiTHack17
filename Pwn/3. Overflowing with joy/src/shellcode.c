#include <stdio.h>
#include <string.h>

void overflow(void)
{
	char buf[200] = { 0 };
	fprintf(stderr, "Address of the buffer: %p\n", buf);
	scanf("%s", buf);
	fprintf(stderr, "%s\n", buf);
}

int main(void)
{
	overflow();
	return 0;
}
