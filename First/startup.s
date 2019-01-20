.global _start
_start:
stacktop: .word 0x20001000
.word reset
.word hang

reset:
	bl notmain
	b hang
.thumb_func
hang:   b .

.globl PUT32
PUT32:
	str r1,[r0]
	bx lr

.globl GET32
GET32:
	ldr r0,[r0]
	bx lr

.globl dummy
	dummy:
	bx lr

