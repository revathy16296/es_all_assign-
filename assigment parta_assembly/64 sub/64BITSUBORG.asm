	AREA sub,CODE,READONLY
	ENTRY
main
		LDR R0,=data
		LDR R1,[R0]
		LDR R2,[R0,#04]
		LDR R0,=value
		LDR R3,[R0]
		LDR R4,[R0,#04]
		SUBS R6,R2,R4
		SBC R5,R1,R3
		LDR R0,=result
		STR R5,[R0]	,#04
		STR R6,[R0]
		SWI	  &11
data	DCD &DDDDDDDD,&AAAACCCC
value	DCD &BBBBBBBB,&AAAAAAAA
result	DCD &0
	END


