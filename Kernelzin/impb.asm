ORG 0h
inicio:	mov ah, 0eh		; funcao imprime caracter
	mov al,'b'		; caracter a ser impresso
	mov bh,0		; pagina zero
	mov bl,15		; cor branquinha
	mov cx,1		; quantidade a ser impressa
	int 10h			; imprime
	jmp inicio		; volta para inicio