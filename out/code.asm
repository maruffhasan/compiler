format ELF executable 3
entry main


segment readable executable
func:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 128
	; -- line 3 --
	MOV EAX, [EBP+8]
	PUSH EAX
	MOV EAX, 0
	POP EBX
	CMP EBX, EAX
	JE L_rel_true_0
	MOV EAX, 0
	JMP L_rel_end_1
L_rel_true_0:
	MOV EAX, 1
L_rel_end_1:
	CMP EAX, 0
	JE L_if_end_2
	; -- line 3 --
	MOV EAX, 0
	JMP func_exit
L_if_end_2:
	; -- line 4 --
	MOV EAX, [EBP+8]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 5 --
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 1
	PUSH EAX
	MOV EAX, [EBP+8]
	POP EBX
	SUB EAX, EBX
	PUSH EAX
	CALL func
	POP EBX
	ADD EAX, EBX
	JMP func_exit
func_exit:
	ADD ESP, 128
	POP EBP
	RET 4

segment readable executable
func2:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 128
	; -- line 10 --
	MOV EAX, [EBP+8]
	PUSH EAX
	MOV EAX, 0
	POP EBX
	CMP EBX, EAX
	JE L_rel_true_3
	MOV EAX, 0
	JMP L_rel_end_4
L_rel_true_3:
	MOV EAX, 1
L_rel_end_4:
	CMP EAX, 0
	JE L_if_end_5
	; -- line 10 --
	MOV EAX, 0
	JMP func2_exit
L_if_end_5:
	; -- line 11 --
	MOV EAX, [EBP+8]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 12 --
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 1
	PUSH EAX
	MOV EAX, [EBP+8]
	POP EBX
	SUB EAX, EBX
	PUSH EAX
	CALL func
	POP EBX
	ADD EAX, EBX
	JMP func2_exit
func2_exit:
	ADD ESP, 128
	POP EBP
	RET 4

segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 128
	; -- line 17 --
	MOV EAX, 7
	PUSH EAX
	CALL func
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 18 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 19 --
	MOV EAX, 0
	JMP main_exit
main_exit:
	ADD ESP, 128
	POP EBP
	MOV EAX, 1
	XOR EBX, EBX
	INT 0x80

OUTDEC:
	PUSH EBX
	PUSH ECX
	PUSH EDX
	PUSH ESI
	OR EAX, EAX
	JGE OUTDEC_POSITIVE
	NEG EAX
	PUSH EAX
	SUB ESP, 4
	MOV byte [ESP], '-'
	MOV EAX, 4
	MOV EBX, 1
	MOV ECX, ESP
	MOV EDX, 1
	INT 0x80
	ADD ESP, 4
	POP EAX
OUTDEC_POSITIVE:
	XOR ECX, ECX
	MOV EBX, 10
OUTDEC_DIGIT_LOOP:
	XOR EDX, EDX
	DIV EBX
	ADD DL, 30h
	PUSH EDX
	INC ECX
	TEST EAX, EAX
	JNZ OUTDEC_DIGIT_LOOP
OUTDEC_PRINT_LOOP:
	TEST ECX, ECX
	JZ OUTDEC_NEWLINE
	PUSH ECX
	MOV EAX, 4
	MOV EBX, 1
	LEA ECX, [ESP+4]
	MOV EDX, 1
	INT 0x80
	POP ECX
	ADD ESP, 4
	DEC ECX
	JMP OUTDEC_PRINT_LOOP
OUTDEC_NEWLINE:
	SUB ESP, 4
	MOV byte [ESP], 10
	MOV EAX, 4
	MOV EBX, 1
	MOV ECX, ESP
	MOV EDX, 1
	INT 0x80
	ADD ESP, 4
	POP ESI
	POP EDX
	POP ECX
	POP EBX
	RET
