# You spin my head right round, right round

> > Crypto - 150pts
> 
> We intercepted this secret message, but we are unable to determine it's contents, can you help?
> ```
> NbMAtvd{khmtmbhg_vbiaxkl_tkx_twwbmbox}
> ```

## Writeup

This is a basic rotation cipher affecting the alphabet.

To solve:
`tr t-za-sT-ZA-S a-zA-Z < challenge.txt`
 Yielding `UiTHack{rotation_ciphers_are_additive}`
