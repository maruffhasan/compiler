format ELF executable 3
entry main

segment readable writeable
i dd 1 dup (0)
segment readable writeable
j dd 1 dup (0)

segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 128
	; -- line 6 --
	MOV EAX, 1
	MOV [i], EAX
	; -- line 7 --
	MOV EAX, [i]
	CALL OUTDEC
	; -- line 9 --
	MOV EAX, 8
	PUSH EAX
	MOV EAX, 5
	POP EBX
	ADD EAX, EBX
	MOV [j], EAX
	; -- line 10 --
	MOV EAX, [j]
	CALL OUTDEC
	; -- line 12 --
	MOV EAX, [j]
	PUSH EAX
	MOV EAX, 2
	POP EBX
	IMUL EAX, EBX
	PUSH EAX
	MOV EAX, [i]
	POP EBX
	ADD EAX, EBX
	MOV [EBP-4], EAX
	; -- line 13 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 15 --
	MOV EAX, 9
	PUSH EAX
	MOV EAX, [EBP-4]
	POP EBX
	XOR EDX, EDX
	IDIV EBX
	MOV EAX, EDX
	MOV [EBP-12], EAX
	; -- line 16 --
	MOV EAX, [EBP-12]
	CALL OUTDEC
	; -- line 18 --
	MOV EAX, [EBP-12]
	PUSH EAX
	MOV EAX, [EBP-8]
	POP EBX
	CMP EBX, EAX
	JLE L_rel_true_0
	MOV EAX, 0
	JMP L_rel_end_1
L_rel_true_0:
	MOV EAX, 1
L_rel_end_1:
	MOV [EBP-16], EAX
	; -- line 19 --
	MOV EAX, [EBP-16]
	CALL OUTDEC
	; -- line 21 --
	MOV EAX, [i]
	PUSH EAX
	MOV EAX, [j]
	POP EBX
	CMP EBX, EAX
	JNE L_rel_true_2
	MOV EAX, 0
	JMP L_rel_end_3
L_rel_true_2:
	MOV EAX, 1
L_rel_end_3:
	MOV [EBP-20], EAX
	; -- line 22 --
	MOV EAX, [EBP-20]
	CALL OUTDEC
	; -- line 24 --
	MOV EAX, [EBP-16]
	CMP EAX, 0
	JNE L_bool_true_4
	MOV EAX, [EBP-20]
	CMP EAX, 0
	JNE L_bool_true_4
L_bool_false_5:
	MOV EAX, 0
	JMP L_bool_end_6
L_bool_true_4:
	MOV EAX, 1
L_bool_end_6:
	MOV [EBP-24], EAX
	; -- line 25 --
	MOV EAX, [EBP-24]
	CALL OUTDEC
	; -- line 27 --
	MOV EAX, [EBP-16]
	CMP EAX, 0
	JE L_bool_false_8
	MOV EAX, [EBP-20]
	CMP EAX, 0
	JE L_bool_false_8
L_bool_true_7:
	MOV EAX, 1
	JMP L_bool_end_9
L_bool_false_8:
	MOV EAX, 0
L_bool_end_9:
	MOV [EBP-24], EAX
	; -- line 28 --
	MOV EAX, [EBP-24]
	CALL OUTDEC
	MOV EAX, [EBP-24]
	INC dword [EBP-24]
	; -- line 31 --
	MOV EAX, [EBP-24]
	CALL OUTDEC
	; -- line 33 --
	MOV EAX, [EBP-24]
	NEG EAX
	MOV [EBP-4], EAX
	; -- line 34 --
	MOV EAX, [EBP-4]
	CALL OUTDEC
	; -- line 36 --
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
