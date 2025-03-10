#!/bin/bash

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
SAVE_URL="SilentBob"
LOGIN="SilentBob"
EMAIL="silentbob@mail.com"


SCRIPT_DIR=$(dirname "$(realpath "$0")")

echo
echo 'trap 'rm -f "$SCRIPT_DIR"' EXIT'
printf "git clone $SAVE_URL /tmp/$LOGIN\n"
printf "cp $SCRIPT_DIR/templates/* /tmp/$LOGIN\n"
printf "replace <user url> and <user>\n"
printf "tmp/$LOGIN/deploy.sh\n"
echo

setup_code() {
	printf "\n\033[1;38;2;0;255;255m1) Create new repository in your GITEA \033[0m(\033[1;38;2;255;255;0mEnter when created\033[0m)"
	read SAVE_URL
	printf "\n\033[1;38;2;0;255;255m2) Enter your repository link:\n"
	printf "\033[1;38;2;255;0;128m"
	read SAVE_URL
	if [ -z "$SAVE_URL" ]; then
		SAVE_URL="SilentBob"
	fi

	printf "\n\033[1;38;2;0;255;255mEnter your login:\n"
	printf "\033[1;38;2;255;0;128m"
	read LOGIN
	if [ -z "$LOGIN" ]; then
		LOGIN="SilentBob"
	fi

	printf "\n\033[1;38;2;0;255;255mEnter your some email \033[0m(\033[1;38;2;255;255;0mnot necessary\033[0m)\033[1;38;2;0;255;255m:\n"
	printf "\033[1;38;2;255;0;128m"
	read EMAIL
	if [ -z "$EMAIL" ]; then
		EMAIL="silentbob@mail.com"
	fi

	echo 'trap 'rm -f "$SCRIPT_DIR"' EXIT'
	# printf "git clone $SAVE_URL /tmp/$LOGIN"
	git clone $SAVE_URL /tmp/$LOGIN
	# printf "cp $SCRIPT_DIR/templates/* /tmp/$LOGIN\n"
	cp $SCRIPT_DIR/templates/* /tmp/$LOGIN\n
	printf "replace <user url> and <user>\n"
	# printf "tmp/$LOGIN/deploy.sh\n"
	tmp/$LOGIN/deploy.sh\n

	# sed -i '' -e "s/^#[ *]LOGIN=.*$/LOGIN=\"$LOGIN\"/" "$0"
	# sed -i '' -e "s/^#[ *]EMAIL=.*$/EMAIL=\"$EMAIL\"/" "$0"
	# sed -i '' -e "/^setup_code$/ s/^/# /" "$0"



	printf "\n\033[1;38;2;0;255;0mcomplete\033[0m\n\n"

	exit 0
}

# setup_code

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
# 
# 
# сначало сделать
# 	ридми
# 	скрипт развёртывания
#
#