; Loader.asm
bits 32
extern main
global start

start:
  call main   ; Call our kernel's main() function
  cli         ; Stop interrupts (that's another article)
  hlt         ; Stop all instructions
