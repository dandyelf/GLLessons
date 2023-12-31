#include "s21_parser_obj.h"

namespace s21 {

void ParserObj::StartParser(const std::string &file_name, ObjT *obj) {
  obj_ = obj;
  fp_ = fopen(file_name.c_str(), "r");
  if (fp_ == NULL) {
    throw std::runtime_error("File fail");
  }
  ParsObj();
  if (obj_->vertex_vector.size() < 3 || obj_->polygon_vector.size() < 1) {
    fclose(fp_);
    throw std::runtime_error("Empty of fail file");
  }
  fclose(fp_);
  for (const auto& element : obj_->vertex_vector) {
    if (obj_->max_el < element) obj_->max_el = element;
    if (obj_->min_el > element) obj_->max_el = element;
  }
}

void ParserObj::ParsObj() {
  while (1) {
    char lineHeader[128];
    int res = fscanf(fp_, "%s", lineHeader);
    if (res == EOF) break;
    if (strcmp(lineHeader, "v") == 0) {
      VertexLineCheck();
    }
    if (strcmp(lineHeader, "f") == 0) {
      FacetLineCheck();
    }
  }
}

void ParserObj::VertexLineCheck() { ParsLineVertex(); }

void ParserObj::ParsLineVertex() {
  double x, y, z;
  int matches = fscanf(fp_, "%lf %lf %lf\n", &x, &y, &z);
  if (matches == 3) {
    obj_->vertex_vector.push_back(x);
    obj_->vertex_vector.push_back(y);
    obj_->vertex_vector.push_back(z);
  } else {
    fp_++;
  }
}

void ParserObj::FacetLineCheck() {
  std::string tmp = LineCreator("1234567890-/ ");
  ParsLineFacet(tmp);
}

std::string ParserObj::LineCreator(const std::string &dictionary) {
  std::string tmp;
  char get = fgetc(fp_);
  while (dictionary.find(get) != std::string::npos && get != EOF) {
    tmp.push_back(get);
    get = fgetc(fp_);
  }
  return tmp;
}

void ParserObj::ParsLineFacet(std::string &str) {
  std::vector<int> tmp_vec;
  std::size_t i{};
  while (i < str.size()) {
    if (str[i] == ' ') {
      i++;
      continue;
    }
    std::string tmp;
    for (; i < str.size() && str[i] != ' '; i++) {
      tmp.push_back(str[i]);
    }
    tmp_vec.push_back(std::stoi(tmp));
    i++;
  }
  if (tmp_vec.size() > 2) {
    SortInsert(tmp_vec);
  }
}

void ParserObj::SortInsert(const std::vector<int> &in) {
  for (size_t i = 0; i < in.size(); i++) {
    for (size_t j = i; j <= i + 1 && (j + 1) <= in.size(); j++) {
      PutOutVector(in[j]);
    }
  }
  PutOutVector(in[0]);
  obj_->facet_elem += in.size() * 2;
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
