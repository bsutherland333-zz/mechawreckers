# Mechawreckers' Code Base

This is the code base for Mechawreckers' ME 330 (Mechatronics) project. Written in C for a PIC24F16KA301 microcontroller.


## Coding Style
This repo closely mimics the coding style found in this tutorial: https://www.codementor.io/@michaelsafyan/object-oriented-programming-in-c-du1081gw2
- Variables are in snake_case. my_variable
- Functions are in camelCase. myFunction()
- Classes are in UpperCamelCase. MyClass
- Class items are appended to their associated class name with two underscores. MyClass__class_item
- Private class items are denoted by a leading underscore _MyClass__class_item. Class name can be omitted if desired (__class_item).
- Any preprocessor variables should be defined in UPPERCASE.

## File Organization

- Write all code within the SRC directory.

- To organize our code, please make files that group functions into categories based on their function. For example, any functions that drive stepper motors should be put in a file and folder that is seperate from functions that drive servos and so on. 

## Compiling on MPLab IDE

- The code on in this directory won't compile unless you include the src directory in your project path