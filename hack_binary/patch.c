#include <stdio.h>

int main(){
	FILE *f = fopen ("binary", "r+b");
	unsigned char opcode = 0x74;
	fseek(f, 0x6a1, SEEK_SET);
	fwrite(&opcode, sizeof(opcode), 1, f);
	fclose(f);
	return 0;
}

/*gcc -o patch.c patch 
Запускаем патч и ни чего не произойдет, затем запускаем бинарный файл и мы переписали бинарни что бы он выдавал нам Access
*/
