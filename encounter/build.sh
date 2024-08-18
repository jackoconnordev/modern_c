#!/bin/sh
[ -d bin ] || mkdir bin

for file in *.c; do
  clang -o "./bin/${file%%.*}" "$file"
done
