#include <stdio.h>

int main()
{
  int i, j;
  int myArray[6][6]; // объявляем массив размером 6*6

  for ( i = 1; i < 6; i++ ) {
    for ( j = 1; j < 6; j++ )
      myArray[i][j] = i * j; // каждому элементу присваиваем значение произведения текущих индексов элемента массива
  }

  printf( "Here's the array we did it:\n" );
  for ( i = 1; i < 6; i++ ) {
    for ( j = 1; j < 6; j++ )
    {
        printf( " %d", i, j, myArray[i][j] );
    }
    printf( "\n" );
  }
  getchar();
}
