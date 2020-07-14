
ORG 7C00h
	 mov ax,seg_cod_des ; segmento de destino
	 mov es,ax
	 mov bx,off_cod_des ; offset de destino
         mov ah,02   ; função de leitura de setores
	 mov al,01   ; número de setores a ser lido
	 mov ch, 0   ; cilindro
	 mov cl, 2   ; setor
	 mov dh, 0   ; cabeça
	 mov dl, 0   ; driver A
	 int 13h    ; faz a leitura
	 jmp word seg_cod_des:off_cod_des  ; executa o código
	  

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; AREA DE DADOS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

seg_cod_des   equ  0h  ; segmento do endereço de destino
off_cod_des   equ  8000h     ; codigo de destino  

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Finalizador do setor de boot
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

times 510-($-$$) db 0   ; completa setor de boot
          db 55h, 0AAh ; identificador do setor de boot	  	  

;;restante do disquete


mapeia: push ax		;salva setor logico
	div 36		;divide setor logico (ax) por 32
	mov ch,ah	;passa para o cilindro o resultado da div ax/36
	pop ax		;recupera o setor logico
	push ax		;salva o setor logico novamente
	div 16		;divide o setor logico por 16
	div 2		;divide (ax/16) por 2
	mov dh, al	; cabeça (dh) recebe (ax/16)%2
	pop ax		;recupera o setor logico em ax
	push ax		;salva o setor logico na pilha
	div 18		;divide o setor logico por 18
	add al,1	;soma 1 no resto da divisão
	mov cl,al	; setor recebe 1+(ax%18)
	pop ax		;recupera o setor logico em ax
	RET


;primeiramente devemos carregar o map de bits na memoria para depois alterá-lo
setmap:	
	;carrega o mapa de bits na memória

	push ax				;salva o segmento
	mov ax,67			;setor do mapa de bits
	
	mov ah,02   			; função de leitura de setores
	call mapeia			;busca o setor no disquete

	mov ax,seg_cod_des_mapa 	;segmento de destino
	mov es,ax
	mov bx,off_cod_des_mapa 	;offset de destino

	mov al,1   			; número de setores a ser lido
	mov dl, 0   			; driver A
	int 13h    			; faz a leitura
	pop ax				;recupera o setor logico em ax

	;esta parte do codigo irá setar o mapa de bits
	



;;;;; Código de Teste
    	  
 incbin "kernel.bin"  ;; incluio kernel pré-compilada
	  