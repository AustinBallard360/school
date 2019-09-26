#!/usr/bin/env bash

key=$1

if [[ -ne $key ]] ; then
	echo "Need key"
	exit 1
fi

while IFS= read -r INPUT; do
	#delete spaces
	#use TR, how to pass input to TR idk

	##switch each letter with TR again ?

	# echo each line ?
	#is line by line ceasar good enough ?
done

