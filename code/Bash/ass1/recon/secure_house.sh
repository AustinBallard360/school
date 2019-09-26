#!/usr/bin/env bash
#Luke Schulz

##### TODO ###### ARRAYARIZE LEAVE(), STR MANIPULATION IS NOT GONNA CUT IT

OWNER="$1"; # first argument is owner of home
KEYS=${@:2}; # all the rest of arguments are key names
SECRET_KEY='FIREFIGHTER_SECRET_KEY'; #secret key always valid ? ( even after change locks?)

LASTKEY="" # Check for turning key vs inserting key
LASTPERSON="" # who is the last person to turn a key
GOODKEY=0 # 1 = yes, 0 = no
WHOSIN="" # string/list of folks inside # DEPRECATED :rage: 
declare -a WHOARR # array to who whos inside, replace WHOSIN
WHOCOUNT=0 # count of folks inside ( for comma seperated list building)

INSERT(){
	GOODKEY=0 # insert key clears last good key
	person="$3" 
	key="$4"
	if [[ ! -z $5 ]]; then # too many keys?
		echo "ERROR"
		return
	fi
	echo "KEY $key INSERTED BY $person";
	LASTKEY="$key" 
	LASTPERSON="$3"
}
TURN(){

	if [[ ! -z $4 ]]; then # too many params break it
		echo "ERROR"
		return
	fi
	person="$3";
	if [[ "$person" == "$LASTPERSON" ]]; then # i disagree w/ this, but ENFORCE POLICY, SAME USER MUST INSERT, TURN AND ENTER!
		for i in $KEYS #check the last inserted key which is being turned against all valid keys
			do 
				if [[ $LASTKEY =~ $i  ]]  ; then
					echo "SUCCESS $person TURNS KEY $LASTKEY";
					LASTPERSON="$person"; # if the door unlucks, save the person who did that
					GOODKEY=1; # set goodkey flag for enter function
					return
				fi
		done
		if [[ $LASTKEY == $SECRET_KEY ]] ; then # firefighter case
			echo "SUCCESS $person TURNS KEY $LASTKEY";
			LASTPERSON="$person"; # if the door unlucks, save the person who did that
			GOODKEY=1; # set goodkey flag for enter function
			return
		fi
	fi


	echo "FAILURE $person UNABLE TO TURN KEY $LASTKEY" 
	#GOODKEY=0;

}
ENTER(){
	if [[ ! -z $4 ]] || [[ -z $3 ]]; then # too many keys? // no user.
		echo "ERROR"
		return
	fi
	person=$3;
	if [[ "$person" == "$LASTPERSON" ]] && [[ $GOODKEY -eq 1 ]] ; then #idk if we need to check the person here. if the door is unlocked its unlocked???
		echo "ACCESS ALLOWED"
		GOODKEY=0 # one person enters per key swipe ?
		LASTPERSON=0 #needed? idk redundant but trying to enforce this policy		
		WHOARR+=("$person") # add mcperson to the array
		((WHOCOUNT++)) #increment count of people.

	else 
		echo "ACCESS DENIED"
		# need to reset GOODKEY & LASTPERSON Here.... ???
	fi
}
WHO(){	
		if [[ ! -z $3 ]]; then # check correct arguments
		echo "ERROR"
		return
	fi
	#if [ -z "$WHOSIN" ] ; then  #check 
	if [ "${#WHOARR[@]}" -eq 0 ] ; then  # check for empty array
		echo "NOBODY HOME";
	else

		WHOSINs=$( echo "${WHOARR[@]}"| tr " " "," )
		echo "$WHOSINs"

	fi

}
CHANGELOCKS(){
	if [[  -z $3 ]]; then # check correct arguments
		echo "ERROR"
		return
	fi
	person="$3"

	for dude in "${!WHOARR[@]}" ; do # check if owner is in the house
		if [[ ${WHOARR[dude]} = ${person} ]] && [[ "$person" == "$OWNER" ]] ; then # if the dude is our dude
			KEYS=${@:4}; # all the rest of arguments are key names
			echo "OK"
			return
		fi
	done
	echo "ACCESS DENIED"
}

LEAVE(){

	if [[ ! -z $4 ]] || [[ -z $3 ]]; then # check correct arguments
		echo "ERROR"
		return
	fi
	person="$3"

	for dude in "${!WHOARR[@]}" ; do # CHECK OUT LIST OF HOUSEE'S
		#echo "DUDE IS $dude" # DEBUG
		if [[ ${WHOARR[dude]} = ${person} ]] ; then # if the dude is our dude
			unset 'WHOARR[dude]' # remove dat hoe
			echo "OK"
			((WHOCOUNT--)) #do we need this idk kinda doubt it
			return
		fi
	done
	
	echo "$person NOT HERE" # if we did not find our guy and remove him and return, hes not here.

}

#### BEGIN MAIN #######
	#loop to EOF
	lineCount=0
	while IFS= read -r INPUT; do
	 # get line from stdin
		case "$INPUT" in #switch on key phrases
			*)
    			echo "$lineCount $INPUT "  >&2
				((lineCount++))
    			;;
		esac

	done