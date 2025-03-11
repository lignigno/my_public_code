#!/bin/bash

SAVE_URL=""
LOGIN=""
PASSWORD=""
EMAIL="silentbob@mail.com"
SCRIPT_DIR=$(dirname "$(realpath "$0")")

setup_code() {

	printf "\033[1;38;2;0;255;255m\n"
	printf "1) Create new repository in your GITEA \033[0m(\033[1;38;2;255;255;0mEnter when created\033[0m)"
	read SAVE_URL
	SAVE_URL=""

	while [ -z "$SAVE_URL" ]; do
		printf "\033[1;38;2;0;255;255m\n"
		printf "2) Enter your repository link:\n"
		printf "\033[1;38;2;255;0;128m"
		read SAVE_URL
		if [ -z "$SAVE_URL" ]; then
			printf "\033[1;38;2;255;0;0m"
			printf "Repository link cannot be empty, please enter it.\n"
		fi
	done

	while [ -z "$LOGIN" ]; do
		printf "\033[1;38;2;0;255;255m\n"
		printf "Enter your \033[38;2;0;255;0mlogin\033[38;2;0;255;255m:\n"
		printf "\033[1;38;2;255;0;128m"
		read LOGIN
		if [ -z "$LOGIN" ]; then
			printf "\033[1;38;2;255;0;0m"
			printf "Login cannot be empty, please enter it.\n"
		fi
	done

	while [ -z "$PASSWORD" ]; do
		printf "\033[1;38;2;0;255;255m\n"
		printf "Enter your \033[38;2;255;0;0mpassword\033[38;2;0;255;255m:\n"
		printf "\033[1;38;2;255;0;128m"
		read -s PASSWORD
		if [ -z "$PASSWORD" ]; then
			printf "\033[1;38;2;255;0;0m"
			printf "Password cannot be empty, please enter it.\n"
		fi
	done

	printf "\n\033[1;38;2;0;255;255mEnter your some email \033[0m(\033[1;38;2;255;255;0mnot necessary\033[0m)\033[1;38;2;0;255;255m:\n"
	printf "\033[1;38;2;255;0;128m"
	read EMAIL
	if [ -z "$EMAIL" ]; then
		EMAIL="silentbob@mail.com"
	fi
	printf "\033[0m"

	cd $SCRIPT_DIR
	REP=$(git rev-parse --show-toplevel)
	trap 'rm -rf "$REP"' EXIT

	git config --global user.email "$EMAIL"
	git config --global user.name "$LOGIN"

	FINAL_URL="https://$LOGIN:$PASSWORD@${SAVE_URL#https://}"

	rm -rf /tmp/$LOGIN
	git clone $FINAL_URL /tmp/$LOGIN

	if [ $? -ne 0 ]; then
		printf "\n\033[1;38;2;255;0;0mERROR\033[0m\n\n"
		exit 1
	fi

	cp -f $SCRIPT_DIR/templates/* /tmp/$LOGIN

	sed -i '' "s|<user url>|$SAVE_URL|g" /tmp/$LOGIN/README.md
	sed -i '' "s|<user>|$LOGIN|g" /tmp/$LOGIN/README.md
	sed -i '' "s|<user>|$LOGIN|g" /tmp/$LOGIN/lis.sh
	sed -i '' "s|<user>|$LOGIN|g" /tmp/$LOGIN/save.sh
	sed -i '' "s|<user>|$LOGIN|g" /tmp/$LOGIN/deploy.sh

	cd /tmp/$LOGIN

	./deploy.sh
	./save.sh

	if [ $? -ne 0 ]; then
		printf "\n\033[1;38;2;255;0;0mERROR\033[0m\n\n"
		exit 1
	fi

	printf "\n\033[1;38;2;0;255;0mcomplete\033[0m\n\n"


	exit 0
}

setup_code


# 1)	*	спросить <user url> 
# 2)	*	спросить никнейм <user>
# 3)		спросить почту (по умолчанию silentbob@mail.com)
# 4)		сразу сделать гит клон с созданием ридми и закидыванием
#			скрипта деплоя который по умолчанию должен говорить что он не настроен и
# 			скрипта настройки если пользователь захочет перенастроить
# 
# 
# 
# 
# 

# draft
# 
# git clone <user url> /tmp/<user> && \
# echo "tmp/<user>/deploy.sh"
# 
# 
# предлагать ставить o my zsh
# 
# 
# in lis code dir :
#	- install.sh
#	- menuconfig.sh
#	- templates/
#		- deploy.sh
# 		- save.sh
# 
# сначало сделать
# 	ридми
# 	скрипт развёртывания
#
#