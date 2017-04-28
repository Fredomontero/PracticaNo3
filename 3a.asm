model tiny
.data
.code
org 100h
  principal proc
    ;mov ax,00h
    ;mov ds,ax
    mov si,200h
  inicio:
    mov byte ptr [si],55h
    cmp byte ptr [si],55h
    jne falla
    mov byte ptr [si],0AAh
    cmp byte ptr [si],0AAh
    jne falla
    cmp si,0fffh
    je exito
    inc si
    jmp inicio
  falla:
    mov dl,'F'
    mov ah,02h
    int 21h
    jmp fin
  exito:
    mov dl,'E'
    mov ah,02h
    int 21h
  fin:
    jmp fin
  endp
end principal
