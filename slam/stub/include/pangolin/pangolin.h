#pragma once
// Minimal stand-in for Pangolin on Android. ORB-SLAM3 only touches this type in
// MapDrawer/Map.h; the desktop GL viewer is never built here.
namespace pangolin {
struct OpenGlMatrix {
  float m[16];
};
}
