# Wierd code

> > Misc - 200pts
> 
> ASCII also seemed strange at times...
> 
> Are you able to extract the information?
> 
> File: [wierd_code]

## Writeup

Running `file wierd_code`, you can see the file is EBCDIC, and might even that it is EBCDIC-encoded C source code.
First convert from EBCDIC to ASCII:

`dd if=wierd_code conv=ascii of=ebcdic.c`

Then compile the C source:

`cc -trigraphs ebcdic.c -o ebcdic`

Finally run the executable:

`./ebcdic`
