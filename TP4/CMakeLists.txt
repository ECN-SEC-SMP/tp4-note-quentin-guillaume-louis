cmake_minimum_required(VERSION 3.5)
project(MyProject)

# Set the source files (add all your .cpp files here)
set(SOURCE  
    "PolyTests.cpp"      
    "TP4.cpp"      
    "utility.cpp"
)

# Set the header files (add all your .h files here)
set(HEADER 
    "Constructible.h"    
    "Parcelle.h"    
    "Point2D.h"    
    "Polygone.h"    
    "utility.h"    
    "ZA.h"    
    "ZAU.h"    
    "ZN.h"    
    "ZU.h"    
)

# Optionally, print the collected files (useful for debugging)
message(STATUS "Source files: ${SOURCE}")
message(STATUS "Header files: ${HEADER}")

# Add executable or library
add_executable(MyExecutable ${SOURCE} ${HEADER})

# Or if you want to create a library instead of an executable:
# add_library(MyLibrary ${SOURCE} ${HEADER})
