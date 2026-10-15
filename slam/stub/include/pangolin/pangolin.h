#pragma once
// Minimal stand-in for Pangolin on Android. ORB-SLAM3 only touches this type in
// MapDrawer/Map.h; the desktop GL viewer is never built here.
// Map.h keeps a thumbnail buffer typed with desktop GL scalars, so the handful of
// typedefs it needs are declared here.
typedef unsigned char GLubyte;
typedef unsigned int GLuint;
typedef int GLint;
typedef float GLfloat;
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef int GLsizei;

namespace pangolin {
struct OpenGlMatrix {
  float m[16];
};
}