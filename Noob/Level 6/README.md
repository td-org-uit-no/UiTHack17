# Level 6

> Noob - 350pts

Connect to the following machine using __ssh__:

IP: `95.85.33.80`
Username: `noob-6`
The password is the flag you retrieved in level 5.

Once logged in, find a flag hidden in the home directory

This is the final level, so congratulations if you were able to complete it!

## Writeup

- Trying to log into noob-6, we seem to be automatically logged out

```
[noob-5@uithack-noob ~]$ ssh noob-6@localhost
noob-6@localhost's password: 
Last login: Sun Oct 15 20:50:02 2017 from uithack-noob
Welcome to the final noob challenge..

 __    __  __  ________  __    __                      __       
|  \  |  \|  \|        \|  \  |  \                    |  \      
| $$  | $$ \$$ \$$$$$$$$| $$  | $$  ______    _______ | $$   __ 
| $$  | $$|  \   | $$   | $$__| $$ |      \  /       \| $$  /  \
| $$  | $$| $$   | $$   | $$    $$  \$$$$$$\|  $$$$$$$| $$_/  $$
| $$  | $$| $$   | $$   | $$$$$$$$ /      $$| $$      | $$   $$ 
| $$__/ $$| $$   | $$   | $$  | $$|  $$$$$$$| $$_____ | $$$$$$\ 
 \$$    $$| $$   | $$   | $$  | $$ \$$    $$ \$$     \| $$  \$$\
  \$$$$$$  \$$    \$$    \$$   \$$  \$$$$$$$  \$$$$$$$ \$$   \$$
                                                                
                                                                
                                                                
The flag is: UiTHack{this_flag_is_super_duper_rekt_you_wont_find_it_at_all}
Connection to localhost closed.
```

- Let us see what the login shell for `noob-6` is

```
[noob-5@uithack-noob ~]$ grep noob /etc/passwd
noob-1:x:1000:1000::/home/noob-1:/bin/bash
noob-2:x:1001:1001::/home/noob-2:/bin/bash
noob-3:x:1002:1002::/home/noob-3:/bin/bash
noob-4:x:1003:1003::/home/noob-4:/bin/bash
noob-5:x:1004:1004::/home/noob-5:/bin/bash
noob-6:x:1005:1005::/home/noob-6:/usr/bin/noob-login
```

- See what the login shell does

```
[noob-5@uithack-noob ~]$ cat /usr/bin/noob-login 
#!/bin/sh

DIR=$(mktemp)
sed -e 's/not_scrambled/super_duper_rekt_you_wont_find_it/' flag.txt > $DIR
more $DIR
rm -rf $DIR
```

- From this, we can see the script will read the flag and substitutes a part of it
- Substituting back, we get

```
[noob-5@uithack-noob ~]$ echo "UiTHack{this_flag_is_super_duper_rekt_you_wont_find_it_at_all}" | sed -e 's/super_duper_rekt_you_wont_find_it/not_scrambled/'
UiTHack{this_flag_is_not_scrambled_at_all}
```

Yielding the flag

`UiTHack{this_flag_is_not_scrambled_at_all}`
