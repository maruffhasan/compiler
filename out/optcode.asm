format ELF executable 3
entry main
segment readable writeable
segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 4
.L1:
	MOV EAX, 5       ; Line 3
	MOV [EBP-4], EAX
.L2:
.L3:
	MOV EAX, [EBP-4]       ; Line 4
	CMP EAX, 0
	JNE .L4
	JMP .L6
.L4:
	MOV EAX, [EBP-4]       ; Line 5
	PUSH EAX
	DEC EAX
	MOV [EBP-4], EAX
	POP EAX
.L5:
	JMP .L3
.L6:
.L7:
	ADD ESP, 4
	POP EBP
	MOV EAX,1
	XOR EBX, EBX
	INT 0x80
	POP EBP
	RET
