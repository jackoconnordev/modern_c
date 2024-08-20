#!/bin/sh
[ -d bin ] || mkdir bin

# Lib code (lol)
clang -o "./lib/heron.o" -c "./lib/heron.c"
ar rcs "./lib/lib_heron.a" "./lib/heron.o"
clang -o "./lib/unionfind.o" -c "./lib/unionfind.c"
ar rcs "./lib/lib_unionfind.a" "./lib/unionfind.o"

for file in *.c; do
  clang -std=c17 -o "./bin/${file%%.*}" -I "./lib" -L "./lib" -l "_heron" -l"mpfr" "$file"
done
