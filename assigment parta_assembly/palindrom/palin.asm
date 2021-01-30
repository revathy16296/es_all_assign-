	AREA palin,CODE,READONLY
	ENTRY
MAIN
	LDR R0,=VALUE
	ldr r1,[r0]
	ldr r3,val2
	and r2,r1,r3
	mov r1,r1,LSL#0X08
	AND r1,r1,r3
	mov r2,r2,LSL#0X08
	
	and r1,r1,r2
	
	
	SWI &11
VALUE	DCD &1221
val2	dcd &0000ff00
	end
	
	
	
	
	
	