/*Declaración de funciones*/
void testMemory(int segmento, int offset, unsigned char dato, unsigned char dato2);
extern void putchar(char caracter);
extern void pokeb(int segmento, int offset, unsigned char dato);
extern void printAddress(int segmento, int offset);
extern char peekb(int segmento, int offset);

/*Función principal*/
int main(void)
{

  testMemory(0x00,0x2200,0x55,0x0AA);
  while (1) {

  }
  return 0;
}

/*Declaración de funciones*/
void testMemory(int segmento, int offset, unsigned char dato, unsigned char dato2)
{
  while( offset<0x10000 )
  {
    printAddress(segmento ,offset);
    pokeb(segmento, offset, dato);
    if( peekb(segmento, offset) != dato )
      {
        putchar('F');
        break;
      }
    pokeb(segmento, offset, dato2);
    if( peekb(segmento, offset) != dato2 )
      {
        putchar('F');
        break;
      }
    else
      if( offset == 0x0ffff )
        {
          putchar('E');
          break;
        }
    offset++;
  }
}
