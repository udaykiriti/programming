#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

SRC=""
INFILE="in.txt"
OUTFILE="out.txt"
COMPILER="g++"
CXXFLAGS=(-std=c++20 -O2 -Wall -Wextra -DLOCAL)
TIMESTAMP=true

if [[ -t 1 ]]; then
  RED='\033[0;31m'
  GREEN='\033[0;32m'
  YELLOW='\033[0;33m'
  BLUE='\033[0;34m'
  MAGENTA='\033[0;35m'
  CYAN='\033[0;36m'
  BOLD='\033[1m'
  NC='\033[0m'
  ORANGE='\033[38;5;214m'
else
  RED=''
  GREEN=''
  YELLOW=''
  BLUE=''
  MAGENTA=''
  CYAN=''
  BOLD=''
  NC=''
  ORANGE=''
fi

usage() {
  cat <<EOF
Usage: $0 [-s source.cpp] [-i in.txt] [-o out.txt] [-c compiler] [-f "extra flags"] [-t] [source.cpp]
Example: $0 -s solution.cpp -i sample.in -o sample.out -f "-g -O0" -t
EOF
}

_ts() {
  if [[ "$TIMESTAMP" == true ]]; then
    printf "[%s] " "$(date '+%H:%M:%S')"
  fi
}
log() { printf "%b%s%b\n" "$BLUE" "$(_ts)>> $*" "$NC"; }
ok() { printf "%b%s%b\n" "$GREEN" "$(_ts)$*" "$NC"; }
err() { printf "%b%s%b\n" "$RED" "$(_ts)$*" "$NC" >&2; }

while getopts ":s:i:o:c:f:th" opt; do
  case "$opt" in
  s) SRC="$OPTARG" ;;
  i) INFILE="$OPTARG" ;;
  o) OUTFILE="$OPTARG" ;;
  c) COMPILER="$OPTARG" ;;
  f)
    CXXFLAGS+=($OPTARG)
    ;;
  t) TIMESTAMP=false ;;
  h)
    usage
    exit 0
    ;;
  \?)
    err "[Ohhh]: Invalid option: -$OPTARG"
    exit 2
    ;;
  :)
    err "Option -$OPTARG requires argument"
    exit 2
    ;;
  esac
done

shift $((OPTIND - 1))

if [[ -n "${1:-}" ]] && [[ -z "$SRC" ]]; then
  SRC="$1"
fi

if [[ -z "$SRC" ]]; then
  shopt -s nullglob
  files=(*.cpp)
  ((${#files[@]} > 0)) || {
    err "${RED}[Ohh..]No .cpp files found in current directory."
    exit 1
  }
  SRC="${files[0]}"
  log "${RED}[;-]]No source specified - using first .cpp: ${YELLOW}${SRC}${NC}"
fi

[[ -f "$SRC" ]] || {
  err "Source file '$SRC' not found."
  exit 1
}

BIN="${SRC%.*}"
if [[ "${OS:-}" =~ MINGW|Windows ]] || [[ "${MSYSTEM:-}" =~ MINGW ]]; then
  BIN="${BIN}.exe"
fi

command -v "$COMPILER" >/dev/null || {
  err "[Error]: Compiler not found: $COMPILER"
  exit 1
}

_banner() {
  printf "%b" "${ORANGE}${BOLD}"
  cat <<'BANNER'
 ██████╗ ██████╗ ██████╗
██╔════╝ ██╔══██╗ ██╔══██╗
██║      ██████╔╝ ██████╔╝
██║      ██╔═══╝  ██╔═══╝
╚██████╗ ██║      ██║
 ╚═════╝ ╚═╝      ╚═╝
BANNER

  printf "%b" "${NC}"

  printf "%b" "${BLUE}"
  cat <<'TAGLINE'
       C++ BUILD SYSTEM
   compile >> link >> execute
   no mercy.. no warnings..
TAGLINE

  printf "%b\n" "${NC}"
}

typewriter() {
  printf "%s\n" "$*"
}

_spinner() {
  local sp='|/-\'
  printf " "
  (
    while true; do
      for ((i = 0; i < ${#sp}; i++)); do
        printf "\b%s" "${sp:i:1}"
        sleep 0.08
      done
    done
  ) &
  spinner_pid=$!
  disown "$spinner_pid" 2>/dev/null || true
}

spinner_stop() {
  if [[ -n "${spinner_pid:-}" ]]; then
    kill "$spinner_pid" >/dev/null 2>&1 || true
    wait "$spinner_pid" 2>/dev/null || true
    unset spinner_pid
    printf "\b"
  fi
}

clean() {
  spinner_stop
}
trap clean EXIT

printf "%b" "$CYAN"
_banner
printf "%b\n" "$NC"

printf "%b" "${GREEN}"
typewriter "[ON the waY]: Initializing compiler environment..."
printf "%b" "$NC"

printf "%b" "${YELLOW}"
typewriter "Command: $COMPILER ${CXXFLAGS[*]} $SRC -o $BIN"
printf "%b" "$NC"

printf "%b" "${BOLD}${BLUE}[Wait]: Compiling${NC} "
_spinner

tmp_out="$(mktemp)"
tmp_err="$(mktemp)"
set +e
"$COMPILER" "${CXXFLAGS[@]}" "$SRC" -o "$BIN" >"$tmp_out" 2>"$tmp_err" &
compiler_pid=$!
wait "$compiler_pid"
compile_rc=$?
set -e

spinner_stop
if ((compile_rc != 0)); then
  echo -e "${RED}${BOLD}\nCompilation failed.${NC}"
  echo -e "${YELLOW}--- compiler stdout ---${NC}"
  sed -n '1,200p' "$tmp_out" || true
  echo -e "${YELLOW}--- compiler stderr ---${NC}" >&2
  sed -n '1,200p' "$tmp_err" >&2 || true
  rm -f "$tmp_out" "$tmp_err"
  exit "$compile_rc"
fi

echo -e " ${GREEN}${BOLD}OK${NC}"
rm -f "$tmp_out" "$tmp_err"

printf "%b" "${BLUE}"
typewriter "[Working]: Linking objects..."
printf "%b" "$NC"

if [[ -f "$INFILE" ]]; then
  log "[Hold]: Running: ./${BIN} < ${INFILE} > ${OUTFILE}"
  printf "%b" "${MAGENTA}"
  typewriter "[Wait]: Working..."
  printf "%b" "$NC"
  ./"$BIN" <"$INFILE" >"$OUTFILE"
else
  log "[Hold]: Running program: ./${BIN} > ${OUTFILE}"
  printf "%b" "${MAGENTA}"
  typewriter "[Almost]: Running (no input file)..."
  printf "%b" "$NC"
  ./"$BIN" >"$OUTFILE"
fi

printf "%b" "${GREEN}"
typewriter "[Done]: Execution finished."
printf "%b" "$NC"

ok "[Write]: Output written to ${OUTFILE}"

if [[ -s "$OUTFILE" ]]; then
  echo
  printf "%b" "${CYAN}${BOLD}--- program output (first 20 lines) ---${NC}\n"
  sed -n '1,20p' "$OUTFILE" || true
  echo
fi

exit 0
