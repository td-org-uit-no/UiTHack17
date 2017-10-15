#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/ptrace.h>

/* flag: UiTHack{Gratulerer_som_mester_reverser!} */
/*char flag[] = {85, 105, 84, 72, 97, 99, 107, 123, 71, 114, 97, 116, 117, 108, 101, 114, 101, 114, 95, 115, 111, 109, 95, 109, 101, 115, 116, 101, 114, 95, 114, 101, 118, 101, 114, 115, 101, 114, 33, 125};*/
char xor_encoded_flag[] = {35, 34, 102, 100, 13, 84, 38, 2, 156, 80, 42, 163, 9, 234, 174, 131, 55, 21, 45, 186, 73, 192, 109, 32, 57, 140, 234, 71, 194, 64, 47, 237, 67, 41, 76, 8, 167, 83, 66, 232};
char xor_key_flag[] = {118, 75, 50, 44, 108, 55, 77, 121, 219, 34, 75, 215, 124, 134, 203, 241, 82, 103, 114, 201, 38, 173, 50, 77, 92, 255, 158, 34, 176, 31, 93, 136, 53, 76, 62, 123, 194, 33, 99, 149};

/* pass: jeg_trenger_ikke_reverse */
/*char pass[] = {106, 101, 103, 95, 116, 114, 101, 110, 103, 101, 114, 95, 105, 107, 107, 101, 95, 114, 101, 118, 101, 114, 115, 101};*/
char xor_key_pass[] = {121, 155, 205, 140, 254, 86, 63, 230, 183, 155, 196, 53, 115, 66, 138, 92, 130, 182, 144, 18, 229, 243, 117, 89};
char xor_encoded_pass[] = {19, 254, 170, 211, 138, 36, 90, 136, 208, 254, 182, 106, 26, 41, 225, 57, 221, 196, 245, 100, 128, 129, 6, 60};

/*
 * Weakness:
 * - All data required to create password and flag are present
 * - User can (during debugging) change the failure to print string
 *
 * Solution:
 * - During debugging, realize that the xor-operation is decoding the password when comparing it to the user-supplied input
 * - During debugging, after the comparison; alter the value of failure and set it to false, printing the flag
 *
 * Strengthening(if necessary):
 * - Do not store data that directly can construct the flag or passphrase, but rather use the input passphrase to create flag
 */
int main(void)
{
	/* Make sure we are not being traced */
	if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
		puts("No trace for you :)");

	char buf[100] = { 0 };
	printf("Enter password: ");
	scanf("%100s", buf);
	
	/* Constant-time comparison */
	volatile bool failure = false;
	for (size_t i = 0; i < sizeof(xor_encoded_pass); i++) {
		if (buf[i] ^ xor_key_pass[i] ^ xor_encoded_pass[i]) {
			/* Failure = true */
			failure = (failure ? true : true);
		} else {
			/* Failure = failure */
			failure = (failure ? true : false);
		}
	}
	
	/* Determine if comparison yielded equality or inequality */
	if (failure) {
		printf("I am sorry, please try again\n");
		return 1;
	} else {
		printf("Congratulations, the flag is: ");
		for (size_t i = 0; i < sizeof(xor_encoded_flag); i++) {
			putchar(xor_encoded_flag[i] ^ xor_key_flag[i]);
		}
		putchar('\n');
		return 0;
	}
}
