CC="gcc"
CFLAGS="-Wall -Wextra -pedantic -std=c99 -ggdb"

EXEC="ipl"
OUTDIR="bin"

SRCS=("src/main.c")
OBJS=("$OUTDIR/main.o")

build() {
  mkdir -p $OUTDIR
  for i in "${!SRCS[@]}"; do
    $CC $CFLAGS -c "${SRCS[$i]}" -o ${OBJS[$i]}
  done
  $CC $CFLAGS $OBJS -o ipl
}

clean() {
  if [ -f "$EXEC" ]; then
    rm $EXEC
  fi
  if [ -d "$OUTDIR" ]; then
    rm -r $OUTDIR
  fi
}

case "$1" in
  "clean")
    clean ;;
  *)
    if [ -z "$1" ]; then
      build
    else
      echo "$0: Unknown command $1"
      exit 1
    fi
    ;;
esac
