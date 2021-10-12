/*
 * @Author: Zhisheng Zeng
 * @Date: 2021-09-05 21:50:09
 * @Description:
 * @LastEditors: Zhisheng Zeng
 * @LastEditTime: 2021-10-12 21:52:51
 * @FilePath: /astar/tests/gtest.cpp
 */

#include "Model.h"
#include "gtest/gtest.h"

namespace {

TEST(RoutingTest, Reached)
{
  astar::Model astar_model;
  astar_model.buildMap(8, 4);
  astar_model.addObstacle({0, 0}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({0, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({1, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({3, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({5, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({5, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 3}, astar::NodeType::kOmniObs);
  EXPECT_TRUE(astar_model.getPath({0, 3}, {7, 0}).size());
}

TEST(RoutingTest, NoWhere)
{
  astar::Model astar_model;
  astar_model.buildMap(8, 4);
  astar_model.addObstacle({0, 0}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({0, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({1, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({3, 0}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({3, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({5, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({5, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 3}, astar::NodeType::kOmniObs);
  EXPECT_FALSE(astar_model.getPath({0, 3}, {7, 0}).size());
}

TEST(RoutingTest, Reached1)
{
  astar::Model astar_model;
  astar_model.buildMap(8, 5);
  astar_model.addObstacle({2, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({0, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({1, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({3, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 4}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({5, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 3}, astar::NodeType::kOmniObs);
  astar_model.disableDiagonalRouting();
  astar_model.enableTurningBack();
  EXPECT_TRUE(astar_model.getPath({0, 4}, {7, 0}).size());
}

TEST(RoutingTest, NoWhere1)
{
  astar::Model astar_model;
  astar_model.buildMap(8, 5);
  astar_model.addObstacle({2, 1}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({0, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({1, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({3, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({4, 4}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({5, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({6, 3}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 2}, astar::NodeType::kOmniObs);
  astar_model.addObstacle({7, 3}, astar::NodeType::kOmniObs);
  astar_model.disableDiagonalRouting();
  astar_model.disableTurningBack();
  EXPECT_FALSE(astar_model.getPath({0, 4}, {7, 0}).size());
}

}  // namespace
