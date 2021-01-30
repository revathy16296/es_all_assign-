	TTL splitbyte
	AREA program,CODE,READONLY
	ENTRY
Main
	LDR R1,value
	MOV R3,R1,LSR#0x8
	LDR R2,mask
	AND R1,R1,R2
	MOV R1,R1,LSL#0x8
	ADD R1,R1,R3
	STR R1,result
	SWI &11
value	DCD &FBDD
mask		DCD &00FF
result	DCD 0
		END

