#ifndef LOGO_H
#define LOGO_H

#include <qopengl.h>

#include <QList>
#include <QVector3D>
#include <vector>

#include "../model/s21_parser_obj.h"

class Logo {
 public:
  Logo();
  Logo(std::vector<GLfloat> vector);
  Logo(const s21::ObjT *obj);
  const GLfloat *constData() const { return m_data.constData(); }
  int count() const { return m_count; }
  int vertexCount() const { return m_count / 6; }  //!!!!!!!!!!!!!!!

 private:
  void quad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3,
            GLfloat y3, GLfloat x4, GLfloat y4);
  void extrude(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
  void CreateLogo(std::vector<GLfloat> vector);

  void add(const QVector3D &v, const QVector3D &n);

  QList<GLfloat> m_data;
  int m_count = 0;
};

#endif  // LOGO_H
