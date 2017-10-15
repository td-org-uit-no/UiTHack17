#include <stdio.h>
#include <string.h>
#include <assert.h>

/*char flag[] = {85, 105, 84, 72, 97, 99, 107, 123, 34, 105, 107, 107, 101, 95, 108, 105, 107, 101, 95, 108, 101, 116, 116, 34, 125};*/
char xor_encoded_flag[] = {17, 210, 95, 0, 182, 66, 136, 138, 116, 214, 186, 17, 225, 81, 60, 92, 248, 41, 221, 222, 102, 157, 1, 177, 115};
char xor_key_flag[] = {68, 187, 11, 72, 215, 33, 227, 241, 86, 191, 209, 122, 132, 14, 80, 53, 147, 76, 130, 178, 3, 233, 117, 147, 14};

/*char pass[] = {100, 101, 116, 116, 101, 95, 101, 114, 95, 105, 107, 107, 101, 95, 112, 97, 115, 115, 111, 114, 100, 101, 116};*/
char xor_key_pass[] = {222, 180, 84, 139, 178, 120, 184, 221, 229, 25, 175, 191, 32, 243, 166, 24, 203, 137, 55, 191, 201, 244, 115};
char xor_encoded_pass[] = {186, 209, 32, 255, 215, 39, 221, 175, 186, 112, 196, 212, 69, 172, 214, 121, 184, 250, 88, 205, 173, 145, 7};
char xor_decoded_pass[] = { 0 };


void print_flag(void)
{
	printf("Congratulations, the flag is: ");
	for (int i = 0; i < sizeof(xor_encoded_flag); i++) {
		putchar(xor_encoded_flag[i] ^ xor_key_flag[i]);
	}
	putchar('\n');
}

int main(void)
{
	char buf[100] = { 0 };
	printf("Enter password: ");
	scanf("%s", buf);
	
	for (int i = 0; i < sizeof(xor_encoded_pass); i++) {
		xor_decoded_pass[i] = xor_encoded_pass[i] ^ xor_key_pass[i];

	}
	
	if (!strcmp(buf, xor_decoded_pass)) {
		print_flag();
		return 0;
	} else {
		printf("I am sorry, please try again\n");
		return 1;
	}
}