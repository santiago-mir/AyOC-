extern malloc
extern sleep
extern wakeup
extern create_dir_entry

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio
sleep_name: DB "sleep", 0
wakeup_name: DB "wakeup", 0

section .text
; Marca un ejercicio como aún no completado (esto hace que no corran sus tests)
FALSE EQU 0
; Marca un ejercicio como hecho
TRUE  EQU 1

; Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - init_fantastruco_dir
global EJERCICIO_1A_HECHO
EJERCICIO_1A_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

; Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - summon_fantastruco
global EJERCICIO_1B_HECHO
EJERCICIO_1B_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

;########### ESTOS SON LOS OFFSETS Y TAMAÑO DE LOS STRUCTS
; Completar las definiciones (serán revisadas por ABI enforcer):
DIRENTRY_NAME_OFFSET EQU 0
DIRENTRY_PTR_OFFSET EQU 16
DIRENTRY_SIZE EQU 24

FANTASTRUCO_DIR_OFFSET EQU 0
FANTASTRUCO_ENTRIES_OFFSET EQU 8
FANTASTRUCO_ARCHETYPE_OFFSET EQU 16
FANTASTRUCO_FACEUP_OFFSET EQU 24
FANTASTRUCO_SIZE EQU 32

; void init_fantastruco_dir(fantastruco_t* card);
global init_fantastruco_dir
; RDI -> puntero a la card
init_fantastruco_dir:
	; prologo
	push RBP
	mov RBP, RSP

	push R12
	push R13 ; preservo no volatiles que voy a usar

	mov R12, RDI ; nos guardamos el puntero a la card en R12
	xor RDI, RDI ; limpiamos RDI
	mov RDI, 16 ; sizeof(dir * 2) = 16
	call malloc ; puntero al dir en rax

	mov R13, RAX ; puntero al dir en RAX

	; ahora, creamos las entrys
	mov RDI, sleep_name ; name en RDI
	mov RSI, sleep ; funcion en RSI
	call create_dir_entry ; sleep entry en RAX

	mov QWORD[R13], RAX ; movemos new_dir[0] = sleep_entry

	mov RDI, wakeup_name ; name en RDI
	mov RSI, wakeup ; funcion en RSI

	call create_dir_entry ; wakeup entry en RAX

	mov QWORD[R13 + 8], RAX ; new_dir[1] = wakeup_entry

	; ahora, asignamos a la card

	mov QWORD[R12 + FANTASTRUCO_DIR_OFFSET], R13
	mov WORD[R12 + FANTASTRUCO_ENTRIES_OFFSET], 2

	; epilogo
	pop R13
	pop R12
	pop RBP
	ret ;No te olvides el ret!

; fantastruco_t* summon_fantastruco();
global summon_fantastruco
summon_fantastruco:
	; prologo
	push RBP
	mov RBP, RSP

	push R12
	sub RSP, 8 ; preservo R12 y alineo la pila

	xor RDI, RDI
	mov RDI, FANTASTRUCO_SIZE
	call malloc ; puntero a nuestra card en RAX

	mov R12, RAX ; guardo la card en R12

	mov RDI, RAX
	call init_fantastruco_dir ; inicializamos el directorio

	; ahora, asignamos face_up y arquetipo

	mov BYTE[R12 + FANTASTRUCO_FACEUP_OFFSET], 1
	mov QWORD[R12 + FANTASTRUCO_ARCHETYPE_OFFSET], 0

	mov RAX, R12 ; movemos el puntero a la card a rax

	; epilogo
	add RSP, 8
	pop R12
	pop RBP

	ret 
