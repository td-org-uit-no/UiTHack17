# The new school of cryptography

> Crypto - 500pts

## Writeup

This is RSA, and we have `n`, `e` and `c`. Because `c` and `e` are small, we can check if the plaintext was so small that `p^e < n`, and to to decrypt the ciphertext that way.

We can verify this by executing the following sage script:
```python
p_guess = c.nth_root(e)
if p_guess.powermod(e, n) == c:
	print "Guessed correct p: %d" % p_guess
```

This mean that the modulo with `n` has no effect, and `c = p^e`, meaning `p` can be recovered by computing the e-th root of `c` and converting it back to ASCII.

After which the text can be retrieved.
The ciphertext can be decoded by execiting the following snippet of sage:
```python
from binascii import unhexlify
print unhexlify(hex(c.nth_root(e)))
```

Yielding the flag
`UiT{security_require_proper_usage}`
