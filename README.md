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

The main goal of the game is to survive the enemy horde that try to kills you.
The game is a simultaneous 2 players game and each player are controlling one of the characters.
They need to shoot at enemies to kill them and go on another round.
At the end of each round, each player is healed by 10% of their max HP.
When a player dies, he would not respawn at any moment and when the second die, the game is over.


### Commands
The commands for the **first player** are :
- Up / Down : Z/S
- Left / Right : Q/D
- Shoot : SpaceBar

For the **second player** :
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
For this project, we have worked in pair. First of all, we started by choosing a game that will make both of us comfortable to work with: we have chosen a game of beat them all based on the game Vampire Survivors.

We have started by making a display of the window together because we could not work apart if the window wasn't ready. For us, graphics were the starting point.
When our window was ready, we split the work to optimise our time. However, we generally worked together using teletype on atom which is a feature that permit us to work as if we were on the same computer.

Lucas mainly focusses on the collisions, the sprites and the tests, where Léo was making the shifts, the rounds and the bullets.

The game is based on one major abstract class: Entity. All of the things displayed on the screen are one and are separated in different lists in the Map.
The window runs in the class Game, which is displayed in the class Renderer. Check the UML for a better understanding.

Our game is specially design to easily add entities. At first, we wanted to add items to help the players but we did not have the time to do it. However, it is totally possible to make some appears randomly on the screen because all of the main function are already here. You just have to implement a list of items in the map and check the collision with the player.
We can also derivate our existing classes to add particularities such as for instance a "Boss" which is a foe with a name displayed and different abilities.

At first our collisions were not working correctly. Our entities always were teleporting themselves in the top left corner of the one them were colliding with. Because our game is mainly based on collision, we had to find a solution. So, we decided to create our own collision function with the help of an online tutorial.
We also learned that we couldn't use a list of abstract class as we wanted to do with our entities, because we could not use their functions.
We also used Boolean statuses in each character classes that are really useful in games. But the Booleans that needs to turn back after a short delay were really challenging (in the class player: a player can not be hit twice in less than 300 ms and can shoot bullets one at a time).

We are particularly proud of our debugging sessions during which we browsed many forums and websites in order to better understand how SFML works and to improve some features. We did theses sessions all along the project and hit really helped us. Now, we know that a graphic card is not reliable, and can have memory leaks by itself. Also, we know that valgrind only check freed blocks through the main function.


## Bugs :
- On our keyboards, the second player can not move and shoot if the key-shoot button is "O".
- Random segmentation fault appears randomly (maybe no sufficient RAM on our virtual machines).
- Valgrind strongly slows down the execution of the game, the use was difficult to exploit.

## Resources :
Font for the game over : from fontspace.com, Super legend Boy.
Sprite for the robot : RPG Maker sprite

### Enjoy our game !
