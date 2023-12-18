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
  std::vector<double> vertex_vector{};
  int count_of_vertexes{};
  int count_of_facets{};
  double max_el_{};
  double min_el_{};
  private:
    ObjT(){};
};

class ParserObj {
 public:
  ParserObj() = default;
  ParserObj(const ParserObj&) = delete;
  ParserObj(ParserObj&&) = delete;
  ~ParserObj() = default;
  void StartParser(const std::string& file_name, ObjT* obj);
  void ParsObj();
  void VertexLineCheck();
  void ParsLineVertex();
  void FacetLineCheck();
  std::string LineCreator(const std::string& dictionary);
  void ParsLineFacet(std::string& str);
  void SortInsert(const std::vector<int>& in);
  void PutOutVector(int a);

 private:
  ObjT* obj_;
  FILE* fp_;
  std::ifstream file_obj_;
};

}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
