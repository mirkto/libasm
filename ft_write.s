			global		_ft_write
			extern		___error

			section		.text
_ft_write:	mov			rax, 0x2000004		;rdi=fd, rsi=*char, rdx=len
			syscall
			jc			error
			jmp			done
error:		push		rax
			call		___error
			pop			rcx
			mov			[rax], rcx
			mov			rax, -1
done:		ret