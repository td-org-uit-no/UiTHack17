# The renaissance of cryptography

> Crypto - 300pts

## Writeup

Given the cipher text:
`VmESauy{qswjaddiemptaq_tymdtahvxtzn_uwqlpcs_uoo_fp_sajr}`

This is a polyalphabetic substitution cipher - specifically a vigenere cipher.
Use knowledge of flag format to execute a known-plaintext attack and use the extracted key to decrypt the flag.
The known plaintext will reveal the key `BELLASO`.


Using [dcode](http://www.dcode.fr/vigenere-cipher), the cipher text can be dercypted, yielding the flag:
`UiTHack{polyalphabetic\_substitution\_ciphers\_can\_be\_hard}`
