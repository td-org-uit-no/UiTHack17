# Level 2

> Noob - 50pts

Connect to the following machine using __ssh__:

IP: `95.85.33.80`
Username: `noob-2`
The password is the flag you retrieved in level 1.

Once logged in, find a flag hidden in the home directory

The __flag__ for this challenge is the password for level 3

## Writeup

- List hidden files with `ls -lah` and view file contents

```
[noob-2@uithack-noob ~]$ ls -lah
total 24K
drwxr-x---  2 root noob-2 4.0K Aug 18 08:05 .
drwxr-xr-x. 8 root root   4.0K Aug 18 08:34 ..
-rw-r-----  1 root noob-2   18 Dec  6  2016 .bash_logout
-rw-r-----  1 root noob-2  193 Dec  6  2016 .bash_profile
-rw-r-----  1 root noob-2  231 Dec  6  2016 .bashrc
-rw-r-----  1 root noob-2    0 Aug 18 07:53 .cloud-locale-test.skip
-rw-r-----  1 root noob-2   76 Aug 18 08:06 .very_secret_file
[noob-2@uithack-noob ~]$ cat .very_secret_file 
username: noob-3
password: UiTHack{tho_shant_guess_this_passphrase_neither}
```

Yielding the flag:

`UiTHack{tho_shant_guess_this_passphrase_neither}`
