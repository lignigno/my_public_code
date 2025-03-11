#!/bin/zsh

# todo save

cd /tmp/<user>

git add .
git commit -m "save"
git push

printf "\033[1;38;2;255;0;128m"
printf "saved"
printf "\033[1;38;2;255;255;0m"
printf " :)\n"
printf "\033[1;38;2;255;0;128m"
printf "will be soon\033[0m\n"