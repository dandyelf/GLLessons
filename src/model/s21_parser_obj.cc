#include "s21_parser_obj.h"

#include <iostream>
#include <sstream>

namespace s21 {

void ParserObj::StartOpen(const std::string& file_name, ObjT* obj) {
  obj_ = obj;
  file_obj_.open(file_name);
  if (!file_obj_.is_open()) {
    throw std::runtime_error("File fail");
  }
  Pars();
  if (obj_->vertex_vector.size() < 3 || obj_->polygon_vector.size() < 3) {
    file_obj_.close();
    throw std::runtime_error("Empty of fail file");
  }
  file_obj_.close();
  InitObj();
}

void ParserObj::Pars() {
  std::string line;
  while (std::getline(file_obj_, line)) {
    std::istringstream iss(line);
    std::string lineHeader;
    iss >> lineHeader;
    if (lineHeader == "v") {
      ParsLineVertex(iss);
    }
    if (lineHeader == "f") {
      ParsLineFacet(iss);
    }
  }
}

void ParserObj::ParsLineVertex(std::istringstream& iss) {
  double x, y, z;
  if ((iss >> x >> y >> z)) {
    obj_->vertex_vector.push_back(x);
    obj_->vertex_vector.push_back(y);
    obj_->vertex_vector.push_back(z);
  }  // else error check if need
}

void ParserObj::InitObj() {
  obj_->count_of_vertexes = obj_->vertex_vector.size() / 3;
  obj_->count_of_facets = obj_->polygon_vector.size() / 2;
  obj_->max_el_ = obj_->vertex_vector[0];
  obj_->min_el_ = obj_->vertex_vector[0];
  for (auto element : obj_->vertex_vector) {
    if (obj_->max_el_ < element) obj_->max_el_ = element;
    if (obj_->min_el_ > element) obj_->min_el_ = element;
  }
  size_t max_vertex = obj_->polygon_vector[0];
  for (auto element : obj_->polygon_vector) {
    if (max_vertex < element) max_vertex = element;
  }
  if (max_vertex > obj_->count_of_vertexes) {
    throw std::runtime_error("On vertex " + std::to_string(max_vertex));
  }
}

void ParserObj::ParsLineFacet(std::istringstream& iss) {
  std::vector<int> tmp_vec;
  std::string tmp;
  while (iss >> tmp) {
    tmp_vec.push_back(std::stoi(tmp));
  }
  if (tmp_vec.size() > 3) {
    ToTriangles(tmp_vec);  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  } else if (tmp_vec.size() > 2) {
    SortInsert(tmp_vec);
  }  // else push error if need
}

void ParserObj::ToTriangles(std::vector<int>& vect) {
  std::vector<int> tmp_vec(3);
  tmp_vec[0] = vect[0];
  tmp_vec[1] = vect[1];
  tmp_vec[2] = vect[2];
  SortInsert(tmp_vec);
  for (size_t i = 2; i < vect.size(); i++) {
    tmp_vec[0] = vect[0];
    tmp_vec[1] = vect[i - 1];
    tmp_vec[2] = vect[i];
    SortInsert(tmp_vec);
  }
}

void ParserObj::SortInsert(const std::vector<int>& in) {
  // for (size_t i = 0; i < in.size(); i++) {
  //   for (size_t j = i; j <= i + 1 && (j + 1) <= in.size(); j++) {  // For
  //   GL_LINES
  //     PutOutVector(in[j]);
  //   }
  // }
  // PutOutVector(in[0]);
  for (size_t i = 0; i < in.size(); i++) {
    PutOutVector(in[i]);
  }
}

void ParserObj::PutOutVector(int a) {
  int b;
  if (a < 0) {
    b = (a + obj_->vertex_vector.size() / 3);
  } else {
    b = a - 1;
  }
  if (b >= 0 && b < (int)obj_->vertex_vector.size()) {
    obj_->polygon_vector.push_back(b);
  }  //  else push error if need
}

}  // namespace s21
