# Writing Assistant

## Overview
This extends the functionality of the program by providing a menu-driven interface to perform various operations on the input text, including:

- Counting the number of non-whitespace characters.
- Counting the number of words.
- Fixing capitalization.
- Replacing exclamation marks with periods.
- Shortening sequences of multiple spaces.
  Usage

## To Run
1. Run the program.
2. Enter a string.
3. Choose an option from the menu to perform specific operations on the text.
4. Follow the prompts to continue analyzing or editing the text.
5. Choose 'q' to quit the program.

## Error Handling

The program handles unexpected user input as follows:

If the user enters a string longer than the maximum allowed length (49 characters for the warm-up exercise, 255 characters for the lab activity), the program truncates the input and continues processing.
If the user selects an invalid menu option in the lab activity, the program displays an error message and re-prompts for a valid choice.
Implementation Details

The program is implemented in C and organized into two modules: LabWarmup and LabActivity. Each module contains a main.c file where the program logic resides.

## Development Guidelines

Follow the provided style guide for coding conventions.
Ensure the code compiles without warnings using the provided Makefile.
Handle unexpected user input and error conditions gracefully.
Avoid memory-related errors such as buffer overflows or stack smashing.
