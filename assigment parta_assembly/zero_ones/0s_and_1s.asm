	AREA zero,CODE,READONLY
	ENTRY
main
	LDR R0,=value
	LDR R1,[R0]
	MOV R2,#0x1F
loop	MOV R1,R1,LSR #1
	ADDCS R3,R3,#1
	ADDCC R4,R4,#1
	SUB R2,R2,#1
	CMP R2,#00
	BNE loop

	SWI &11
value	DCD &12345678
	END

	