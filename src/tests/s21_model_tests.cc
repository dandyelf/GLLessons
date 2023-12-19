#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

const std::string obj_path = TESTS_OBJ_PATH;

TEST(ModelFacade, GetObj) {
  s21::Facade a;
  a.OpenObj(obj_path + "/tetrahedron.obj");
  EXPECT_EQ(a.GetObject()->count_of_vertexes, 38);
}

TEST(ModelFacade, StartOpen) {
  s21::Facade a;
  a.OpenObj(obj_path + "/tetrahedron.obj");
  EXPECT_EQ(a.GetObject()->count_of_vertexes, 38);
}

TEST(ModelFacade, Skull) {
  s21::Facade a;
  a.OpenObj(obj_path + "/skull.obj");
  EXPECT_EQ(a.GetObject()->count_of_vertexes, 6122);
}
