#!/bin/zsh

SCRIPT_DIR=$(dirname "$(realpath "$0")")

echo "alias lis=\"/tmp/<user>/save.sh\"" >> ~/.zshrc

clear
printf "\033[1;38;2;0;255;255m"
printf "lis deployed\n\n"
printf "for save run "
printf "\033[1;38;2;255;0;128m"
printf "\"lis\"\033[0m\n"

