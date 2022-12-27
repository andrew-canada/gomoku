#!/bin/bash

msg=$1

git status
echo "continue? y/Y or n/N"
read answer
if [ ${answer^^} != "N" ]
then
    echo "let's push to git"
else
    echo "stop here"
    exit
fi

git add .
git status
git commit -m "$msg"
git status
git push
git status

