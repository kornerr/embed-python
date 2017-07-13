PROJECT(EMBED_PYTHON)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Use C++11.
ADD_DEFINITIONS("-std=c++11")

FIND_PACKAGE(PythonLibs 3 REQUIRED)
IF (PYTHONLIBS_FOUND)
    INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
    #LINK_DIRECTORIES(${PYTHON_LIBRARIES})
    #MESSAGE(${PYTHON_LIBRARIES})
ELSE ()
    MESSAGE(
        FATAL_ERROR
        "Could not find Python libraries. Do you have development package installed?")
ENDIF ()

# Create executable.
ADD_EXECUTABLE(embedPython src/main.cpp)
# Link executable with Python library.
TARGET_LINK_LIBRARIES(embedPython ${PYTHON_LIBRARIES})

ADD_LIBRARY(spam MODULE src/spammodule.cpp)
TARGET_LINK_LIBRARIES(spam ${PYTHON_LIBRARIES})
SET_TARGET_PROPERTIES(spam PROPERTIES PREFIX "")
