			global		_ft_strcpy

			section		.text
_ft_strcpy:	mov			rcx, -1				;rdi=dest, rsi=source
loop:		inc			rcx
			mov			al, byte[rsi + rcx]
			mov			byte[rdi + rcx], al
			cmp			al, 0
			jnz			loop
done:		mov			rax, rdi
			ret