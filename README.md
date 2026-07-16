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
- File Storage

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

## Technologies Used

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
- String Handling
- Bubble sort
- File handling
- Modular Programming
- Header files
- Git & GitHub

## compile

```bash
gcc *.c -Wall -Wextra
```

## Run

```bash
./a.out
```
## Validation

- Name
  - Alphabets only
  - One space allowed
  - Maximum 49 characters
- Phone number
  - 10 digits
  - From 0 - 9
  - No duplicates
  - Invalid patterns rejected
- Email
    - No space
    - Uppercase entries are converted to lowercase
    - Exactly one '@'
    - Valid domain name
    - No duplicates

## Special features

- Store contacts permanently using files ✅
- Case-insensitive search ✅
- Duplicate contact detection ✅
- Better input validation ✅

## Future Improvements

- Multiple contact search results
- Partial name search
- Better UI
- Dynamic memory allocation

## Author

Dasmini D ❤️

GitHub : https://github.com/Dasmini