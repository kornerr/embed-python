PROJECT(EMBED_PYTHON)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Use C++11.
ADD_DEFINITIONS("-std=c++11")

# Create executable.
ADD_EXECUTABLE(embedPython src/main.cpp)
# Link executable with OpenSceneGraph libraries.
#TARGET_LINK_LIBRARIES(sampleApplication osg osgDB osgGA osgViewer)
