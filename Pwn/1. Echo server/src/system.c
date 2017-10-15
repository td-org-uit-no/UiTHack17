#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	size_t nbytes = 0;
	char *line = NULL;
	const char *python = "python2 -c 'print ";
	
	while (getline(&line, &nbytes, stdin) != -1) {
		/* 
		 * Allocate buffer with room for both python command, read line and
		 * 2 chars - one for a quote and the last for the null-terminator
		 */
		line[strlen(line)-1] = '\0';
		size_t bufsize = strlen(python) + strlen(line) + 2;
		char *buf = calloc(bufsize, sizeof(*buf));
		snprintf(buf, bufsize, "%s%s'", python, line);
		
		system(buf);
	}

	return 0;
}
