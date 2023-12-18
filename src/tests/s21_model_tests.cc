#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

const std::string obj_path = TESTS_OBJ_PATH;

TEST(FacadeTest, GetDataObj) {
  s21::Facade a;
  a.OpenObj(obj_path + "/tetrahedron.obj");
}
