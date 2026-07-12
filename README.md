# 📒 Address Book in C

A simple Address Book application developed in C.

## Features

- Create Contact
  - Validates contacts before saving!
  - If validation fails asks user to re-enter the respective detail.
- Search Contact
 - Search and displays the contact based on the detail user enters.
 - Search is case insensitive
- Edit Contact
  - Edits the details of the selected contact based on the validation rules _(rules detailed below)_
- List Contacts
  - Displays the contacts in a tabular/columnar formate
  - Displays the total number of contact at the end
- Delete Contact
  - Deletes the contact based on the entered detail
- Save contacts to file
  - Saves the contact to the file so it becomes permenant 😃
- Validation of details
  - For Names : 
    - Checks is there is not more than one space
    - Checks if the characters are within 'A' - 'Z' and 'a' - 'z'
  - For Phone numbers :
    - Should have only 10 digits
    - should be from 0 - 9
    - No duplicate entries should be found in the existing data
    - Should not start with numbers 0 - 5
    - Should not have more than 5 and 4 sequential and concequtive numbers respectively. Eg. 8888856786, 1234564326.
  - For Emails :
    - No space should be entered
    - Uppercase entries are converted to lowercase
    - Only one '@' should be entered
    - No duplicate entries should be found in the existing data



---

## 📂 Project Structure

```
Address-Book/
│
├── main.c
├── contact.c
├── contact.h
├── populate.c
├── populate.h
├── file.c
├── file.h
├── contacts.csv
└── README.md
```

---

## Technologies

- C
- Git
- GitHub
- VS Code
- WSL

## Concepts Practiced

This project helped me practice:

- Arrays
- Structures
- Pointers
- Strings
- Bubble sort
- File handling
- Modular Programming
- Header files
- Git & GitHub

## compile

```bash
gcc *.c
```

## Run

```bash
./a.out
```
## Special features

- Store contacts permanently using files ✅
- Case-insensitive search ✅
- Duplicate contact detection ✅
- Better input validation ✅
- Dynamic memory allocation _Coming soon..._

## Author

Dasmini D ❤️

GitHub : https://github.com/Dasmini