LD_LIBRARY_PATH=/usr/local/lib ./compiler.out $1

fasm out/optCode.asm
./out/optCode
