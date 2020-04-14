#!/bin/bash

if [ -t 1 ]; then
    ANSI_RESET="$(tput sgr0)"
    ANSI_UNDERLINE="$(tput smul)"
    ANSI_RED="$(tput bold)$(tput setaf 1)"
    ANSI_YELLOW="$(tput bold)$(tput setaf 3)"
    ANSI_BLUE="$(tput bold)$(tput setaf 4)"
fi

trap 'echo "$ANSI_RESET"' EXIT SIGHUP SIGINT SIGQUIT SIGPIPE SIGTERM

VERBOSE=0
FILE="./dist/default/production/Source.production.hex"
LOCATIONS="3E00:4,8,12 3E10:0,4,8,12 3E20:0,4,8,12 3E30:0,4"

if [[ -f $FILE ]]; then
    cp $FILE $FILE.bak

    if [[ $VERBOSE -eq 0 ]]; then echo -n "${ANSI_YELLOW}"; fi

    for LOCATION in $LOCATIONS; do
        ADDRESS=`echo $LOCATION | cut -d: -f1`
        OFFSETS=`echo $LOCATION | cut -d: -f2 | tr ',' ' '`
        LINE=`egrep "^:..${ADDRESS}00" $FILE`
        if [[ $VERBOSE -ge 1 ]]; then echo "${ANSI_BLUE}$ADDRESS${ANSI_RESET}"; fi
        if [[ $VERBOSE -ge 2 ]]; then echo "${ANSI_BLUE}    $LINE${ANSI_RESET}"; fi

        CHECKSUM=0
        NEW_LINE=`echo $LINE | sed 's/..$//'`
        for OFFSET in $OFFSETS; do
            if [[ $VERBOSE -eq 0 ]]; then echo -n "."; fi
            NEW_OFFSET=$(( 9 + $OFFSET * 2 ))
            NEW_VALUE=$(( 30 + $RANDOM % 10 ))
            NEW_LINE=`echo $NEW_LINE | sed "s/^\\(.\\{$NEW_OFFSET\\}\\)../\\1$NEW_VALUE/"`
        done

        for ((I = 1; I <= $(( `echo $NEW_LINE | wc -c` - 2 )); I+=2)); do
            VALUE=`printf "%d" $(( 16#${NEW_LINE:$I:2} ))`
            CHECKSUM=$(( $CHECKSUM + $VALUE ))
        done
        CHECKSUM=$(( (255 - $CHECKSUM % 256 + 1) % 256 ))
        CHECKSUM_HEX=`printf "%02x" $CHECKSUM | tr [[:lower:]] [[:upper:]]`
        NEW_LINE="$NEW_LINE$CHECKSUM_HEX"

        if [[ $VERBOSE -ge 1 ]]; then echo "${ANSI_BLUE}    $NEW_LINE${ANSI_RESET}"; fi
        sed -i "s/$LINE/$NEW_LINE/" $FILE
    done

    if [[ $VERBOSE -eq 0 ]]; then echo "${ANSI_RESET}"; fi
else
    pwd
    echo "${ANSI_RED}Cannot find $FILE${ANSI_RESET}" >&2
fi
