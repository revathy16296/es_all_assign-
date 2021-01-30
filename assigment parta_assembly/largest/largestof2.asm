	AREA largest,CODE,READONLY
	ENTRY
main
	LDR R0,=data
	LDR R3,=0x40000000
	LDR R1,[R0],#04
loop
	LDR R2,[R0]
	CMP	R1,R2
	BGE large
	MOV R1,R2
large
	STR R1,[R3]
	swi &11
data	DCD &05,&56
	END