
# Overview

This repository contains examples created by following
[Extending and Embedding the Python Interpreter](https://docs.python.org/3.5/extending/index.html).

The final goal is to have a Python support in a C++ application.

# Prerequisites

You need `libpython3-dev` package on Ubuntu.

# Samples
## 1. spam

Once `spam.so` is built, you can spawn a Python3 interpreter like this:

`PYTHONPATH=/path/to/build/dir/embed-python python3`

Then you can do the following:

`import spam`

`spam.system("cat abc")`

