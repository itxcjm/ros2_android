#!/usr/bin/env python3
"""Expose the complete active ORB-SLAM3 map to the Android JNI bridge."""
from pathlib import Path
import sys

root = Path(sys.argv[1])
header = root / "include/System.h"
source = root / "src/System.cc"

text = header.read_text()
if "std::vector<MapPoint*> GetAllMapPoints();" not in text:
    needle = "std::vector<MapPoint*> GetTrackedMapPoints();"
    if text.count(needle) != 1:
        raise SystemExit("System.h: tracked map point declaration not found exactly once")
    header.write_text(text.replace(needle, needle + "\n    std::vector<MapPoint*> GetAllMapPoints();"))

text = source.read_text()
if "System::GetAllMapPoints()" not in text:
    needle = "vector<cv::KeyPoint> System::GetTrackedKeyPointsUn()"
    if text.count(needle) != 1:
        raise SystemExit("System.cc: keypoint method not found exactly once")
    method = ("vector<MapPoint*> System::GetAllMapPoints()\n"
              "{\n"
              "    return mpAtlas->GetAllMapPoints();\n"
              "}\n\n")
    source.write_text(text.replace(needle, method + needle))
