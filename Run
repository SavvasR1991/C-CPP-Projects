#!/bin/bash
DIR=$(pwd)	

trap ctrl_c INT

function ctrl_c() {
        echo "** Trapped CTRL-C"
}
unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    MINGW*)     machine=MinGw;;
    *)          machine="UNKNOWN:${unameOut}"
esac
echo ${machine}

if [ ${machine} == "Linux" ]
then
	echo "Running programs in Linux Enviroment"
	if [ "$1" == "clean" ] 
	then
		echo "Clean up all folders.."
		find -type d -name build -prune -exec rm -rf {} \;
	else
		if [ "$1" != "" ]
		then
			echo "Ignoring extra arguments.."
		fi
        
        declare -a StringArray=("Computational-App" "Hanoi-Simulation" "Matrix-Max-Summary" "Object-Example-Simulation" "Telephone-List")
        for val in ${StringArray[@]}; do 
            cd $val 
            printf 'Running Projects in: %s\n Folder' "$val"
            ./Run
            cd ../
        done
	fi
fi
