# Ascii and a single dot?

> > Misc - 300pts
> 
> Are you able to interpret the message?
> 
> ```
>                   .
>                   |
>                   $
>                   "
>   /-----\         U
>   |     "         i
>   \$"some}"&      T
>    /\/\ w         H
>    ||$| a         "
>    ||"| _         |
>    ||s\"e{kca"$---/
>    ||o  "
>    ||l  $
>    ||a  \-"ra_sg"$\
>    ||n /----------/
>    ||"//
>    |\/|
>    \--/
> ```

## Writeup

After some searching, we discover this is ascii-dots, which can be pasted into an [online interpreter](https://asciidots.herokuapp.com/).
Running the program through the interpreter yields

```
UiTH
ack{e
solan
gs_ar
e_awe
some}
```

Revealing the flag:

`UiTHack{esolangs_are_awesome}`
