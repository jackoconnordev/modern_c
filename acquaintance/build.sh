#!/bin/sh
[ -d bin ] || mkdir bin

# Lib code (lol)
gcc -o "./lib/heron.o" -c "./lib/heron.c"
ar rcs "./lib/lib_heron.a" "./lib/heron.o"

for file in *.c; do
  gcc -o "./bin/${file%%.*}" -I "./lib" -L "./lib" -l "_heron" -l"mpfr" "$file"
done
