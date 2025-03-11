#!/bin/zsh

SCRIPT_DIR=$(dirname "$(realpath "$0")")

echo "alias lis=\"/tmp/<user>/save.sh\"" > ~/.zshrc
clear

printf "\033[1;38;2;255;0;128mlis deployed\033[0m\n\n"

printf "\033[1;38;2;255;0;128mfor save run "lis"\033[0m\n\n"

