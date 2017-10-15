CC = gcc
CFLAGS = -Wall -Wextra -fno-stack-protector -z execstack -no-pie -m32

SHELLCODE = shellcode
PWN = pwn_shellcode.py

.PHONY: all clean pwn
all: $(SHELLCODE)

$(SHELLCODE): $(SHELLCODE).c
	$(CC) $(CFLAGS) $^ -o $@

pwn: $(PWN) $(SHELLCODE)
	./$<

clean:
	@rm -fv $(SHELLCODE)
