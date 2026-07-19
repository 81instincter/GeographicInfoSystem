# GIS Point-in-Polygon Query Tool

A command-line **Geographic Information System (GIS)** tool that determines whether a given point lies inside one or more polygons using the **Ray-Casting Algorithm**. Built as part of COP3530 (Data Structures & Algorithms) at the University of West Florida.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-000000?style=for-the-badge)
![Catch2](https://img.shields.io/badge/Testing-Catch2-brightgreen)

## ✨ Features
- **Ray-Casting Algorithm** for accurate point-in-polygon detection (handles edges, vertices, and complex shapes)
- **Object-Oriented Design**: `Point`, `Polygon`, and `GIS` classes with proper encapsulation
- **Dynamic Memory Management** using raw pointers + RAII-like cleanup
- **Copy Constructor & Assignment Operator** for `Polygon`
- **Comprehensive Unit Tests** (Catch2 framework)
- **Modular & Readable** code following good C++ practices

## 🚀 Quick Start

### Prerequisites
- g++ (C++14 or later)
- Make

### Build & Run
```bash
# Clone the repo
git clone https://github.com/yourusername/GIS-School-Program.git
cd GIS-School-Program

# Compile
make

# Run with sample data
./main
