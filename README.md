# Mechawreckers' Code Base

This is the code base for Mechawreckers' ME 330 (Mechatronics) project. Written in C for a PIC24F16KA301 microcontroller.


## Coding Style
This repo closely mimics the coding style found in this tutorial: https://www.codementor.io/@michaelsafyan/object-oriented-programming-in-c-du1081gw2
- Variables are in snake_case. my_variable
- Functions are in camelCase. myFunction()
- Classes are in UpperCamelCase. MyClass
- Class items are appended to their associated class name with two underscores. MyClass__class_item
- Private class items are denoted by a leading underscore _MyClass__class_item
- Any preproccessor variables  should be defines in UPPERCASE.

## File Organization

To organize our code, please make files that group functions into categories based on their function. For example, any functions that drive stepper motors should be put in a file that is seperate from functions that drive servos and so on. 