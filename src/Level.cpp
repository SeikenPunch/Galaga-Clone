#include "Level.hpp"
#include <fstream>
#include <iostream>

void Level::gridInit(){
   alienPlacement.resize(gridX * gridY); //x = i % gridX; y = i / gridX;
}

int Level::getCellSize(){
   return cellSize;
}

void Level::readLevel(std::string fileName){
   std::ifstream file(fileName);
   char currentChar;
   char delim;
   
   GridInfo g;
   // file layout: ALIEN_TYPE(int),x_pos,y_pos

   file.close();
}