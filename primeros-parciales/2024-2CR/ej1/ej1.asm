extern malloc
extern free
extern strcpy

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio

UNIT_NAME EQU 0
UNIT_COMBUSTIBLE EQU 12
UNIT_REFERENCIAS EQU 14
UNIT_SIZE EQU 16

section .text
; Marca un ejercicio como aún no completado (esto hace que no corran sus tests)
FALSE EQU 0
; Marca un ejercicio como hecho
TRUE  EQU 1

; Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - optimizar
global EJERCICIO_1A_HECHO
EJERCICIO_1A_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

; Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - contarCombustibleAsignado
global EJERCICIO_1B_HECHO
EJERCICIO_1B_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

; Marca el ejercicio 1C como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - modificarUnidad
global EJERCICIO_1C_HECHO
EJERCICIO_1C_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

; void optimizar(mapa_t mapa, attackunit_t *compartida, uint32_t (*fun_hash)(attackunit_t *))
; RDI -> mapa
; RSI -> compartida
; RDX -> funcion_hash
global optimizar
optimizar:
	push RBP
	mov RBP, RSP
	push R12
	push R13
	push R14
	push R15

	mov R12, RDI ; mapa en R12
	mov R13, RSI ; compartida en R13
	mov R14, RDX ; funcion_hash r14

	xor R15, R15


	mov RDI, R13
	call R14
	mov R15D, EAX ; guardamos el hash en R15D

	xor R8, R8
	mov R8, 255
	imul R8, 255 ; total posiciones a recorrer

	loop_sobre_el_mapa:
		cmp R8, 0
		je fin_loop

		cmp QWORD[R12], 0 ; si es nulo, sig elem
		je siguiente_pos
		
		mov RDI, QWORD[R12] ; temp en RDI
		push R8
		sub RSP, 8
		call R14 ; hash en eax
		add RSP, 8
		pop R8
		cmp R15D, EAX
		jne siguiente_pos

		add BYTE [R13 + UNIT_REFERENCIAS], 1
		mov R9, QWORD[R12] ; temp
		sub BYTE[R9 + UNIT_REFERENCIAS], 1 

		mov QWORD[R12], R13

		cmp BYTE [R9 + UNIT_REFERENCIAS], 0
		jne siguiente_pos	

		call free

	
	siguiente_pos:

		dec R8
		add R12, 8
		jmp loop_sobre_el_mapa
	
	fin_loop:


	pop R15
	pop R14
	pop R13
	pop R12
	pop RBP
	ret



global contarCombustibleAsignado
;uint32_t contarCombustibleAsignado(mapa_t mapa, uint16_t (*fun_combustible)(char *))
; RDI -> mapa
; RSI -> fun_combustible
contarCombustibleAsignado:
	push RBP
	mov RBP, RSP
	push R12
	push R13
	push R14
	push R15

	mov R12, RDI ; mapa en R12
	mov R13, RSI ; funcion combustible en R13

	xor R14, R14 ; en R14 vamos a preservar la respuesta
	xor R15, R15 ; en r15 nuestro contador
	mov R15, 255
	imul R15, 255 ; total posiciones a recorrer
	


	recorrer_mapa:
		cmp R15, 0
		je fin
		mov R8, QWORD[R12] ; temp
		cmp R8, 0
		je siguiente_indice
		; tenemos que obtener el combustible base
		mov RDI, R8 ; name en RDI
		push R8
		sub RSP, 8
		call R13 ; en ax el combustible base
		add RSP, 8
		pop R8
		xor R9, R9
		mov R9W, WORD[R8 + UNIT_COMBUSTIBLE] ; temp->combustible
		sub R9W, AX ; combustible extra = combustible real - combustible base
		add R14, R9 ; res += combustible extra

	siguiente_indice:
		dec R15
		add R12, 8
		jmp recorrer_mapa

	

	fin:
	xor RAX, RAX
	mov EAX, R14D
	pop R15
	pop R14
	pop R13
	pop R12
	pop RBP
	ret

global modificarUnidad
;void modificarUnidad(mapa_t mapa, uint8_t x, uint8_t y, void (*fun_modificar)(attackunit_t *))
; RDI -> mapa
; SIL -> x
; DL -> y
; RCX -> funcion
modificarUnidad:
	push RBP
	mov RBP, RSP

	push RBX
	push R12
	push R13
	push R14
	push R15
	sub RSP, 8

	mov R12, RDI ; mapa r12
	mov R15, RCX ; funcion r15

	xor RBX, RBX
	mov BL, DL ; Y

	; avanzo filas
	xor RCX, RCX
	mov CL, SIL
	mov RAX, 255
	mul ECX
	imul RAX, 8
	add R12, RAX
	; avanzo columnas
	imul RBX, 8
	add R12, RBX

	mov RDI, [R12] ;(x,y)

	cmp RDI, 0 ; mapa[x][y] == nulo?
	je fin_3

	cmp BYTE[RDI + UNIT_REFERENCIAS], 1

	je modificar_unidad

	; nueva instancia

	mov RDI, UNIT_SIZE
	call malloc

	mov R14, RAX ; nueva en R14
	mov R13, [R12] ; unidad en R13

	sub BYTE[R13 + UNIT_REFERENCIAS], 1
	mov BYTE[R14 + UNIT_REFERENCIAS], 1
	; copio combustible
	mov CX, WORD[R13 + UNIT_COMBUSTIBLE]
	mov WORD[R14 + UNIT_COMBUSTIBLE], CX
	;copio string
	mov RDI, R14
	mov RSI, [R12]
	call strcpy
	; reemplazo la unidad x la nueva
	mov [R12], R14

	; modifico la instancia
	mov RDI, [R12]

	modificar_unidad:
	call R15

	fin_3:
	add RSP, 8
	pop R15
	pop R14
	pop R13
	pop R12
	pop RBX
	pop RBP
	ret