# Galaga Clone using raylib 5.5


<img width="1910" height="1071" alt="GalagaWIP" src="https://github.com/user-attachments/assets/497ee006-55ca-4754-a3e3-8995785716ea" />

## About this project:
### Motivation:
I wanted to make a game where I could focus on the technical aspects first and creative aspects second. This is the purpose behind making an already existing game. I wanted a game that was simple that managed entities so Galaga became my mission.

### Techniques
For this project I orignally wanted to use an ECS (Entity Component System) to manage entities. This would have been a great challenge attempting to make a program that was data-oriented. Although this would have been a challenge I settled with a hierarchical design. The reason for this is the enemeis in the game. It made sense to have all the entities that would interact to inherit from some common class and handle the interactions between all the entities in some entity manager class. Using an ECS for enemies that would all have almost the same components made no sense.
 
## How to compile:
This project uses C++ and CMake to compile. 

### Requirements
- C++ Compiler
- CMake
- raylib 5.5
- Git

### Windows Setup

#### Step 1:
Install MSYS2 and open the UCRT64 terminal and run the following commands:
```bash
pacman -Syu
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-raylib
```

#### Step 2:
Clone the repository onto your local machine.

#### Step 3:
I used the MSYS2 UCRT64 environment. To reduce differences in compilation I recommend using it as well.

#### Step 4:
Build
```bash
cmake -S . -B build -G "Makefiles"
cmake --build build
```

That should be all to build the program. I think...

