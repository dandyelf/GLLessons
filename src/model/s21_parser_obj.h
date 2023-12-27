#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <string>
#include <vector>

namespace s21 {

class ObjT {
  friend class AffTransform;
  friend class Facade;
  friend class ParserObj;

 public:
  ~ObjT(){};
  std::vector<int> polygon_vector{};
  std::vector<float> vertex_vector{};
  size_t count_of_vertexes{};
  size_t count_of_facets{};
  float max_el_{};
  float min_el_{};

 private:
  ObjT(){};
};

class ParserObj {
 public:
  ParserObj() = default;
  ParserObj(const ParserObj&) = delete;
  ParserObj(ParserObj&&) = delete;
  ~ParserObj() = default;
  void StartOpen(const std::string& file_name, ObjT* obj);
  void Pars();
  void ParsLineVertex(std::istringstream& iss);
  void InitObj();
  void ParsLineFacet(std::istringstream& iss);
  void ToTriangles(std::vector<int>& vect);
  void SortInsert(const std::vector<int>& in);
  void PutOutVector(int a);

 private:
  ObjT* obj_;
  std::ifstream file_obj_;
};

}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
