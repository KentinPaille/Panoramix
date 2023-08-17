# Panoramix

One refill at a time!

## Description

Second-year project made in `C`. The purpose of this project is to study examples of [threads](https://www.geeksforgeeks.org/multithreading-in-c/)
and [mutex programming](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/) and the algorithmic difficulties that go with it.

### Prerequisites
* `C` and `libc`
* [Make](https://www.gnu.org/software/make/)

### Context
The year is 50 BC. Gaul is entirely occupied by the Romans. Well, not entirely. . . One small village of indomitable
Gauls still holds out against the invaders. And life is not easy for the Roman legionaries who
garrison the fortified camps of Totorum, Aquarium, Laudanum and Compendium. . .


In this village the druid prepares a cooking pot of magic potions. The villagers get a serving of potion and
then procede to beat roman soldiers. When the pot is empty, the villager wakes up the druid and waits until
the druid has refilled the pot.

### Expectations
* Make use of [Semaphores](https://www.geeksforgeeks.org/use-posix-semaphores-c/)
* Make use of [Mutexes](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)
* Each villager, and the druid run in its own thread
* The cooking pot is full at the start of the program
* A villager’s thread stop when all the fights have been done (and hopefully won)
* The druid’s thread stop when he has no ingredients left to refill the pot
* The program stop gracefully when all the villager’s threads have stopped

## How to build project
To compile the `panoramix`, stack is used wrapped in a Makefile, which implements the following rules:
|   Command             |   Result          |
|-----------------------|-------------------|
|   `make`              | create a `panoramix` executable. |
|   `make clean`        | delete the files produced by the compilation. |
|   `make fclean`       | execute a `make clean`, and then delete the `panoramix` executable at the root of project. |
|   `make re`           | do the `fclean` and `all` rules (in that order) |

### Arguments
```sh
∼/B-CCP-400> ./panoramix
USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```
