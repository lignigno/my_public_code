#!/bin/zsh

cd /tmp/<user>

git add . > /tmp/null
git commit -m "save" > /tmp/null
git push > /tmp/null

if [ $? -ne 0 ]; then
	rm -rf /tmp/null
	exit 1
fi

rm -rf /tmp/null

printf "\033[1;38;2;255;0;128m"
printf "saved"
printf "\033[1;38;2;255;255;0m"
printf " :)\n"
printf "\033[1;38;2;255;0;128m"
printf "will be soon\033[0m\n"