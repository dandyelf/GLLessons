#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

const std::string obj_path = TESTS_OBJ_PATH;

TEST(WControllerTest, GetData) {
  s21::Controller controller_obj_;
  s21::Facade facade;
  const std::string file = obj_path + "/tetrahedron.obj";
  controller_obj_.SetModel(&facade);
  controller_obj_.OpenObj(file);
  EXPECT_EQ(controller_obj_.GetObject()->count_of_vertexes, 38);
  EXPECT_EQ(controller_obj_.GetObject()->count_of_facets, 252);
}

TEST(WControllerTest, MoveX) {
  s21::Controller controller_obj_;
  s21::Facade facade;
  const std::string file = obj_path + "/tetrahedron.obj";
  controller_obj_.SetModel(&facade);
  controller_obj_.OpenObj(file);
  const s21::ObjT *obj = controller_obj_.GetObject();
  EXPECT_DOUBLE_EQ(obj->vertex_vector[1], 14.433742000000001);
  EXPECT_DOUBLE_EQ(obj->vertex_vector[2], 40.824832999999998);
  controller_obj_.MoveObj('x', 5.0);
  EXPECT_DOUBLE_EQ(obj->vertex_vector[1], 14.433742000000001);
  EXPECT_DOUBLE_EQ(obj->vertex_vector[2], 40.824832999999998);
}

TEST(ControllerTest, TurnX) {
  s21::Controller controller_obj;
  s21::Facade facade;
  const std::string file = obj_path + "/Low-Poly-Racing-Car.obj";
  controller_obj.SetModel(&facade);
  controller_obj.OpenObj(file);
  EXPECT_DOUBLE_EQ(controller_obj.GetObject()->vertex_vector[1],
                   2.1189444065093999);
  EXPECT_DOUBLE_EQ(controller_obj.GetObject()->vertex_vector[2],
                   -5.0422310829162598);
  controller_obj.RotateObj('x', 5.0);
  EXPECT_DOUBLE_EQ(controller_obj.GetObject()->vertex_vector[1],
                   1.6714217881790148);
  EXPECT_DOUBLE_EQ(controller_obj.GetObject()->vertex_vector[2],
                   -5.207722044944874);
}

TEST(ControllerTest, ScaleX) {
  s21::Controller controller_obj;
  s21::Facade facade;
  const std::string file = obj_path + "/Low-Poly-Racing-Car.obj";
  controller_obj.SetModel(&facade);
  controller_obj.OpenObj(file);
  // EXPECT_DOUBLE_EQ(controller_obj->GetObject().vertex_vector[1], 2.11894);
  // EXPECT_DOUBLE_EQ(controller_obj->GetObject().vertex_vector[2], -5.04223);
  controller_obj.ScaleObj('x', 5.0);
  // EXPECT_DOUBLE_EQ(controller_obj->GetObject().vertex_vector[1], 2.11894);
  // EXPECT_DOUBLE_EQ(controller_obj->GetObject().vertex_vector[2], -5.04223);
}

// TEST(ControllerTest, ChangeSize) {
//   s21::Controller* controller_obj_;
//   controller_obj_ = s21::Controller::getInstance();
//   s21::Facade facade;
//   const std::string file = obj_path + "/Low-Poly-Racing-Car.obj";
//   controller_obj_->SetModel(&facade);
//   controller_obj_->OpenObj(file);
//   // EXPECT_EQ(controller_obj_->GetObject().vertex_vector[1], 2.11894);
//   // EXPECT_EQ(controller_obj_->GetObject().vertex_vector[2], -5.04223);
//   controller_obj_->ScaleObj('0', 5.0);
//   // EXPECT_EQ(controller_obj_->GetObject().vertex_vector[1], 10.5947);
//   // EXPECT_EQ(controller_obj_->GetObject().vertex_vector[2], -25.2112);
// }