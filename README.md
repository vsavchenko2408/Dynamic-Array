Dynamic Array — STL Containers From Scratch
📌 About

This project is my implementation of STL-like containers from scratch.
The goal is to deeply understand:

Memory management

RAII principle

Rule of Five

Copy / Move semantics

Dynamic allocation

Container design

Instead of just using std::array and std::vector, I implemented my own versions to understand how they work internally.

📦 Implemented Containers
1️⃣ Array

Features:

Template-based container

operator[]

at() with bounds checking

push_back()

size()

front() / back()

empty()

clear()

2️⃣ Vector (in progress)

Planned implementation of std::vector-like container with:

_size

_capacity

reserve()

resize()

push_back() with amortized growth

insert()

erase()

Iterators (begin() / end())

🧠 What I Learned

Difference between std::array and std::vector

Why move semantics are important

How double-free errors happen

Exception safety basics

Why capacity matters in dynamic containers

How STL containers are structured internally

🛠 Build

Project uses CMake.

mkdir build
cd build
cmake ..
make
📂 Project Structure
Dynamic-Array/
│
├── include/
│   ├── array.h
│   └── vector.h
│
├── src/
│   ├── array.cpp
│   ├── vector.cpp
│   └── main.cpp
│
├── CMakeLists.txt
└── README.md
🎯 Purpose

This project is part of my journey to become a C++ developer.

The focus is not on copying STL functionality, but on understanding:

How containers manage memory

How ownership transfer works

How to design safe and efficient classes

🚀 Future Improvements

Strong exception safety guarantees

Allocator support

Iterator implementation

Unit tests

Benchmark vs std::vector
