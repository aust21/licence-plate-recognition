# Licence Plate Recognition

This project is a licence plate recognition application built using C++, OpenCV, and CMake.

---

## Features
- Licence plate detection using OpenCV.
- Text extraction (future release)


## Prerequisites
Before building and running the project, ensure the following tools and libraries are installed:

### Required Tools
- **C++ Compiler**: GCC (>= 11.0) or MSVC
- **CMake**: >= 3.16

### Dependencies
- OpenCV: Image processing library
- GTK+: Required by some OpenCV functionalities
- libva-dev: For video acceleration

## Installation and Setup

### Step 1: Clone the Repository
```bash
git clone https://github.com/aust21/licence-plate-recognition.git
cd licence-plate-recognition
```

### Step 2: Install Dependencies
- **For Linux**: sudo apt-get install libopencv-dev
- **MacOS (Homebrew)**: brew install opencv
- **Windows**: Use a precompiled OpenCV distribution or build it from source.

### Step 3: Build the Project

Create build folder if it doesn't exist:

```bash
mkdir build
```

Generate a make file
```bash
cd build && cmake ..
```

Build the application
```bash
make
```

### Step 4: Run the Application

Run the generated executable:
```bash
./licence-detection
```

### Press q or Q to stop the program


## Acknowledgments
- [OpenCV](https://opencv.org/)
