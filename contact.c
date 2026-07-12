#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    Contact temp;
    printf("1.Sort by Name\n 2.Sort by Phone Number\n 3.Sort by Email\n");
    int sortChoice;
    printf("Enter your choice to sort: ");
    scanf("%d", &sortChoice);
    switch(sortChoice){
        case 1:
            printf("Sorting by Name...\n");
            for (int i = 0; i < addressBook->contactCount; i++){
                for (int j = 0; j < addressBook->contactCount - i -1; j++){
                    if (strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) > 0){
                        temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = temp;
                    }
                }
        }
            break;
        case 2:
            printf("Sorting by Phone Number...\n");
            for (int i = 0; i < addressBook->contactCount; i++){
                for (int j = 0; j < addressBook->contactCount - i -1; j++){
                    if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone) > 0){
                        temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = temp;
                    }
                }
            }
            break;
        case 3:
            printf("Sorting by Email...\n");
            for (int i = 0; i < addressBook->contactCount; i++){
                for (int j = 0; j < addressBook->contactCount - i -1; j++){
                    if (strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email) > 0){
                        temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = temp;
                    }
                }
                
            }
            break;
        default:
            printf("Invalid choice. Listing contacts without sorting.\n");
            break;   
        
    
    }
    printf("============================================================================\n");
    printf("%-40s\n", "ADDRESS BOOK");
    printf("============================================================================\n");
    printf("%-5s %-25s %-15s %-35s\n", "No.", "Name", "Phone", "Email");
    printf("============================================================================\n");
    for (int i = 0; i< addressBook->contactCount; i++) {
        printf("%-5d %-25s %-15s %-35s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    printf("============================================================================\n");
    printf("Total contacts : %d\n", addressBook->contactCount);
    printf("============================================================================\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
  
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    int add_count, ret;
    char name[50], phone[20], email[50];
    printf("How many contacts to add ? : ");
    scanf("%d", &add_count);
    for (int i = 0; i < add_count; i++){
        
        do{
        printf("Enter the name : ");
        scanf(" %49[^\n]", name);
        ret = validateName(name);
        }while(!ret);
        strcpy(addressBook->contacts[addressBook->contactCount].name,name);
        
        do{
            printf("Enter the phone : ");
            scanf("%19s", phone);
            ret = validatePhone(phone, addressBook);
        }while(!ret);
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
        
        do{
            printf("Enter the email : ");
            scanf(" %[^\n]", email);
            ret = validateEmail(email, addressBook);
        }while(!ret);
        strcpy(addressBook->contacts[addressBook->contactCount].email, email);
        addressBook->contactCount++;
    }

    printf("Contact added successfully!");
    
}

int searchContact(AddressBook *addressBook) 
{
    int search_choice;
    printf("Select the field you want to search by :");
    printf("1. Name\n2. Phone\n3. Email\n");
    scanf("%d", &search_choice);
    switch(search_choice){
        case 1:
            char name[50];
            printf("Enter the name : ");
            scanf(" %[^\n]", name);
            printf("Search results for name '%s':\n", name);
            for (int i = 0; i < addressBook->contactCount; i++){
                if(strcasecmp(addressBook->contacts[i].name, name) == 0){
                    printf("Name: %s, Phone: %s, Email: %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;
                }
            }
            
            break;
        case 2:
            char phone[20];
            printf("Enter the phone number : ");
            scanf("%19s", phone);
            printf("Search results for phone '%s':\n", phone);
            for (int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].phone, phone) == 0){
                    printf("Name: %s, Phone: %s, Email: %s\n", 
                            addressBook->contacts[i].name, 
                            addressBook->contacts[i].phone, 
                            addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        case 3:
            char email[50];
            printf("Enter the email : ");
            scanf(" %[^\n]", email);
            printf("Search results for email %s\n", email);
            for (int i = 0; i < addressBook->contactCount; i++){
                if(strcasecmp(addressBook->contacts[i].email, email) == 0){
                    printf("Name: %s, Phone: %s, Email: %s\n", 
                        addressBook->contacts[i].name, 
                        addressBook->contacts[i].phone, 
                        addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        default:
            printf("Invalid selection");
            return -1;
            break;
    }
    printf("No contact found.\n");
    return -1; // Return -1 if no contact is found
}

void editContact(AddressBook *addressBook)
{   
    int edit_choice, validation_result;
    char name[50], phone[20], email[50];
    int search_ret = searchContact(addressBook);
    printf("Enter the field you want to edit :\n 1. Name\n 2. Phone\n 3. Email \n4.More than one field\n");
    scanf("%d", &edit_choice);
    switch(edit_choice){
        case 1:
            do{
            printf("Enter the name : ");
            scanf(" %49[^\n]", name);
            validation_result = validateName(name);
            }while(!validation_result);
            strcpy(addressBook->contacts[search_ret].name,name);
            break;
        case 2:
            do{
            printf("Enter the phone : ");
            scanf(" %[^\n]", phone);
            validation_result = validatePhone(phone, addressBook);
            }while(!validation_result);
            strcpy(addressBook->contacts[search_ret].phone,phone);
            break;
        case 3:
            do{
            printf("Enter the email : ");
            scanf(" %[^\n]", email);
            validation_result = validateEmail(email, addressBook);
            }while(!validation_result);
            strcpy(addressBook->contacts[search_ret].email, email);
            break;
        case 4:
            printf("Enter the new details :\n");

            do{
            printf("Enter the name : ");
            scanf(" %49[^\n]", name);
            validation_result = validateName(name);
            }while(!validation_result);
            strcpy(addressBook->contacts[search_ret].name,name);
        
            do{
            printf("Enter the phone : ");
            scanf(" %[^\n]", phone);
            validation_result = validatePhone(phone, addressBook);
            }while(!validation_result);
            strcpy(addressBook->contacts[search_ret].phone,phone);
        
            do{
            printf("Enter the email : ");
            scanf(" %[^\n]", email);
            validation_result = validateEmail(email, addressBook);
            }while(!validation_result);
            strcpy(addressBook->contacts[search_ret].email, email);
            printf("Contact updated successfully!");
            break;

        default:
            printf("Contact not found! Enter the correct existing detail to edit the contact.");
            break;
    }
    
    return;
}

void deleteContact(AddressBook *addressBook)
{
    printf("Contact Deletion:\n");
    int ret = searchContact(addressBook);
        if(ret != -1){
            for (int j = ret; j < addressBook->contactCount - 1; j++){
                addressBook->contacts[j] = addressBook->contacts[j+1];
            }
            addressBook->contactCount--;
            printf("Contact deleted successfully!");
            return;
        }

    printf("Contact not found! Enter the correct existing name to delete the contact.");
   
}

int validateName(const char name[]){
    int space_count = 0;
    if (strlen(name) == 0) {
        printf("The name should be between 1 and 50 characters!\n");
        return 0;
    }
    else{
        for (int i = 0; name[i] != '\0'; i++) {
            if(space_count > 1){
                printf("The name should not have more than one space!\n");
                return 0;
            }
            else if (isalpha(name[i]) != 0 || name[i] == ' ') {
                if (name[i] == ' ') space_count++;
                continue;
            }
            else {
                printf("The name should only contain alphabets and spaces!\n");
                return 0;
            }
        }
    }
    return 1;
}

int validatePhone(const char *phone, AddressBook *addressBook){

    if(*phone < '6'){
        printf("The phone number should start with 6, 7, 8 or 9!\n");
        return 0;
    }
    if(strlen(phone) != 10){
        printf("The phone number should be exactly 10 digits!\n");
        return 0;
    }

    if(checkPattern(phone)){
        printf("The phone number has consecutive or sequential digits!\n");
        return 0;
    }
    //loop for checking uniqueness
    for (int i = 0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[addressBook->contactCount].phone, phone) == 0){
            printf("Phone number already exists!\nPlease enter new number\n");
            return 0;
        }
    }

    //loop for digit validation
    for (int i = 0; phone[i] != '\0'; i++){
        if(phone[i] >= '0' && phone[i] <= '9'){
            continue;
        }
        else{
            printf("Enter numbers from 0 - 9!\n");
            return 0;
        }
    }
    
    return 1;
}

int validateEmail(char *email, AddressBook *addressBook){
    int at_count = 0;
    
    //Loop to check for uniqness
    for (int i = 0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[addressBook->contactCount].email, email) == 0){
            printf("Duplicate email id found!\nPlease enter a new email id\n");
            return 0;
        }
    }

    //loop for character validation
    for (int i = 0; email[i] != '\0'; i++){
        if(email[i] == ' '){
            printf("Email address should have :\nNo spaces\nOnly one @\nA valid domain name\n");
            return 0;
        }
        else if(email[i] == '@'){
            if(at_count != 0){
                printf("Email address should have :\nNo spaces\nOnly one @\nA valid domain name\n");
                return 0;
            }
            at_count += 1;
        }    
        else if(email[i] >= 'A' && email[i] <= 'Z'){
            email[i] = tolower(email[i]);
        }
    
    }

    return 1;
}

int checkPattern(const char *phone){
    int consecutive_count = 0, asc_sequential_count = 0, desc_sequential_count = 0;
    for (int i = 0; phone[i] != '\0'; i++){
        if(phone[i + 1] == phone[i]){   // To check for consecutive numbers
            consecutive_count++;
        }
        else{
            consecutive_count = 0;
        }

        if(phone [i] == phone[i] + 1){   // To check for ascending sequential numbers
            asc_sequential_count++;
        }
        else{
            asc_sequential_count = 0;

        }  
        if(phone [i] == phone[i] - 1){   // To check for descending sequential numbers
            desc_sequential_count++;
        }
        else{
            desc_sequential_count = 0;

        }         
    }
    if(consecutive_count >= 5 || asc_sequential_count >= 4 || desc_sequential_count >= 4){
        return 1;
    }
    return 0;
}
