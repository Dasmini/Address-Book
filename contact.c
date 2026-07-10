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
    printf("%d", addressBook->contactCount);
    printf("1.Sort by Name\n 2.Sort by Phone Number\n 3.Sort by Email\n");
    int sortChoice;
    printf("Enter your choice to sort: ");
    scanf("%d", &sortChoice);
    switch(sortChoice){
        case 1:
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
            for (int i = 0; i < addressBook->contactCount; i++){
                for (int j = 0; j < addressBook->contactCount - i -1; j++){
                    if (addressBook->contacts[j].phone > addressBook->contacts[j+1].phone){
                        temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                        addressBook->contacts[j+1] = temp;
                    }
                }
            }
            break;
        case 3:
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
    for (int i = 0; i< addressBook->contactCount; i++) {
        printf("Contact %d: Name: %s, Phone: %s, Email: %s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    //addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
  
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
    printf("How many contacts to add? : ");
    scanf("%d", &add_count);
    for (int i = 0; i < add_count; i++){
        
        do{
        printf("Enter the name (<50 characters): ");
        scanf(" %49[^\n]", name);
        ret = validateName(name);
        }while(!ret);
        strcpy(addressBook->contacts[addressBook->contactCount].name,name);
        
        do{
            printf("Enter the phone (0-9) : ");
            scanf(" %[^\n]", phone);
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
            for (int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].name, name) == 0){
                    printf("Contact found : Name: %s, Phone: %s, Email: %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        case 2:
            char phone[20];
            printf("Enter the phone number : ");
            scanf(" %[^\n]", phone);
            for (int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].phone, phone) == 0){
                    printf("Contact found : Name: %s, Phone: %s, Email: %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        case 3:
            char email[50];
            printf("Enter the email : ");
            scanf(" %[^\n]", email);
            for (int i = 0; i < addressBook->contactCount; i++){
                if(strcmp(addressBook->contacts[i].email, email) == 0){
                    printf("Contact found : Name: %s, Phone: %s, Email: %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        default:
            printf("Invalid selection");
            return -1;
            break;
    }
    
}

void editContact(AddressBook *addressBook)
{   
    int edit_choice;
    int ret = searchContact(addressBook);
    printf("Enter the field you want to edit :\n 1. Name\n 2. Phone\n 3. Email \n4.More than one field\n");
    scanf("%d", &edit_choice);
    switch(edit_choice){
        case 1:
            printf("Enter the name : ");
            scanf(" %[^\n]", addressBook->contacts[ret].name);
            break;
        case 2:
            printf("Enter the phone : ");  
            scanf("%s", addressBook->contacts[ret].phone);
            break;
        case 3:
            printf("Enter the email : ");
            scanf("%s", addressBook->contacts[ret].email);
            break;
        case 4:
            printf("Enter the new details :\n");
            printf("Enter the name : ");
            scanf(" %[^\n]", addressBook->contacts[ret].name);
            printf("Enter the phone : ");  
            scanf("%s", addressBook->contacts[ret].phone);
            printf("Enter the email : ");
            scanf("%s", addressBook->contacts[ret].email);
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
    if (strlen(name) == 0) {
        printf("The name should be between 1 and 50 characters!\n");
        return 0;
    }
    else{
        for (int i = 0; name[i] != '\0'; i++) {
            if (isalpha(name[i]) != 0 || name[i] == ' ') {
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

    //loop for checking uniqueness
    for (int i = 0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[addressBook->contactCount].phone, phone) == 0){
            printf("Duplicate phone number found!\nPlease enter new number\n");
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
