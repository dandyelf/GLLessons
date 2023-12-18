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
  std::cout << obj->vertex_vector[1] << obj->vertex_vector[2] << std::endl;
  EXPECT_DOUBLE_EQ(obj->vertexes[1], 1.9741823066312869e-218);
  EXPECT_DOUBLE_EQ(obj->vertexes[2], 0.942809137006836);
  // controller_obj_.MoveObj('x', 5.0);
  // EXPECT_DOUBLE_EQ(controller_obj_.GetObject().vertexes[1], 4.1188916263050621e+144);
  // EXPECT_DOUBLE_EQ(controller_obj_.GetObject().vertexes[2], 0.942809137006836);
}

// TEST(ControllerTest, TurnX) {
//   s21::Controller* controller_obj_;
//   controller_obj_ = s21::Controller::getInstance();
//   s21::Facade facade;
//   const std::string file = obj_path + "/Low-Poly-Racing-Car.obj";
//   controller_obj_->SetModel(&facade);
//   controller_obj_->OpenObj(file);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
//   controller_obj_->RotateObj('x', 5.0);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 1.67142);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.20772);
// }

// TEST(ControllerTest, ScaleX) {
//   s21::Controller* controller_obj_;
//   controller_obj_ = s21::Controller::getInstance();
//   s21::Facade facade;
//   const std::string file = obj_path + "/Low-Poly-Racing-Car.obj";
//   controller_obj_->SetModel(&facade);
//   controller_obj_->OpenObj(file);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
//   controller_obj_->ScaleObj('x', 5.0);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
// }

// TEST(ControllerTest, ChangeSize) {
//   s21::Controller* controller_obj_;
//   controller_obj_ = s21::Controller::getInstance();
//   s21::Facade facade;
//   const std::string file = obj_path + "/Low-Poly-Racing-Car.obj";
//   controller_obj_->SetModel(&facade);
//   controller_obj_->OpenObj(file);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
//   controller_obj_->ScaleObj('0', 5.0);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 10.5947);
//   // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -25.2112);
// }