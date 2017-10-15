# Overflowing with joy

> > Pwn - 600pts
> 
> Connect to the machine at and try to exploit my joyful echo server: `207.154.215.146:1337`
> 
> Are you able to pwn it?
> 
> PS: connect using `nc <ip> <port>`
> 
> File: [shellcode](./shellcode)

## Writeup

Checking security and properties of the file, we see that it is a 32-bit binary and most security is disabled, without `nx` set, meaning the stack will be executable, pointing us in the direction of shellcode.

First, we need to determine the offset of the return address which we can use to control the flow of execution further.
Once that is determined, we need to create shellcode that will do what we want to, like spawning a shell.
The assembled shellcode will be placed in the buffer which will be returned to by setting the return address to the very start of the buffer.
One important thing to note is the way the program takes input, and make sure the assembled shellcode will not stop the program from receiving input.

A proof of concept is located in the [source](./src/) directory.
It takes advantage of the pwntools library for python 2.

After getting shell access, you can retrieve the flag:
```
➤ make pwn
./pwn_shellcode.py
[+] Opening connection to 207.154.215.146 on port 1337: Done
[*] Switching to interactive mode
����t$�^\x83�\x89����(ت\x80��u�U��E�T1\x18G\xb6��
$ cat flag
UiTHack{overflowing_made_great_again}
```

Yielding the flag:

`UiTHack{overflowing_made_great_again}`
