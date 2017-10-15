# Level 5

> Noob - 150pts

Connect to the following machine using __ssh__:

IP: `95.85.33.80`
Username: `noob-5`
The password is the flag you retrieved in level 4.

Once logged in, find a file owned by the user root and the group noob-5, and in it, you will find the unique flag.

The __flag__ for this challenge is the password for level 6

## Writeup

- Find the file with the correct properties

```
[noob-5@uithack-noob  ]$ find / -group noob-5 -user root 2> /dev/null
/usr/lib/kernel/is_this_the_file?
/home/noob-5
/home/noob-5/.bash_profile
/home/noob-5/.cloud-locale-test.skip
/home/noob-5/.bash_logout
/home/noob-5/.bashrc
```

- Sort the flag haystack and find the unique flag in it

```
[noob-5@uithack-noob ~]$ sort /usr/lib/kernel/is_this_the_file\? | uniq -u
UiTHack{PoC||GTFO}
```

Yielding the flag:

`UiTHack{PoC||GTFO}`
