#/bin/sh
## game.sh for ok in /home/abdel/CPE/dante
## 
## Made by abdel cherkaoui
## Login   <abdel@epitech.net>
## 
## Started on  Sun May 14 16:00:29 2017 abdel cherkaoui
## Last update Sun May 14 20:31:27 2017 Sid
##
cp ./game/game.exe game.tar.gz

tar -xzvf ./game.tar.gz

make re -C game

rm game.tar.gz
cd game

rm *.c *.o *~ *#
rm Makefile
rm my.h

./generator 100 100 ok
