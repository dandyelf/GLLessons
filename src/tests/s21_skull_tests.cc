#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

const std::string obj_path = TESTS_OBJ_PATH;

TEST(MainTest, Cubecarcas) {
  s21::Facade facade;
  const std::string file = obj_path + "/cubecarcas.obj";
  try {
    facade.OpenObj(file);
  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
  const s21::ObjT *obj = facade.GetObject();
  EXPECT_EQ(obj->count_of_facets, 432);
}
