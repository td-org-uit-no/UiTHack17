# No trace for you

> > Reverse Engineering - 700pts
> 
> It seems like assembly must be read!
> 
> Are you still able to retrieve the flag?
> 
> File: [no_trace](./no_trace)

## Writeup

Tracing this will be of no use, as it does  not use any library functions for comparison.

This can be solved dynamically by skipping the comparison alltogether, or by patching the jump opcode after the comparson.
It can also be solved statically by performing the XOR operation to retrieve the flag.

Assuming the flag is located at the two locations `0x201080` and `0x2010c0`, we can decode it using Radare:

```
➤ r2 -c "e io.cache=true; wox `p8 64 @ 0x2010c0` @ 0x201080; ps @ 0x201080" no_trace
UiTHack{Gratulerer_som_mester_reverser!}
```

- `e io.cache=true` is to allow the file only in-memory
- `p8 64 @ 0x2010c0` prints a 64 byte long sequence of hex-encoded bytes
- `wox <hex-string> @ 0x201080` XOR's the memory at `0x201080` with the given hex string
- `ps @ 0x201080` prints the string located at 0x201080

Yielding the flag:

`UiTHack{Gratulerer_som_mester_reverser!}`
