
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


mapeia: push ax
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



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;primeiramente devemos carregar o map de bits na memoria para depois alterá-lo
setmap:	
	;carrega o mapa de bits na memória

	push ax				;salva o setor
	puhs cx				;salva o numero de setores
	mov ax,67			;setor do mapa de bits
	
	call mapeia			;busca o setor no disquete
	

	mov ax,seg_cod_des_mapa 	;segmento de destino
	mov es,ax
	mov bx,off_cod_des_mapa 	;offset de destino

	mov ah,02   			; função de leitura de setores
	mov al,1   			; número de setores a ser lido
	mov dl, 0   			; driver A
	int 13h    			; faz a leitura
	pop cx				;recupera o numero de setores
	pop ax				;recupera o setor logico em ax

	;esta parte do codigo irá setar o mapa de bits (como?)

	push ax					;salva ax na pilha
	div 8					;quociente = byte, resto = bit
	mov endbyte,off_cod_des_mapa+ah		;endbyte recebe o endereço do byte
	mov dl,1		;dl terá o conteudo 00000001 usdo na operação or para setar os bits
	rol dl,al		;rotaciona dl para setar o bit correspondente
	pop ax			;restaura o segmento em ax

.LOOP:	or[endbyte],dl		;seta o bit do mapa de bits
	rol dl,1		;faz uma rotação para setar o proximo bit
	dec cx			;decrementa o contador
	comp cx,0		;vê se o valor de cx é igual a zero
	jz GRAVA		;e for zero quer dizer que ja setou todos o s bits(salva o mapa no disco)
	comp dl,1		;vê se o valor de dl é 1 (se for um quer dizer que o proximo bit a ser setado esta no 				;proximo byte)
	jnz LOOP		; se não for 1 executa o loop novamente
	mov [endbyte],[endbyte+1] ;se for um pula pro proximo byte
	jmp LOOP		;volta para o loop


	;esta parte irá gravar o mapa de bits no diskete

.GRAVA:	push ax				;salva o setor
	puhs cx				;salva o numero de setores
	mov ax,67			;setor do mapa de bits
	
	call mapeia			;busca o setor no disquete
	

	mov ax,seg_cod_des_mapa 	;segmento de destino
	mov es,ax
	mov bx,off_cod_des_mapa 	;offset de destino

	mov ah,03   			; função de gravação de setores
	mov al,1   			; número de setores a ser lido
	mov dl, 0   			; driver A
	int 13h    			; faz a leitura
	pop cx				;recupera o numero de setores
	pop ax				;recupera o setor logico em ax
	RET
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	   	
	
resetamap:	
	;carrega o mapa de bits na memória

	push ax				;salva o setor
	puhs cx				;salva o numero de setores
	mov ax,67			;setor do mapa de bits
	
	call mapeia			;busca o setor no disquete
	

	mov ax,seg_cod_des_mapa 	;segmento de destino
	mov es,ax
	mov bx,off_cod_des_mapa 	;offset de destino

	mov ah,02   			; função de leitura de setores
	mov al,1   			; número de setores a ser lido
	mov dl, 0   			; driver A
	int 13h    			; faz a leitura
	pop cx				;recupera o numero de setores
	pop ax				;recupera o setor logico em ax

	
	;essa primeira parte encontra o primeiro byte e bit correspondente ao setor no mapa de bits------------------

	push ax					;salva ax na pilha
	div 8					;quociente = byte, resto = bit
	mov endbyte,off_cod_des_mapa+ah		;endbyte recebe o endereço do byte
	mov dl,11111110				;dl terá o conteudo 11111110 usdo na operação and para resetar os bits
	rol dl,al				;rotaciona dl para resetar o bit correspondente
	pop ax					;restaura o segmento em ax

	
	;essa segunda parte é responsável por resetar o mapa de bits------------------------------------------------

.LOOP:	and[endbyte],dl			;seta o bit do mapa de bits
	rol dl,1			;faz uma rotação para setar o proximo bit
	dec cx				;decrementa o contador
	comp cx,0			;vê se o valor de cx é igual a zero
	jz GRAVA			;e for zero quer dizer que ja resetou todos o s bits(salva o mapa no disco)
	comp dl,1			;vê se o valor de dl é 1 (se for um quer dizer que o proximo bit a ser setado esta no 					;proximo byte)
	jnz LOOP			; se não for 1 executa o loop novamente
	mov [endbyte],[endbyte+1] 	;se for um pula pro proximo byte
	jmp LOOP			;volta para o loop
	
	
	;esta parte irá gravar o mapa de bits no diskete----------------------------------------------------------------

.GRAVA:	push ax				;salva o setor
	puhs cx				;salva o numero de setores
	mov ax,67			;setor do mapa de bits
	
	call mapeia			;busca o setor no disquete
	

	mov ax,seg_cod_des_mapa 	;segmento de destino
	mov es,ax
	mov bx,off_cod_des_mapa 	;offset de destino

	mov ah,03   			; função de gravação de setores
	mov al,1   			; número de setores a ser lido
	mov dl, 0   			; driver A
	int 13h    			; faz a leitura
	pop cx				;recupera o numero de setores
	pop ax				;recupera o setor logico em ax
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	

;busca CX bits resetados no mapa de bits e retorna a posição inicial em ax

	;carrega o mapa de bits na memoria
Busca:	
	puhs cx				;salva o numero de bits
	mov ax,67			;setor do mapa de bits
	
	call mapeia			;busca o setor no disquete
	

	mov ax,seg_cod_des_mapa 	;segmento de destino
	mov es,ax
	mov bx,off_cod_des_mapa 	;offset de destino

	mov ah,02   			; função de leitura de setores
	mov al,1   			; número de setores a ser lido
	mov dl, 0   			; driver A
	int 13h    			; faz a leitura
	pop cx				;recupera o numero de bits
	mov ax,off_cod_des_mapa		;ax recebe

	


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;; Código de Teste
    	  
 incbin "kernel.bin"  ;; incluio kernel pré-compilada
	  