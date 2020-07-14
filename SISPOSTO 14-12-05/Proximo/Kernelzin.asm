ORG 8000h
            call TabelaProc
	    CLI				; bloqueia interrupções
	    mov ax, [20h] 		; copia o deslocamento
	    mov [ponteiro], ax		; grava no ponteiro
	    mov ax, [22h]		; copia o segmento
	    mov [ponteiro+2], ax	; grava no ponteiro
	    mov ax, nova		; deslocamento da int nova
	    mov [20h], ax		; grava na tab. de int.
	    mov [22h], cs		; grava segmento
	    STI				; libera interrupções
fim:       JMP fim			; fica preso para ver o resultado na tela
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
            
nova: 	    
            push ax;			; salva os registradores na pilha
	    push bx;
	    push cx;
	    push dx;
	    push ds;
	    push es;
	    push bp;
	    push di;
	    push si;
            
            mov ax, 0
            mov ds, ax	    
            mov al, [procativo]
            mov ah, 0
	    mov bx, tabela		; inicio da tabela de processos
            shl ax,4
            add bx,ax
	    mov [bx+1], SS
            mov [bx+3], SP  


            mov SS,[tabela+1]
            mov SP,[tabela+3]
            pushf		        ; salva flags
            push cs		        ; salva cs=> mesmo segmento de continua
            mov ax, continua	        ; OFFSET (IP)  de continua
            push ax		        ; salva na pilha
            jmp FAR [ponteiro]

continua:   mov [tabela+1],SS
            mov [tabela+3],SP
            call procpronto
            mov [procativo],al
            mov SS,[bx+1]
            mov SP,[bx+3]
            
            pop si			; recuperando registradores da pilha do sistema                 
	    pop di;
            pop bp;
            pop es;
            pop ds;
            pop dx;
            pop cx;
            pop bx;
            pop ax;  


            iret	                ; volta da int
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Exercicio 2

TabelaProc: 
            mov cx, 18
            mov bx, tabela
            mov byte [bx], pronto

.loop1:     add bx, 10h  
            mov byte [bx], naousado
            loop .loop1
            ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Exercicio 3

Busca: 
            mov cx, 18
            mov bx, tabela
            mov al, 0               	; indice para um processo para tabela de processo

.loop1:     add bx, 10h  
            inc al
            cmp byte [bx], naousado 
            jz .fim
            loop .loop1
            mov al, 0FFh
.fim        ret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Exercicio 4

Segmento:  
            and al, al		        ; vê se o valor de Al é zero
            jnz .prox1			; se não for zero vai para prox1		
            mov ax, 0h
            mov es, ax			; senão retorna o seguimento 1
            ret				; retorna (caso al seja 0h)

.prox1:     mov ch, 0			; zera a parte alta do contador, p6ra ter compatibilidade com al
            mov cl,al			; contador recebe o valor de al (al contém um indice de processos)

            mov ax,800h
.iter:      add ax, 800h
            loop .iter
            mov es,ax
            ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Exercicio 5

;inicializa a pilha

pilha: 	    mov di,7ffeh		; di aponta para a ultima posição de 16bits do segmento de processo
	    mov word [es:di],300h	; coloca uma sequencia de bits com dois bits ativos que simbolizam flags
	    dec di			; decrementa di 2vezes pois tem que andar dois bytes no segmento do processo
	    dec di 
	    mov[es:di],es		; o valor de cs (lembrando que es é dado e representa o segmento do processo)

	    dec di			; decrementa di 2vezes pois tem que andar dois bytes no segmento do processo
	    dec di
	    mov word [es:di],0		; o valor inicial de ip é zero (ip é o deslocamento) 

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa ax com zero (posição que representa ax na pilha)

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa bx com zero (posição que representa bx na pilha)          

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa cx com zero (posição que representa cx na pilha)

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa dx com zero (posição que representa dx na pilha)

	    dec di			
	    dec di
	    mov[es:di],es		; inicializa  ds com es
 
	    dec di			
	    dec di
	    mov[es:di],es		; inicializa es com es (salva es)

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa bp com zero (posição que representa bp na pilha)

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa di com zero (posição que representa di na pilha)

	    dec di			
	    dec di
	    mov word [es:di],0		; inicializa si com zero (posição que representa si na pilha)

