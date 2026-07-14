#!/bin/bash

TEMPLATE="$HOME/programming/algo/Template.cpp"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
ORANGE='\033[38;2;255;140;0m'
BLUE='\033[0;34m'
NC='\033[0m'

if [ -z "${1:-}" ]; then
  echo -e "${YELLOW}[Usage] :${NC} create <name> [-cpp]"
  exit 1
fi

FILENAME="$1"
EXTENSION="${2:-}"

if [ "$#" -gt 2 ]; then
  echo -e "${RED}[Error] :${NC} Too many arguments"
  echo -e "${YELLOW}[Usage] :${NC} create <name> [-cpp]"
  exit 1
fi

if [ -n "$EXTENSION" ] && [ "$EXTENSION" != "-cpp" ]; then
  echo -e "${RED}[Error] :${NC} Unknown option: $EXTENSION"
  echo -e "${YELLOW}[Usage] :${NC} create <name> [-cpp]"
  exit 1
fi

if [ "$EXTENSION" == "-cpp" ]; then
  FILENAME="${FILENAME}.cpp"
fi

if [ ! -f "$TEMPLATE" ]; then
  echo -e "${RED}[Error] :${NC} Template not found"
  echo -e "${BLUE}[Path] :${NC} $TEMPLATE"
  exit 1
fi

if [ -f "$FILENAME" ]; then
  echo -e "${ORANGE}[Ohhh..]: Please check once before Trying another time..${NC}"
  echo -e "${ORANGE}[Warning!!!] :${NC} $FILENAME Already exists....${NC} "
  echo -e "${RED}[Danger...]: Verify Twice and Enter "y" cuz the Data will be Destroyed${NC}"
  read -rp "[r u Sure...]: Overwrite? (y/n) [Now the Danger Begins]: " choice
  [[ ! "$choice" =~ ^([yY]|[yY][eE][sS])$ ]] && echo -e "${RED}Aborted...[I mean Operation Cancelled]" && exit 1
fi

cp "$TEMPLATE" "$FILENAME" &&
  echo -e "${GREEN}[Delivered] :${NC} $FILENAME from algo/Template.cpp"
