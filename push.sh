#!/bin/bash

if [ $# == 1 ]; then
    msg=$1
else
    echo "Usage: push.sh <commit msg>"
    echo "commit with defualt msg"
    msg="update"
fi

echo $msg

echo "++++++++checking status++++++++"
git status
echo "++++++++add files++++++++"
git add .
echo "++++++++commit files++++++++"
git commit -m "$msg"
echo "++++++++push files++++++++"
git push