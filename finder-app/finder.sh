#!/bin/bash

# Accepts runtime args, 
# filesdir: path to directory:
# searchstr: text string to searched within these files
#
# Exists with return 1 error if parameters not specified
# Exits return value 1 if filesdir does not represent a directory on the filesystem

if [ $# -lt 2  ]; then
    printf "%b" "Error. Not enough arguments specified.\n" >&2
    printf "%b" "usage: ./finder.sh filesdir searchstr\n" >&2
    exit 1
elif [ $# -gt 2  ]; then
    printf "%b" "Error. Too many arguments specified.\n" >&2
    printf "%b" "usage: ./finder.sh filesdir searchstr\n" >&2
    exit 1
fi


filesdir="$1"
searchstr=$2

if [ ! -d "${filesdir}" ]; then
    printf "%b" "Error. ${filesdir} does not represent a directory on the filesystem."
    exit 1
fi

files_found=`ls ${filesdir}`
num_files=`ls ${filesdir} | wc -l`
counter=0
for filename in $filesdir/*; do
    #echo "file=${filename}"
    res=`grep -nHR "${searchstr}" "${filename}"`
    #echo "grep ${searchstr} ${filename}"
    if [ ! -z "$res" ]; then
        #echo "Found match ${res}"
       ((counter++))
    fi
done
printf "%b" "The number of files are ${num_files} and the number of matching lines are ${counter}\n"
