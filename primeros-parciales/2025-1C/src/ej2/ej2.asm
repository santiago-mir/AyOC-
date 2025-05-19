extern strcmp
global invocar_habilidad

; Completar las definiciones o borrarlas (en este ejercicio NO serán revisadas por el ABI enforcer)
DIRENTRY_NAME_OFFSET EQU 0
DIRENTRY_PTR_OFFSET EQU 16
DIRENTRY_SIZE EQU 24

FANTASTRUCO_DIR_OFFSET EQU 0
FANTASTRUCO_ENTRIES_OFFSET EQU 8
FANTASTRUCO_ARCHETYPE_OFFSET EQU 16
FANTASTRUCO_FACEUP_OFFSET EQU 24
FANTASTRUCO_SIZE EQU 32

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio

section .text

; void invocar_habilidad(void* carta, char* habilidad);
; RDI -> puntero a la carta
; RSI -> habilidad a llamar
invocar_habilidad:
	; prologo
	push RBP
	mov RBP, RSP

	push R12
	push R13
	push R14
	push R15

	mov R12, RDI ; puntero a la card en R12
	mov R13, RSI ; habilidad en R13

	mov R14, QWORD[R12 + FANTASTRUCO_DIR_OFFSET] ; directorio en R14
	xor R15, R15
	mov R15W, WORD[R12 + FANTASTRUCO_ENTRIES_OFFSET] ; cant entries en R15W

	xor R9, R9 ; r9 nuestro contador

	ciclo:
		cmp R9W, R15W ; si son iguales, salgo y paso al sig arquetipo
		je siguiente_arquetipo

		mov RDI, QWORD[R14 + DIRENTRY_NAME_OFFSET] ; nombre a RDI
		mov RSI, R13 ; nombre de la habilidad
		push R9
		sub RSP, 8
		call strcmp
		add RSP, 8
		pop R9
		cmp RAX, 0
		je invocar
		inc R9 ; i + 1
		add R14, 8 ; sig posicion
		jmp ciclo
	

	siguiente_arquetipo:
		mov RDI, QWORD[R12 + FANTASTRUCO_ARCHETYPE_OFFSET] ; arquetipo en RDI
		cmp RDI, 0
		je fin
		mov RSI, R13
		call invocar_habilidad
		jmp fin


	invocar:
		mov RDI, R12 ; movemos la card a RDI
		mov RCX, QWORD[R14] ; entry
		mov RCX, QWORD[RCX + DIRENTRY_PTR_OFFSET] ; funcion
		call RCX


	fin:

	pop R15
	pop R14
	pop R13
	pop R12
	pop RBP
	ret 
