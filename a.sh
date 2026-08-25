#!/bin/bash

./compiler.out $1

fasm out/code.asm
./out/code
