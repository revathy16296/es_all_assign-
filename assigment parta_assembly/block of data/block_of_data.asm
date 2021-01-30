	AREA block,CODE,READONLY
	entry
	ldr r0,=0x40000000
	ldr r1,=0x4000f000
	mov r2,#0x0A
loop	ldr r3,[r0],#0x04
	str r3,[r0],#0x04
	sub r2,r2,#1
	cmp r2,#00
	bne loop
	end
