# Capstone-Apexcoderz
# Sleep Inducer System

## Overview
This program simulates a sleep inducer system for managing inmates' sleep data and inducing sleep through sound. It allows users to enter new inmates, search for inmates, display inmate data, delete inmates, set dorm numbers based on sleep time, and start the sleep inducer.

## Libraries Used
- `bits/stdc++.h`: Standard C++ libraries
- `conio.h`: For `_kbhit()` function
- `ctime`: For time manipulation functions
- `windows.h`: For `system()` function and `Sleep()` function
- `mmsystem.h`: For playing sound (multimedia system)

## Class `Inmates`
This class represents each inmate and contains the following attributes and methods:

### Attributes
- `name`: Name of the inmate
- `ID`: ID of the inmate
- `dorm`: Dormitory number of the inmate

### Methods
- `setname(string name)`: Set the name attribute
- `setID(string ID)`: Set the ID attribute
- `setdorm(int dorm)`: Set the dorm attribute
- `getname()`: Return the name attribute
- `getID()`: Return the ID attribute
- `getdorm()`: Return the dorm attribute

## Functions
1. `ifexist(ID)`: Check if the inmate ID exists in the file specified by `Filename`.
2. `insert(i)`: Insert new inmate data into the file.
3. `search()`: Search for an inmate by ID and display their details.
4. `show()`: Display all inmates' data in a tabular format.
5. `delete_inmate()`: Delete an inmate from the file.
6. `set_dorm()`: Set the dormitory number based on the sleep time for a specified day.
7. `inducer()`: Start the sleep inducer, which plays music based on the current time and dormitory.

## Main Function
The `main()` function serves as the entry point of the program and provides a menu-driven interface for interacting with the sleep inducer system.

## Starting the Program
To start the program, call the `main()` function.
