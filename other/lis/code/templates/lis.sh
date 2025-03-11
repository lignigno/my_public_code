#!/bin/zsh

# LIS_SCRIPTS_DIR="/Users/Guest/Desktop/my_public_code/other/lis/code/templates"
LIS_SCRIPTS_DIR="/tmp/<user>"

EXIST_COMMANDS=( $(find "$LIS_SCRIPTS_DIR" -type f -name "*.sh" ! -name "deploy.sh" ! -name "lis.sh" -exec basename {} .sh \;) )
COMMAND="save"

if [ $# -gt 0 ]; then
	if is_command "$1"; then
		printf "correct command\n"
		COMMAND=$1
	else
		printf "\033[1;38;2;255;0;0m\n"
		printf "incorrect command :\033[0m $1\n"
		printf "exist commands :\n\n"

		for cmd in "${EXIST_COMMANDS[@]}"; do
			printf "- $cmd\n"
		done
		printf "\n"

		exit 1
	fi
fi

$LIS_SCRIPTS_DIR/$COMMAND.sh

is_command() {
	for cmd in "${EXIST_COMMANDS[@]}"; do
		if [ "$1" == "$cmd" ]; then
			return true
		fi
	done

	return false
}