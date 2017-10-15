# Level 4

> Noob - 125pts

Connect to the following machine using __ssh__:

IP: `95.85.33.80`
Username: `noob-4`
The password is the flag you retrieved in level 3.

Once logged in, find the correct flag in a large haystack of flags.
The correct flag is the __alphabetically first__ flag __in the last 1337__ lines of the haystack

The __flag__ for this challenge is the password for level 5

## Writeup

- Search for the haystack within hidden directories

```
[noob-4@uithack-noob ~]$ ls -lah
total 24K
drwxr-x---  3 root noob-4 4.0K Aug 18 08:22 .
drwxr-xr-x. 8 root root   4.0K Aug 18 08:34 ..
-rw-r-----  1 root noob-4   18 Dec  6  2016 .bash_logout
-rw-r-----  1 root noob-4  193 Dec  6  2016 .bash_profile
-rw-r-----  1 root noob-4  231 Dec  6  2016 .bashrc
-rw-r-----  1 root noob-4    0 Aug 18 07:53 .cloud-locale-test.skip
drwxr-x---  3 root noob-4 4.0K Aug 18 08:24 .flags?
[noob-4@uithack-noob ~]$ cd .flags\?/
[noob-4@uithack-noob .flags?]$ ls -lah
total 12K
drwxr-x--- 2 root noob-4 4.0K Aug 18 08:24  
drwxr-x--- 3 root noob-4 4.0K Aug 18 08:24 .
drwxr-x--- 3 root noob-4 4.0K Aug 18 08:22 ..
[noob-4@uithack-noob .flags?]$ cd \ 
[noob-4@uithack-noob  ]$ ls -lah
total 8.7M
drwxr-x--- 2 root noob-4 4.0K Aug 18 08:24 .
drwxr-x--- 3 root noob-4 4.0K Aug 18 08:24 ..
-rw-r----- 1 root noob-4 8.7M Aug 18 08:21 flags.txt
```

- Retrieve the last 1337 lines of the haystack, sort it and take the first line

```
[noob-4@uithack-noob  ]$ tail -1337 flags.txt | sort | head -1
UiTHack{abstract-syntax-tree}
```

Yielding the flag:

`UiTHack{abstract-syntax-tree}`
