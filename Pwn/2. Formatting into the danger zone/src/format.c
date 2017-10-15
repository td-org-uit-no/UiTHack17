#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char *password = "Let's all be nice to one another!";

bool read_and_compare(void)
{
	char *line = NULL;
	size_t len = 0;
	fputs("Enter password: ", stderr);
	if (getline(&line, &len, stdin) != -1) {
		fprintf(stderr, "You entered: ");
		fprintf(stderr, line);
		if (strncmp(password, line, strlen(password)) == 0) {
			free(line);
			return true;
		}
	}
	free(line);
	return false;
}

void might_print(const char* flag)
{
	if (read_and_compare() == true) {
		fprintf(stderr, "Which was the right password: %s\n", flag);
	} else {
		fputs("Which was wrong..", stderr);
	}
}

int main(void)
{
	char *flag = "UiTHack{format_strings_can_be_scary}";
	might_print(flag);

	return 0;
}
