/*
 * @Author: Zhisheng Zeng
 * @Date: 2021-09-05 21:50:09
 * @Description:
 * @LastEditors: Zhisheng Zeng
 * @LastEditTime: 2021-09-16 15:18:42
 * @FilePath: /AStar/tests/simple.cpp
 */

#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "Model.h"
int main()
{
  astar::Model astar_model;
  astar_model.buildMap(4, 3);
  astar_model.addNodeCost({1, 0}, 10);
  astar_model.addNodeCost({1, 1}, 10);
  astar_model.addNodeCost({2, 0}, 10);
  astar_model.addNodeCost({2, 1}, 10);
  astar_model.addNodeCost({3, 0}, 10);
  astar_model.addNodeCost({3, 1}, 10);
  astar_model.addObstacle({2, 0}, 'H');
  astar_model.addObstacle({1, 1}, 'V');
  astar_model.disableDiagonalRouting();
  astar_model.enableTurningBack();
  astar_model.getPath({1, 0}, {3, 2});

  return 0;
}
