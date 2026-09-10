format ELF executable 3
entry main

segment readable writeable
w dd 10 dup (0)

segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 128
	; -- line 6 --
	MOV EAX, 2
	NEG EAX
	PUSH EAX
	POP EAX
	MOV [w], EAX
	; -- line 7 --
	MOV EAX, [w]
	PUSH EAX
	POP EAX
	MOV [EBP-8], EAX
	; -- line 8 --
	MOV EAX, [EBP-8]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 9 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 10 --
	MOV EAX, [w]
	INC dword [w]
	PUSH EAX
	POP EAX
	MOV [EBP-8], EAX
	; -- line 11 --
	MOV EAX, [EBP-8]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 12 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 13 --
	MOV EAX, [w]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 14 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 16 --
	MOV EAX, 0
	PUSH EAX
	MOV EAX, [EBP-4]
	POP EBX
	ADD EAX, EBX
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 17 --
	MOV EAX, 0
	PUSH EAX
	MOV EAX, [EBP-4]
	POP EBX
	SUB EAX, EBX
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 18 --
	MOV EAX, 1
	PUSH EAX
	MOV EAX, [EBP-4]
	POP EBX
	IMUL EAX, EBX
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	; -- line 19 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 21 --
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 0
	POP EBX
	CMP EBX, EAX
	JG L_rel_true_6
	MOV EAX, 0
	JMP L_rel_end_7
L_rel_true_6:
	MOV EAX, 1
L_rel_end_7:
	CMP EAX, 0
	JE L_bool_false_4
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 10
	POP EBX
	CMP EBX, EAX
	JL L_rel_true_8
	MOV EAX, 0
	JMP L_rel_end_9
L_rel_true_8:
	MOV EAX, 1
L_rel_end_9:
	CMP EAX, 0
	JE L_bool_false_4
L_bool_true_3:
	MOV EAX, 1
	JMP L_bool_end_5
L_bool_false_4:
	MOV EAX, 0
L_bool_end_5:
	CMP EAX, 0
	JNE L_bool_true_0
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 0
	POP EBX
	CMP EBX, EAX
	JL L_rel_true_13
	MOV EAX, 0
	JMP L_rel_end_14
L_rel_true_13:
	MOV EAX, 1
L_rel_end_14:
	CMP EAX, 0
	JE L_bool_false_11
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 10
	NEG EAX
	POP EBX
	CMP EBX, EAX
	JG L_rel_true_15
	MOV EAX, 0
	JMP L_rel_end_16
L_rel_true_15:
	MOV EAX, 1
L_rel_end_16:
	CMP EAX, 0
	JE L_bool_false_11
L_bool_true_10:
	MOV EAX, 1
	JMP L_bool_end_12
L_bool_false_11:
	MOV EAX, 0
L_bool_end_12:
	CMP EAX, 0
	JNE L_bool_true_0
L_bool_false_1:
	MOV EAX, 0
	JMP L_bool_end_2
L_bool_true_0:
	MOV EAX, 1
L_bool_end_2:
	CMP EAX, 0
	JE L_else_17
	; -- line 22 --
	MOV EAX, 100
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	JMP L_if_end_18
L_else_17:
	; -- line 24 --
	MOV EAX, 200
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
L_if_end_18:
	; -- line 25 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 27 --
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
