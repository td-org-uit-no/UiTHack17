# No strings here

> > Reverse Engineering - 350pts
> 
> The game has been stepped up, are you still able to get the flag?
> 
> File: [no_strings](./no_strings)

## Writeup

As the title suggest, there are no plain-text strings in the binary, but we can see that it is using `strcmp`.
The input to it can be determined by executing

`ltrace ./no_strings`

Which reveal that your password is compared against `dette_er_ikke_passordet`, which is the password.
Entering that password into the binary yield the flag:

`UiTHack{"ikke_like_lett"}`
