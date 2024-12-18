#!/bin/bash


if [ $# -ne 1 ]; then 
	echo "Example Usage: $0 <4 digit number> "
	exit 1
fi


echo -n "$1" | sha256sum | awk '{print $1}' > hash_output.txt


echo "The hashed number has been saved to hash_output.txt"
