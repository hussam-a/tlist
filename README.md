# tlist
Task Lister Loadable Kernel Module

Authors:

Hussam A. El-Araby (github.com/hussam-a)

Project code and configurations are under the GNU GPL license (tlist/LICENSE)

This project is a Linux task lister , implemented as a loadable kernel module.

# Project structure:

- C++ source code to compile (tlist/src)
  * tlistd , lists tasks in a depth first manner and produces a tree output
  * tlistl, lists tasks as numbered by their PIDs
