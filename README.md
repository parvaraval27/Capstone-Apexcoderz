# Inmates Management System

## Libraries Used
- iostream
- fstream
- sstream
- string
- vector
- unordered_map
- ctime
- conio.h
- windows.h
- mmsystem.h
- iomanip

## Global Variables
- `filename`: string

## Class Definition: `Inmates`
- **Private Members**:
    - `name` (string)
    - `ID` (string)
    - `dorm` (int)
- **Public Methods**:
    - Constructor: `Inmates()`
    - Setter Methods: `setname(string)`, `setID(string)`, `setdorm(int)`
    - Getter Methods: `getname()`, `getID()`, `getdorm()`

## Function Definitions

### `ifexist(ID: string) -> bool`
- Opens the file specified by `Filename` in read mode.
- Iterates through each line in the file:
    - Checks if the `ID` exists in the line.
    - If found, returns true.
- If not found, returns false.

### `insert(Inmates i)`
- Initializes variables: `close = false`, `filex = true`
- While not `close`:
    - Clears screen
    - Prompts user to enter input file name if `filex` is true
    - Prompts user to enter inmate's ID
    - If the ID already exists:
        - Prints error message and waits for 2 seconds
    - Else:
        - Prompts user to enter inmate's name
        - Opens file specified by `Filename` in append mode
        - If file cannot be opened:
            - Prints error message and returns
        - Else:
            - Prompts user to enter sleep time for 10 days
            - Calculates average sleep time
            - Determines dorm number based on average sleep time
            - Writes inmate's data to the file
            - Closes the file
            - Prints success message
    - Prompts user for further actions (add more data, change file, close)

### `search(Inmates i)`
- Clears screen
- Gets current time
- Prompts user to enter inmate's ID
- Opens file specified by `Filename` in read mode
- If file cannot be opened:
    - Prints error message and returns
- Else:
    - Initializes an unordered_map to store inmate data
    - Iterates through each line in the file:
        - Parses the line and extracts dorm, ID, name, and sleep time data
        - Stores inmate's data in the unordered_map
    - Closes the file
    - Searches for the given ID in the unordered_map
    - If ID is found:
        - Prints inmate's details and waits for Enter key press
    - Else:
        - Prints error message

### `show()`
- Opens file specified by `Filename` in read mode
- If file cannot be opened:
    - Prints error message and returns
- Else:
    - Gets current day
    - Prints header for inmate details
    - Iterates through each line in the file:
        - Parses the line and extracts dorm, ID, name, and sleep time data
        - Prints inmate's details
    - Waits for Enter key press

### `delete_inmate()`
- Initializes `close = false`
- While not `close`:
    - Clears screen
    - Prompts user to enter input file name
    - Prompts user to enter inmate's ID to delete
    - Opens file specified by `Filename` in read mode
    - Initializes `found = false`
    - Initializes a vector to store lines of the file
    - Iterates through each line in the file:
        - Checks if the inmate's ID exists in the line
        - If found, marks found as true, else adds the line to the vector
    - Closes the file
    - Opens file specified by `Filename` in write mode
    - Writes lines from the vector to the file
    - Closes the file
    - If inmate is found:
        - Prints success message
    - Else:
        - Prints error message and prompts user for further actions

### `set_dorm()`
- Clears screen
- Prompts user to enter input file name
- Prompts user to enter day
- Opens file specified by `Filename` in read mode
- Initializes an array with day names
- Resets dorm numbers based on day and sleep time
- Closes the file
- Prints wait message and waits for 3 seconds

### `inducer()`
- Prompts user to enter input file name
- Prints message to exit
- While no key is pressed:
    - Gets current time
    - Determines dorm to induce sleep based on time
    - Prints dorm number and Earpod IDs of inmates in that dorm
    - Plays corresponding music
    - Prints current time and refresh every second

### `main()`
- Initializes object of `Inmates` class
- Initializes `exit = false`
- While not `exit`:
    - Clears screen
    - Prints menu options
    - Prompts user for choice
    - Based on choice, call respective functions or exit program
