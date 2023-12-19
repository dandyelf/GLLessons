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
  if (obj_->vertex_vector.size() < 3 || obj_->polygon_vector.size() < 1) {
    file_obj_.close();
    throw std::runtime_error("Empty of fail file");
  }
  file_obj_.close();
  InitObj();
}

void ParserObj::Pars() {
std::string line;
  while (std::getline(file_obj_, line))
  {
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
  } // else error check if need
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
  int max_vertex = obj_->polygon_vector[0];
  for (auto element : obj_->polygon_vector) {
    if (max_vertex < element) max_vertex = element;
  }
  if (max_vertex > obj_->count_of_vertexes)
  {
    throw std::runtime_error("On vertex " + max_vertex);
  }
}

void ParserObj::ParsLineFacet(std::istringstream& iss) {
  std::vector<int> tmp_vec;
  std::string tmp;
  while (iss >> tmp) {
    tmp_vec.push_back(std::stoi(tmp));
  }
  if (tmp_vec.size() > 2) {
    SortInsert(tmp_vec);
  } // else push error if need
}

void ParserObj::SortInsert(const std::vector<int> &in) {
  for (size_t i = 0; i < in.size(); i++) {
    for (size_t j = i; j <= i + 1 && (j + 1) <= in.size(); j++) {
      PutOutVector(in[j]);
    }
  }
  PutOutVector(in[0]);
}

void ParserObj::PutOutVector(int a) {
  int b;
  if (a < 0) {
    b = (a + obj_->vertex_vector.size() / 3 + 1);
  } else {
    b = a;
  }
  obj_->polygon_vector.push_back(b - 1);
}

}  // namespace s21
