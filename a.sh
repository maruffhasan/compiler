#!/bin/bash

./compiler.out $1

fasm out/optCode.asm
./out/code
