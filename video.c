// simple putc
int x, y; // Our global 'x' and 'y'
char color; // our global color attribute

void putc(unsigned char c)
{
  char *vidmem = (char*)0xB8000; // pointer to video memory
  int pos = (y*2) + x;    // get the position
  vidmem[pos] = c;        // print the character
  vidmem[pos++] = color;  // set the color attribute
  if ( c == '\n')         //newline
  {
    y++;
    x = 0;
  }
  else
  {
    x += 2; // 2 bytes per char
  }
}

int puts( char *message )
{
  int length;
  while(*message)
  {
    putc(*message++);
    length++;
  }
  return length;
}
