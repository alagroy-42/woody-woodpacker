segment .text
	global decrypt

decrypt:
	push rax
	push rcx
	push rdx
	push rsi
	push rdi
	push r8
	push r9
	mov rcx, 43 ; text_size
	mov rsi, 43 ; data_size 
	lea rdx, [rel routine] ; text
	lea rdi, [rel routine] ; data
	xor r8, r8 ; data_index
	xor r9, r9 ; data_offset
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
	jmp woody
end_code:
	pop rsi
	mov rax, 1
	mov rdi, 1
	mov rdx, 14
	syscall
	pop r9
	pop r8
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rax
	jmp go_back;entrypoint
woody:
	call end_code
	woody_str: db "....WOODY....", 10
go_back:
	jmp 42