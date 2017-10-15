# Cover all the bases

> > Crypto - 100pts
> 
> The following string was discovered, can you figure out what it says:
> 
> ```
> KVUVISDBMNVXW2LOL54W65LSL5RGC43FL5VWS3DMNFXGOX3ZN52XEX3EN5XWI435
> ```

## Writeup

The challenge is base32-encoded.

To solve:
`base32 -d < challenge.txt`
Yielding `UiTHack{in_your_base_killing_your_doods}`
