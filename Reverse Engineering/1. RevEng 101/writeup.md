# RevEng 101

> > Reverse Engineering - 200pts
> 
> Are you able to extract the flag from the program?
> 
> File: [rev101](./rev101)

## Writeup

The executable might contain static strings, and extracting all strings from it, using Radare2:

`r2 -c iz rev101` or simply `strings rev101`

Running either will reveal the flag `UiTHack{strings_are_good}`.
