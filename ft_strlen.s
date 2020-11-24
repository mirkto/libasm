			global		_ft_strlen

			section		.text
_ft_strlen:	mov			rax, -1			;rdi=*str
loop:		inc			rax
			cmp			byte[rdi + rax], 0
			jnz			loop
done:		ret