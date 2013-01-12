task :default do
  %x(
    mkdir -p obj
    mkdir -p bin
    gcc -L`gcc --print-file-name=` -m32 -ffreestanding -fno-builtin -nostdlib -c *.c
    nasm -f aout loader.asm -o loader.o
    mv *.o obj
    ld -m elf_i386 -s -Ttext 0x1000 -o bin/kernel.bin obj/*.o
    nasm -f bin boot.asm -o bin/boot.bin
    dd if=bin/boot.bin of=os.img bs=512 count=1
    dd if=bin/kernel.bin of=os.img bs=512 seek=1
  )
end

task :clean do
  %x(
    rm -f obj/* bin/* *.img
  )
end
