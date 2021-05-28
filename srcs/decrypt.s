BITS 64

segment .text
	global test

test:
	push rax
	push rsi
	push rdi
	push rdx
	push rcx
	push r8
	push r9
	jmp woody
end_code:
	pop rsi
	mov rax, 1
	mov rdi, 1
	mov rdx, 14
	syscall
	mov rcx, 43 ; text_size
	mov rsi, 4 ; key_size 
	lea rdx, [rel routine] ; text
	xor r8, r8 ; key_index
	xor r9, r9 ; key_offset
	jmp key
back_key:
	pop rdi ; key
routine:
	movzx rax, byte [rdi + r8]
	add rax, r9
	xor [rdx], rax
	inc rdx
	inc r8
	cmp r8, rsi
	jne loopinstr
	add r9, byte 43
	xor r8, r8
loopinstr:
	loop routine
	pop r9
	pop r8
	pop rcx
	pop rdx
	pop rdi
	pop rsi
	pop rax
	jmp 42
woody:
	call end_code
	woody_str: db "....WOODY....", 10
key:
	call back_key
	key_str: db ''