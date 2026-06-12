#pragma once

#include <raylib.h>
#include <vector>
#include <string>
#include "AlienInfo.hpp"


class Level {
   public:
      void readLevel(std::string fileName);
      int getCellSize();
      std::vector<GridInfo> getLevel(int level);


   private:
      void gridInit();
      std::vector<GridInfo> alienPlacement;
      const int gridX = 40;
      const int gridY = 18;
      const int cellSize = 48; 
      int difficulty;
      int level;
      bool levelFinished = false;
};
