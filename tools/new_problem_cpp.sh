#!/bin/bash

# Hack to  find the directory of this script.
pushd `dirname $0` > /dev/null
SCRIPTPATH=`pwd`
popd > /dev/null

PROBLEM="$1";
PROBLEMPATH="$SCRIPTPATH/../$PROBLEM";

# Check that problem number is specified.
if [ -z "$1" ]; then
    echo "No problem number specified!"
    echo "Exampe usage: ./new_problem_cpp.sh 123"
    exit
fi

# Check that the problem does not exist already.
if [ -d "$PROBLEMPATH" ]; then
    echo "Problem already exists!"
    exit
fi

echo "Creating new problem $PROBLEM from C++ template"; 

# Copy template project.
cp -r "$SCRIPTPATH/template_cpp" "$PROBLEMPATH"

# Replace placeholder with real values.
sed -i -e 's/xyz/'"$PROBLEM"'/g' "$PROBLEMPATH"/*
rm -rf "$PROBLEMPATH"/*-e

mv "$PROBLEMPATH"/problem_xyz.hpp  "$PROBLEMPATH"/problem_"$PROBLEM".hpp
mv "$PROBLEMPATH"/problem_xyz.cpp  "$PROBLEMPATH"/problem_"$PROBLEM".cpp
