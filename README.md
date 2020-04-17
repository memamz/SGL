# SGL
A Simple Generic Library written in C++ providing most of the basic functionalities for many applications. It was created for my personal use as a simple library to include and modify while testing new ideas with the least dependencies possible.

The library is designed to be easy to include, understand and modify. While I'll try to optimize whenever I can, I'll always favor simplicity and generality as this is the main goal. The library is not suitable for production applications, there are tons of opensource libraries optimized for specific functionalities, I would only recommend using it for testing new ideas or creating demos and simple applications.

The project is still a work in progress and will be updated regularly with new functionalities.

It contains the following modules as separate namespaces:
- [x] SGCore: for a variety of useful utilities, e.g., PRNGs, memory management.
- [x] SGWin: for windows specific functions.
- [x] SGMath: for 3D mathematics and other common mathematical functions.
- [ ] SGAlg: for common algorithms and data structures.
- [ ] SGNet: for networking purposes.
- [x] SGCG: for computer graphics and rendering related functionalities.
- [ ] SGAI: for artificial intelligence purposes, genetic algorithms.
- [ ] SGNN: for neural networks and deep learning.
- [ ] SGPCG: for procedural content generation.
- [ ] SGSim: for simulation helpers, integrators and solvers.
- [ ] SGGPU: a wrapper for CUDA and some useful kernels.
- [ ] SGSec: for security and encryption functions.
