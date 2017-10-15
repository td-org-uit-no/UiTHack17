# Level 3

> Noob - 100pts

Connect to the following machine using __ssh__:

IP: `95.85.33.80`
Username: `noob-3`
The password is the flag you retrieved in level 2.

Once logged in, find the flag hidden in a large haystack.
The __flag__ for this challenge is the password for level 4

## Writeup

- Find the hidden directory with the flag haystack:

```
[noob-3@uithack-noob ~]$ ls -lah
total 24K
drwxr-x---  3 root noob-3 4.0K Aug 18 08:32 .
drwxr-xr-x. 8 root root   4.0K Aug 18 08:34 ..
-rw-r-----  1 root noob-3   18 Dec  6  2016 .bash_logout
-rw-r-----  1 root noob-3  193 Dec  6  2016 .bash_profile
-rw-r-----  1 root noob-3  231 Dec  6  2016 .bashrc
-rw-r-----  1 root noob-3    0 Aug 18 07:53 .cloud-locale-test.skip
drwxr-x---  2 root noob-3 4.0K Aug 18 08:32 .hidden
[noob-3@uithack-noob ~]$ cd .hidden
[noob-3@uithack-noob .hidden]$ ls -lah
total 4.7M
drwxr-x--- 2 root noob-3 4.0K Aug 18 08:32 .
drwxr-x--- 3 root noob-3 4.0K Aug 18 08:32 ..
-rw-r----- 1 root noob-3 4.7M Aug 18 08:31 flags.txt
```

- Search through the haystack for flags

```
[noob-3@uithack-noob .hidden]$ grep UiTHack flags.txt 
UiTHack{insecurity}
```

Yielding the flag:

`UiTHack{insecurity}`
