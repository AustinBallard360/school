#!/usr/bin/env bash
#Luke Schulz

##### TODO ###### ARRAYARIZE LEAVE(), STR MANIPULATION IS NOT GONNA CUT IT

OWNER="$1"; # first argument is owner of home
KEYS=${@:2}; # all the rest of arguments are key names
SECRET_KEY='FIREFIGHTER_SECRET_KEY'; #secret key always valid ? ( even after change locks?)

LASTKEY="" # Check for turning key vs inserting key
LASTPERSON="" # who is the last person to turn a key
GOODKEY=0; # 1 = yes, 0 = no
WHOSIN=""; # string/list of folks inside
WHOCOUNT=0; # count of folks inside ( for comma seperated list building)

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
		if [[ $LASTKEY =~ $SECRET_KEY ]] ; then # firefighter case
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
		if (( WHOCOUNT >= 1)); then # need condition for building comma seperated list
			WHOSIN+=",$person" #subsequent entries need a comma
			
		else
			WHOSIN+="$person" # test case shows single entry w/o comma
		fi

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
	if [ -z "$WHOSIN" ] ; then  #check 
		echo "NOBODY HOME";
	else
		echo "$WHOSIN"

	fi

}
CHANGELOCKS(){
	#check for owner inside , and if hes the one calling for changelocks
	if [[ $WHOSIN =~ "$OWNER" ]] && [[ "$3" == "$OWNER" ]]; then
		KEYS=${@:4}; # all the rest of arguments are key names
		echo "OK"
	else
		echo "ACCESS DENIED"
	fi
}

LEAVE(){

	### THIS IS BROKEN. STRING MANIPULATION HAS FAILED ME.
	### IF YOU GET The order of Luke2, Luke3 , Luke, and you LEAVE() LUKE, it will leave you with 
	### "2, Luke3, Luke"
	### Idk how to fix this
	if [[ ! -z $4 ]] || [[ -z $3 ]]; then # check correct arguments
		echo "ERROR"
		return
	fi
	person="$3"


	if [[ $WHOSIN =~ "$person" ]]; then

		echo "OK"
		lessWho="${WHOSIN/$person/}" # this leaves extra comma, im out of my depth in regex.
		WHOSIN=$( echo $lessWho | sed 's/,,/,/g' ) #() for cmd, Sed just replaces any double comma with single comma(sanitize)
		if [[ "$WHOSIN" =~ ","* ]] ; then # if first char is comma from deleting head of list. (( I know this string manipulation is getting wild im sorry))
			WHOSIN="${WHOSIN#,}" # should remove front comma
		fi 
		((WHOCOUNT--))
	else
		echo "NOT HERE"
	fi
}

#### BEGIN MAIN #######
	#loop to EOF
	while IFS= read -r INPUT; do
	 # get line from stdin
		case "$INPUT" in #switch on key phrases
			"INSERT KEY"*)
				INSERT $INPUT;;
			"TURN KEY"*)
				TURN $INPUT;;
			"ENTER HOUSE"*)
				ENTER $INPUT;;
			"WHO'S INSIDE?"*)
				WHO $INPUT;; # input not needed, never any params
			"CHANGE LOCKS"*)
				CHANGELOCKS $INPUT;;
			"LEAVE HOUSE"*)
				LEAVE $INPUT;;
			*)
    			echo "ERROR";;
		esac

	done