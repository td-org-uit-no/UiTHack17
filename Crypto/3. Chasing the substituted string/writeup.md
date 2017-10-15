# Chasing the substituted string

> > Crypto - 250pts
> 
> It seems they are becoming smarter, because this is even harder to decipher!
> 
> ```
> CuVOtsz{fcwfvuvcvunh_surolif_sth_wl_tvvtszlp_uh_kcqvurql_gtaf}
> ```

## Writeup

This is a monoalphabetic substitution cipher.
Use knowledge of flag format to execute a known-plaintext attack and decrypt one character at a time.

The resulting translation will be: 

| a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| t | w | s | p | l | y | e | o | u | x | z | q | k | h | n | r | b | i | f | v | c | j | g | m | a | d |

Which can be applied to the challenge to recreate the plaintext flag:

`tr twsplyeouxzqkhnrbifvcjgmadTWSPLYEOUXZQKHNRBIFVCJGMAD a-zA-Z < challenge.txt`

Yielding `UiTHack{substitution_ciphers_can_be_attacked_in_multiple_ways}`
