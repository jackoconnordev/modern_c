# Dependencies

Mac directions only. Env vars one way to get clang and clangd to find system libraries
and header files.

```sh
export LIBRARY_PATH=/opt/homebrew/lib:$LIBRARY_PATH  # -Iincludedir
export CPATH=/opt/homebrew/include:$CPATH  # -Llibdir
```

## mpfr

```sh
brew install mpfr
```
