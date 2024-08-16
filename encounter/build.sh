#!/bin/sh
[ -d bin ] || mkdir bin

for file in *.c; do
  gcc -o "./bin/${file%%.*}" "$file"
done
