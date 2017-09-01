#!/bin/sh
## pref.sh for ok in /home/abdel/CPE/dante
## 
## Made by abdel cherkaoui
## Login   <abdel@epitech.net>
## 
## Started on  Sat May 13 19:18:47 2017 abdel cherkaoui
## Last update Sun May 14 15:48:53 2017 abdel cherkaoui
##

RED='\033[0;31m'
NC='\033[0m'

GREEN='\033[0;32m'
NC='\033[0m'

clear
echo "MAKE ALL SOLVERS [  ]"
make re -s -C breadth/
make re -s -C depth/
make re -s -C astar/
make re -s -C generator/
make re -s -C tournament/
echo -e "MAKE ALL SOLVERS [ ${GREEN}OK${NC} ]"

echo "
[1] GENERATION [      ] 10 [SOLVABLE]"
./generator/generator 10 10 > ./maps/new.txt
echo -e "[1] GENERATION [  ${GREEN}OK${NC}  ] 10
"

echo "[2] TEST START!"
sleep 2;
clear


#START
echo "

"
echo -e "
         depth   [${RED}OK${NC}]
"
time ./depth/solver ./maps/new.txt
echo -e "
         depth   [${GREEN}OK${NC}]"
sleep 3;
clear

#START
echo "

"
echo -e "
         breadth   [${RED}OK${NC}]
"
time ./breadth/solver ./maps/new.txt

echo -e "
         breadth   [${GREEN}OK${NC}]"
sleep 3;
clear

#START
echo "

"
echo -e "
         Astar   [${RED}OK${NC}]
"
time ./astar/solver ./maps/new.txt
echo -e "
         Astar   [${GREEN}OK${NC}]"
sleep 3;
clear

#START
echo "

"
echo -e "
         WAR ALGORITH  [${RED}OK${NC}]
"
time ./tournament/solver ./maps/new.txt
echo -e "
         WAR ALGORITHM [${GREEN}OK${NC}]"
sleep 3;
clear




echo "[1] GENERATION [      ] 10K [SOLVABLE]"
./generator/generator 10000 10000 > ./maps/new.txt
echo -e "[1] GENERATION [  ${GREEN}OK${NC}  ] 10K"
echo "[2] TEST START!"
time ./breadth/solver ./maps/new.txt > ./test.txt
echo "
      breadth [OK]"
time ./depth/solver ./maps/new.txt > ./test.txt
echo "
      depth   [OK]"
time ./astar/solver ./maps/new.txt > ./test.txt
echo "
       Astar   [OK]"
time ./tournament/solver ./maps/new.txt > ./test.txt
echo "
      WAR ALGORITHM [OK]"

echo "
"

sleep 5;
clear

echo "[1] GENERATION [      ] 10K [PERFECT]"
./generator/generator 10000 10000 perfect > ./maps/new.txt
echo -e "[1] GENERATION [  ${GREEN}OK${NC}  ] 10K"
echo "[2] TEST START!"
time ./breadth/solver ./maps/new.txt > ./test.txt
echo "breadth [OK]"
time ./depth/solver ./maps/new.txt > ./test.txt
echo "depth   [OK]"
time ./astar/solver ./maps/new.txt > ./test.txt
echo "Astar   [OK]"
time ./tournament/solver ./maps/new.txt > ./test.txt
echo "WAR ALGORITHM [OK]"
clear
echo "[END DELETE TEST FILES] [  ]"
rm maps/new.txt
rm test.txt
echo "[END DELETE TEST FILES] [OK]"
