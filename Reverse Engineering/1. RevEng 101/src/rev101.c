#include <stdio.h>
#include <string.h>

static const char *flag = "UiTHack{strings_are_good}";
static const char *password = "please_let_me_in";

int main(void)
{
	char buf[100] = { 0 };
	printf("Enter password: ");
	scanf("%s", buf);
	
	if (!strcmp(buf, password)) {
		printf("Congratulations, the flag is: %s\n", flag);
		return 0;
	} else {
		printf("I am sorry, please try again\n");
		return 1;
	}
}