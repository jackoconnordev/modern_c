mkdir -p debug
cd debug
gcc -g -I ../lib -L ../lib -l _unionfind ../lib/graph.c ../test_graph.c
