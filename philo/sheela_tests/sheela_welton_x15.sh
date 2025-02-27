#!/bin/bash
# make -C philo_bonus && clear
# exe=./philo_bonus/philo_bonus
pwd
make -C ../
exe=../philo

tests=10
color1="\e[41;30m"
color2="\e[1;31m"
color3="\e[42;30m"
color4="\e[1;32m"
reset="\e[0m"

x=1
time=0.1
echo -e "$color1 2 100 200 200 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 2 100 200 200 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 2 150 360 100 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 2 150 360 100 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 2 150 200 100 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 2 150 200 100 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 1 400 100 100 7 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 1 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color3 4 210 100 100 7 not die $reset"
while [ $x -le $tests ]
do
	printf $color4
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 4 210 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 1 800 200 200 7 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 1 800 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color3 5 800 200 200 7 not die $reset"
while [ $x -le $tests ]
do
	printf $color4
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 5 800 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 4 310 200 100 7 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 4 310 200 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color3 5 400 100 100 7 not die $reset"
while [ $x -le $tests ]
do
	printf $color4
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 5 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 5 200 100 100 7 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 5 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color3 3 400 100 100 7 not die $reset"
while [ $x -le $tests ]
do
	printf $color4
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 3 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 3 200 100 100 7 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 3 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color3 4 410 200 200 7 not die $reset"
while [ $x -le $tests ]
do
	printf $color4
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 4 410 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "$color1 4 399 200 200 7 should die $reset"
while [ $x -le $tests ]
do
	printf $color2
    echo -e "Test: $x$reset"
	stdbuf -oL $exe 4 399 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

make -C ../ fclean
#make -C ../philo_bonus fclean