;Salva o topo da pilha na tabela de processos

	    mov ah,0			; zera ah (pois pode conter lixo)
	    shl ax,4			; rotaciona ax 4vezes p/ a direita (multiplica al (indice) por 16)
            mov bx, tabela		; bp recebe o esdereço inicial da tabela 
	    add bx,ax			; soma 610 ao conteudo de ax (bp <- 610 + al*16h)
	   				; bp irá conter o endereço inicial do processo na tabela de processo
	    mov[bx+1],es			; anda 1 byte pois o primeiro byte (da tabela de proc) contem o indice do processo
	   				; ss recebe es (ss representa o segmento do proc, por isso ele recebe es)
	    mov[bx+3],di			; sp recebe o deslocamento para o topo da pilha
	    shr ax,4			; recupera ax (volta ao valor anterior a rotação à direita)
	    ret				; retorna 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Exercicio 6

procpronto:     

            mov al, [procativo]		; passa para o al o indice do proc ativo (procativo é a posição de memoria que é 
					; reservada para conter o indice do processo ativo)
            cmp al, 18			; se al for 18 quer dizer que al é o ultimo processo
            jb buscar			; se tiver abaixo (for menos que 18) vai buscar o proximo proc ativo
            mov al,0			; se não, al retorna ao kernel que esta sempre ativo
            mov bx, tabela		; bp recebe o segmento onde se encontra a tabela
            ret 

					; as linhas a seguir fazem bp apontar para o proximo processo na tabela de processo
buscar:     inc al			; incrementa o indice ou seja, vai para o proximo proc da tabela de processo
            mov bx, tabela		; bp recebe o esdereço inicial da tabela 
	    mov ah,0
	    shl ax, 4
            add bx,ax
	    shr ax, 4 
compara:    
            cmp byte [bx], pronto	; vê se o primeiro byte da tab de proc esta setada com pronto
            jz  achei			; se sim nos achamos o proximo processo que esta pronto
	    inc al			; e incrementamos o indice 
	    add bx,16			; soma 610 ao conteudo de ax (bp <- 610 + al*16h)
	    cmp al,19			; se o indice for menor que 19 (ainda não esta no final da tabela de processo)
	    jb compara			; volta e compara se esta no pronto  
	    mov al,0			; se estiver no final da tabela al, retorna ao kernel que esta sempre ativo
            mov bx, tabela		; bp recebe o segmento onde se encontra a tabela

achei:      ret				; quando acha um processo pronto é só retornar (al e bp ja estao prontos)
        		     



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	            
	             
;Exercicio 7

colocapronto:

	   mov bx, tabela		; bp recebe o endereço inicial da tabela
           mov ah,0			; zera ah (pois pode conter lixo)
           shl ax,4			; rotaciona ax 4vezes p/ a direita (multiplica al (indice) por 16)
	   add bx,ax			; soma 610 ao conteudo de ax (bp <- 610 + al*16h) posição do processo na tabela
	   mov byte [bx],pronto		; muda o primeiro byte que representa os estados na tabela de processos para pronto
	   ret				

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;Exercicio 8
; parametros ds:si e cx

carregarseg:  
           call Busca                   ; busca processo nao usado na tabela de processos retornando em al
	   push ax
           call Segmento                ; busca pelo segmento dado por al e retorna em es
	   pop ax
           call pilha                   ; inicializa a pilha de processos
           call colocapronto		; torna processo ativo
           ret          
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	            
	             
impa:      incbin "impa.bin"          		; incluindo arquivo binario impa.bin
           tamanhoa equ ($-impa)	    	; tamanho do arquivo "impa.bin"

impb:      incbin "impb.bin"			; incluindo arquivo impb.bin
           tamanhob equ ($-impb)	 	; tamanho do arquivo "impb.bin"



           int_ini dd 0 			; interrupção anterior
           ponteiro dd  0		                
           procativo equ 600h			; processo sempre ativo (kernel)
           tabela equ 610h			; inicio da tabela
           fim_tabela equ 619h			; final da tabela de processos
	   end_byte equ  620h			; guarda o endereço de um byte
	   setor equ	 622h			; guarda um setor
	   posmapa	 624h			; posiçãoinicial do bit no mapa de bits


	   ;
;estados
 
           pronto equ 0
           naousado equ 1
           bloqueado equ 2