#!/bin/bash

# Accepts runtime args, 
# writefile: path to file
# writestr: text string to be written in file
#
# Exits with return 1 error if parameters not specified
# Exits if file was not created


if [ $# -lt 2  ]; then
    printf "%b" "Error. Not enough arguments specified.\n" >&2
    printf "%b" "usage: ./write.sh writefile writestr\n" >&2
    exit 1
elif [ $# -gt 2  ]; then
    printf "%b" "Error. Too many arguments specified.\n" >&2
    printf "%b" "usage: ./write.sh writefile writestr\n" >&2
    exit 1
fi

writefile="$1"
writestr="$2"

{
    printf "%b" "${writestr}" > "${writefile}"
} || {
    printf "%b" "Error. Unable to create file ${writefile}\n"
    exit 1
}
