#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int add_count;
    printf("How many contacts to add? : ");
    scanf("%d", &add_count);
    for (int i = 0; i < add_count; i++){
        printf("Enter the name : ");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
        printf("Enter the phone : ");
        scanf("%s", addressBook->contacts[addressBook->contactCount].phone);
        printf("Enter the email : ");
        scanf("%s", addressBook->contacts[addressBook->contactCount].email);
        addressBook->contactCount++;
    }

    printf("Contact added successfully!");
    
}

void searchContact(AddressBook *addressBook) 
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
                    return;
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
                    return;
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
                    return;
                }
            }
            break;
        default:
            printf("Invalid selection");
            break;
    }
    
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
