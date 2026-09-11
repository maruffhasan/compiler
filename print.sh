LD_LIBRARY_PATH=/usr/local/lib ./compiler.out $1

mkdir -p out 

fasm out/optCode.asm
./out/optCode
