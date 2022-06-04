# Robothemall

### Authors : Léo LAVAL & Lucas RIBEIRO

## Libraries : 
### SFML2
To install SFML2, you have to execute the command below :
```
sudo apt-get install libsfml-dev
```

## How to play
Le but principal du jeu est de survivre le plus longtemps.
Ce jeu est prévu pour 2 joueurs en simultanés.
A la fin de chaque manche, les joueurs recuperent 10% de leur PV max.
Lorsqu'un joueur est mort, le deuxieme se retrouve seul jusqu'a la fin de la partie. (no respawn)

### Commands
The commands for the __first player__ are :
- Up / Down : Z/S
- Left / Right : Q/D
- Shoot : SpaceBar

For the __second player__ :
- Up / Down : I/K
- Left / Right : J/L
- Shoot : Enter

## Installation
If SFML2 is not installed, you have to install it otherwise you can not compile the game.

Open your terminal and execute the command below
- if you clone the game from github :
```
cd ~/github/Robothemall
make
./Robothemall
```
- else 
```
cd 'directory_path'
make
./Robothemall
```

## Our work:



## Bugs :
- On our keyboards, the second player can not move and shoot if the key-shoot button is "O".
- Random segmentation fault, we can not use valgrind to find it, because it's not often and valgrind is making the game lag...

## Resources :
Font for the game over : from fontspace.com, Super legend Boy.
Sprite for the robot : RPG Maker sprite
