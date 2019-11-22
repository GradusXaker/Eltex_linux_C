#include <stdio.h>
#include <stdlib.h>

int main(){
	int c = 10;
	if (c == rand()){
		printf("Success!\n");
	}
	return 0;
}




/*gcc - o binary.c binary

objdump -S --section=.text binary

000000000000068a <main>:
 68a:	55                   	push   %rbp
 68b:	48 89 e5             	mov    %rsp,%rbp
 68e:	48 83 ec 10          	sub    $0x10,%rsp
 692:	c7 45 fc 0a 00 00 00 	movl   $0xa,-0x4(%rbp)
 699:	e8 c2 fe ff ff       	callq  560 <rand@plt>
 69e:	39 45 fc             	cmp    %eax,-0x4(%rbp)
 6a1:	75 0c                	je     6af <main+0x25>
 6a3:	48 8d 3d 9a 00 00 00 	lea    0x9a(%rip),%rdi        # 744 <_IO_stdin_used+0x4>
 6aa:	e8 a1 fe ff ff       	callq  550 <puts@plt>
 6af:	b8 00 00 00 00       	mov    $0x0,%eax
 6b4:	c9                   	leaveq 
 6b5:	c3                   	retq   
 6b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 6bd:	00 00 00 

Нам нужна строчка ----    6a1:	75 0c      je     6af <main+0x25>
Перепишем значение вместо 75 на 74 
Для этого смотрите код patch.c */
