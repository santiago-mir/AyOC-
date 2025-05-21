extern malloc

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio

ITEM_NAME EQU 0
ITEM_FUERZA EQU 20
ITEM_DURABILIDAD EQU 24
ITEM_SIZE EQU 28

section .text
; Marca un ejercicio como aún no completado (esto hace que no corran sus tests)
FALSE EQU 0
; Marca un ejercicio como hecho
TRUE  EQU 1

; Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - es_indice_ordenado
global EJERCICIO_1A_HECHO
EJERCICIO_1A_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

; Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - indice_a_inventario
global EJERCICIO_1B_HECHO
EJERCICIO_1B_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

;; La funcion debe verificar si una vista del inventario está correctamente 
;; ordenada de acuerdo a un criterio (comparador)





;; bool es_indice_ordenado(item_t** inventario, uint16_t* indice, uint16_t tamanio, comparador_t comparador);
; RDI -> inventario
; RSI -> arreglo de indices
; DX -> tamaño
; RCX -> comparador

global es_indice_ordenado
es_indice_ordenado:
	push RBP
	mov RBP, RSP

	push R12
	push R13
	push R14
	push R15

	mov R12, RDI ; inventario R12
	mov R13, RSI ; indices R13
	mov R14, RCX ; func comparador R14
	xor R15, R15
	mov R15W, DX ; tam en R15W
	
	xor R8, R8
	xor R9, R9
	xor R10, R10
	mov R10W, 1
	ciclo:
		cmp R10W, R15W
		je fin

		mov R8W, WORD[R13] ; aca agarramos el 1er indice
		add R13, 2 ; pasamos al siguiente
		mov R9W, WORD[R13] ; siguiente indice
		shl R8, 3 ; mult * 8 (para encontrar la pos del inv)
		shl R9, 3 ; mult * 8

		mov RDI, QWORD[R12 + R8] ; i - 1
		mov RSI, QWORD[R12 + R9] ; i
		push R10
		sub RSP, 8

		call R14 ; comparamos

		add RSP, 8
		pop R10
		cmp RAX, 0 ; si da false, salgo
		je fin
		inc R10W
		jmp ciclo



	fin:

		pop R15
		pop R14
		pop R13
		pop R12
		pop RBP
		ret

;; Dado un inventario y una vista, crear un nuevo inventario que mantenga el
;; orden descrito por la misma.

;; La memoria a solicitar para el nuevo inventario debe poder ser liberada
;; utilizando `free(ptr)`.



;; Donde:
;; - `inventario` un array de punteros a ítems que representa el inventario a
;;   procesar.
;; - `indice` es el arreglo de índices en el inventario que representa la vista
;;   que vamos a usar para reorganizar el inventario.
;; - `tamanio` es el tamaño del inventario.
;; 
;; Tenga en consideración:
;; - Tanto los elementos de `inventario` como los del resultado son punteros a
;;   `ítems`. Se pide *copiar* estos punteros, **no se deben crear ni clonar
;;   ítems**
;; item_t** indice_a_inventario(item_t** inventario, uint16_t* indice, uint16_t tamanio);
global indice_a_inventario
; RDI -> inventario
; RSI -> arreglo indices
; DX -> tamaño
indice_a_inventario:
	; prologo
	push RBP
	mov RBP, RSP

	push R12
	push R13
	push R14
	push R15

	mov R12, RDI ; inventario en R12
	mov R13, RSI ; arreglo indices en R13
	xor R14, R14
	mov R14W, DX ; tamaño en R14W
	xor R15, R15 ; contador

	; primero, hay que pedir memoria

	xor RDI, RDI
	mov DI, R14W ; tamaño en RDI
	shl RDI, 3 ; mult * 8

	call malloc ; memoria reservada en rax
	mov R9, RAX ; preservo direccion base en R9

	xor R8, R8
	ciclo_2:
		cmp R15W, R14W ; si llego al tamaño, corto
		je fin_2
		mov R8W, WORD[R13] ; indice[i]
		shl R8, 3 ; i * 8
		mov R10, QWORD[R12 + R8] ; inventario[indice[i]]
		mov QWORD[RAX], R10 ; resultado[j] = elem
		inc R15W  ; i + 1
		add R13, 2 ; siguiente indice
		add RAX, 8 ; siguiente elem
		jmp ciclo_2
	
	fin_2:
		mov RAX, R9
		pop R15
		pop R14
		pop R13
		pop R12
		pop RBP
		ret
