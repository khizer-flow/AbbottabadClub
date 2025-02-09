#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct UserInfo
{
    int uniqueID;
    char name[32];
    int age;
    char gender[10];
    char address[100];
    char phoneNumber[15];
    char email[50];
    char package[50];
    char subscription[50];
    char subscriptionEndDate[15];
    char membershipStartDate[15];
    char emergencyContact[50];
    char medicalConditions[100];
    char preferences[100];
};



struct Package
{
    char name[50];
    double price;
    char access[100];
    char description[200];
    char additionalBenefits[200];
};



struct Subscription
{
    char type[50];
    double price;
    double discount;
    char description[200];
    char termsConditions[200];
};



struct Employee
{
    char name[32];
    char position[50];
    char phoneNumber[15];
    char email[50];
    char shift[20];
    char jobDescription[200];
};



struct Cafe
{
    char name[50];
    char hours[20];
    char managerContact[50];
    char menuHighlights[200];
};



struct Facility
{
    char name[50];
    char hours[20];
    char specialFeatures[200];
    char rules[200];
};



bool emailValidation(char email[])
{
    int at = -1, dot = -1;
    for (int i = 0; email[i]; i++)
    {
        if (email[i] == '@')
            at = i;
        if (email[i] == '.')
            dot = i;
    }
    if (at == -1 || dot == -1 || at > dot)
    {
        printf("Invalid email format. Please try again.\n");
        return false;
    }
    return true;
}



void addUser(struct UserInfo users[], int *totalUsers, struct Package packages[], int totalPackages, struct Subscription subscriptions[], int totalSubscriptions)
{
    if (*totalUsers >= 100)
    {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }

    struct UserInfo newUser;
    newUser.uniqueID = *totalUsers + 1;

    printf("Enter name: ");
    
    scanf(" %[^\n]%*c", newUser.name);
    printf("Enter age: ");
    
    scanf("%d", &newUser.age);
    
    printf("Enter gender: ");
    
    scanf(" %[^\n]%*c", newUser.gender);
    
    printf("Enter address: ");
    
    scanf(" %[^\n]%*c", newUser.address);
    
    printf("Enter phone number: ");
    
    scanf(" %[^\n]%*c", newUser.phoneNumber);

   
   
   
    do
    {
        printf("Enter email: ");
        scanf(" %[^\n]%*c", newUser.email);
    } while (!emailValidation(newUser.email));

    printf("Enter package (available options: ");
    for (int i = 0; i < totalPackages; i++)
    {
        printf("%s ", packages[i].name);
    }
    printf("): ");
    scanf(" %[^\n]%*c", newUser.package);

    printf("Enter subscription (available options: ");
    for (int i = 0; i < totalSubscriptions; i++)
    {
        printf("%s ", subscriptions[i].type);
    }
    printf("): ");
    scanf(" %[^\n]%*c", newUser.subscription);

    printf("Enter subscription end date (DD/MM/YYYY): ");
    scanf(" %[^\n]%*c", newUser.subscriptionEndDate);
    printf("Enter membership start date (DD/MM/YYYY): ");
    scanf(" %[^\n]%*c", newUser.membershipStartDate);
    
    printf("Enter emergency contact: ");
    
    scanf(" %[^\n]%*c", newUser.emergencyContact);
    printf("Enter medical conditions: ");
    
    scanf(" %[^\n]%*c", newUser.medicalConditions);
    
    printf("Enter preferences: ");
    
    scanf(" %[^\n]%*c", newUser.preferences);

    users[*totalUsers] = newUser;
    (*totalUsers)++;

    printf("\n\n** User added successfully! **\n\n");

    FILE *fuser;

    fuser = fopen("user.txt", "w");

    fprintf(fuser, "%d\n", *totalUsers);

    for (int i = 0; i < *totalUsers; i++)
    {
        fprintf(fuser, "%d;%s;%d;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n", users[i].uniqueID, users[i].name, users[i].age, users[i].gender, users[i].address, users[i].phoneNumber, users[i].email, users[i].package, users[i].subscription, users[i].subscriptionEndDate, users[i].membershipStartDate, users[i].emergencyContact, users[i].medicalConditions, users[i].preferences);
    }

    fclose(fuser);
}

void displayTotalRegistered(int totalUsers)
{
    printf("\nTotal Registered Users: %d\n\n", totalUsers);
}

void displayAllUsers(struct UserInfo users[], int totalUsers)
{
    printf("\n\n** Displaying All Users **\n\n");
    for (int i = 0; i < totalUsers; i++)
    {
        printf("User %d:\n", i + 1);
        
        printf("Unique ID: %d\n", users[i].uniqueID);
        
        printf("Name: %s\n", users[i].name);
        
        printf("Age: %d\n", users[i].age);
        
        printf("Gender: %s\n", users[i].gender);
        
        printf("Address: %s\n", users[i].address);
        
        printf("Phone Number: %s\n", users[i].phoneNumber);
        
        printf("Email: %s\n", users[i].email);
        
        printf("Package: %s\n", users[i].package);
        
        printf("Subscription: %s\n", users[i].subscription);
        
        printf("Subscription End Date: %s\n", users[i].subscriptionEndDate);
        
        printf("Membership Start Date: %s\n", users[i].membershipStartDate);
        
        printf("Emergency Contact: %s\n", users[i].emergencyContact);
        
        printf("Medical Conditions: %s\n", users[i].medicalConditions);
        
        printf("Preferences: %s\n\n", users[i].preferences);
    }
}





void displayAllCafes(struct Cafe cafes[], int totalCafes)
{
    printf("\n\n** Displaying All Users **\n\n");
    for (int i = 0; i < totalCafes; i++)
    {
        printf("Name: %s\n", cafes[i].name);
        
        printf("Hours of Cafe: s\n", cafes[i].hours);
        
        printf("Managers Contact: %s\n", cafes[i].managerContact);
        
        printf("Menu Highlights: %s\n", cafes[i].menuHighlights);
        
    }
}




void displayAllEmployee(struct Employee employees[], int totalEmployees)
{
    printf("\n\n** Displaying All Employees: **\n\n");
    for (int i = 0; i < totalEmployees; i++)
    {
        printf("Employee Name %s:\n", employees[i].name);
        
        printf("Employee Position %s:\n", employees[i].position);
        
        printf("Employee Phone Number %s:\n", employees[i].phoneNumber);
        
        printf("Employee Email %s:\n", employees[i].email);
        
        printf("Employee shift %s:\n", employees[i].shift);
        
        printf("Job Description : %s\n", employees[i].jobDescription);
        
        
        
    }
}






void updateUser(struct UserInfo users[], int totalUsers, struct Package packages[], int totalPackages, struct Subscription subscriptions[], int totalSubscriptions)
{
    int id;
    printf("Enter the unique ID of the user you want to update: ");
    scanf("%d", &id);

    for (int i = 0; i < totalUsers; i++)
    {
        if (users[i].uniqueID == id)
        {
            printf("Updating user with unique ID %d:\n", id);

            printf("Enter new name: ");
            scanf(" %[^\n]%*c", users[i].name);
            
            printf("Enter new age: ");
            scanf("%d", &users[i].age);
            
            printf("Enter new gender: ");
            scanf(" %[^\n]%*c", users[i].gender);
            
            printf("Enter new address: ");
            scanf(" %[^\n]%*c", users[i].address);
            
            printf("Enter new phone number: ");
            scanf(" %[^\n]%*c", users[i].phoneNumber);

           
           
            do
            {
                printf("Enter new email: ");
                scanf(" %[^\n]%*c", users[i].email);
            } while (!emailValidation(users[i].email));

            printf("Enter new package (available options: ");
            for (int i = 0; i < totalPackages; i++)
            {
                printf("%s ", packages[i].name);
            }
            printf("): ");
            scanf(" %[^\n]%*c", users[i].package);

            printf("Enter new subscription (available options: ");
            for (int i = 0; i < totalSubscriptions; i++)
            {
                printf("%s ", subscriptions[i].type);
            }
            printf("): ");
            scanf(" %[^\n]%*c", users[i].subscription);

            printf("Enter new subscription end date (DD/MM/YYYY): ");
            scanf(" %[^\n]%*c", users[i].subscriptionEndDate);
            printf("Enter new membership start date (DD/MM/YYYY): ");
            scanf(" %[^\n]%*c", users[i].membershipStartDate);
            printf("Enter new emergency contact: ");
            scanf(" %[^\n]%*c", users[i].emergencyContact);
            
            
            printf("Enter new medical conditions: ");
            
            scanf(" %[^\n]%*c", users[i].medicalConditions);
            printf("Enter new preferences: ");
            
            scanf(" %[^\n]%*c", users[i].preferences);

            printf("\n\n** User updated successfully! **\n\n");
            return;
        }
    }

    printf("User with unique ID %d not found.\n", id);
}

void deleteUser(struct UserInfo users[], int *totalUsers)
{
    int id;
    printf("Enter the unique ID of the user you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalUsers; i++)
    {
        if (users[i].uniqueID == id)
        {
            for (int j = i; j < *totalUsers - 1; j++)
            {
                users[j] = users[j + 1];
            }
            (*totalUsers)--;
            printf("\n\n** User deleted successfully! **\n\n");
            return;
        }
    }

    printf("User with unique ID %d not found.\n", id);
}

void updatePackage(struct Package packages[], int totalPackages)
{
    int index;
    printf("Enter the package number you want to update (1 to %d): ", totalPackages);
    scanf("%d", &index);
    index--;



    if (index < 0 || index >= totalPackages)
    {
        printf("Invalid package number.\n");
        return;
    }

    printf("Enter new package name: ");
    scanf(" %[^\n]%*c", packages[index].name);
    
    printf("Enter new price: ");
    
    scanf("%lf", &packages[index].price);
    printf("Enter new access details: ");
    
    
    scanf(" %[^\n]%*c", packages[index].access);
    printf("Enter new description: ");
    
    scanf(" %[^\n]%*c", packages[index].description);
    
    printf("Enter new additional benefits: ");
    
    scanf(" %[^\n]%*c", packages[index].additionalBenefits);

    printf("\n\n** Package updated successfully! **\n\n");
}

void updateSubscription(struct Subscription subscriptions[], int totalSubscriptions)
{
    int index;
    printf("Enter the subscription number you want to update (1 to %d): ", totalSubscriptions);
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= totalSubscriptions)
    {
        printf("Invalid subscription number.\n");
        return;
    }

    printf("Enter new subscription type: ");
    
    scanf(" %[^\n]%*c", subscriptions[index].type);
    
    printf("Enter new price: ");
    scanf("%lf", &subscriptions[index].price);
    printf("Enter new discount: ");
    
    
    scanf("%lf", &subscriptions[index].discount);
    
    printf("Enter new description: ");
    
    scanf(" %[^\n]%*c", subscriptions[index].description);
    
    printf("Enter new terms and conditions: ");
    scanf(" %[^\n]%*c", subscriptions[index].termsConditions);

    printf("\n\n** Subscription updated successfully! **\n\n");
}

void updateEmployee(struct Employee employees[], int totalEmployees)
{

    FILE *femployee1;

    femployee1 = fopen("employee.txt", "r");

    for (int i = 0; i < 2; i++)
    {
        fscanf(femployee1, "%32[^;];%50[^;];%15[^;];%50[^;];%20[^;];%200[^\n]\n", employees[i].name, employees[i].position, employees[i].phoneNumber, employees[i].email, employees[i].shift, employees[i].jobDescription);
    }

    fclose(femployee1);

    int index;
    
    printf("Enter the employee number you want to update (1 to %d): ", totalEmployees);
    scanf("%d", &index);
    
    index--;

    if (index < 0 || index >= totalEmployees)
    {
        printf("Invalid employee number.\n");
        return;
    }

    printf("Enter new employee name: ");
    
    scanf(" %[^\n]%*c", employees[index].name);
    
    
    printf("Enter new position: ");
    scanf(" %[^\n]%*c", employees[index].position);
    
    printf("Enter new phone number: ");
    scanf(" %[^\n]%*c", employees[index].phoneNumber);

    
    
    
    do
    {
        printf("Enter new email: ");
        scanf(" %[^\n]%*c", employees[index].email);
    } while (!emailValidation(employees[index].email));

    printf("Enter new shift: ");
    
    scanf(" %[^\n]%*c", employees[index].shift);
    
    
    printf("Enter new job description: ");
    
    scanf(" %[^\n]%*c", employees[index].jobDescription);

    printf("\n\n** Employee updated successfully! **\n\n");

    FILE *femployee;

    femployee = fopen("employee.txt", "w");

    for (int i = 0; i < 2; i++)
    {
        fprintf(femployee, "%s;%s;%s;%s;%s;%s\n", employees[i].name, employees[i].position, employees[i].phoneNumber, employees[i].email, employees[i].shift, employees[i].jobDescription);
    }

    fclose(femployee);
}

void updateCafe(struct Cafe cafes[], int totalCafes)
{
    int index;
    
    printf("Enter the cafe number you want to update (1 to %d): ", totalCafes);
    
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= totalCafes)
    {
        printf("Invalid cafe number.\n");
        return;
    }

    printf("Enter new cafe name: ");
    
    scanf(" %[^\n]%*c", cafes[index].name);
    
    printf("Enter new hours: ");
    
    scanf(" %[^\n]%*c", cafes[index].hours);
    
    printf("Enter new manager contact: ");
    
    scanf(" %[^\n]%*c", cafes[index].managerContact);
    
    printf("Enter new menu highlights: ");
    
    
    scanf(" %[^\n]%*c", cafes[index].menuHighlights);

    printf("\n\n** Cafe updated successfully! **\n\n");
}

void updateFacility(struct Facility facilities[], int totalFacilities)
{
    int index;
    
    printf("Enter the facility number you want to update (1 to %d): ", totalFacilities);
    scanf("%d", &index);
    
    index--;

    if (index < 0 || index >= totalFacilities)
    {
        printf("Invalid facility number.\n");
        return;
    }

    printf("Enter new facility name: ");
    
    
    scanf(" %[^\n]%*c", facilities[index].name);
    
    printf("Enter new hours: ");
    
    scanf(" %[^\n]%*c", facilities[index].hours);
    
    printf("Enter new special features: ");
    
    scanf(" %[^\n]%*c", facilities[index].specialFeatures);
    printf("Enter new rules: ");
    
    scanf(" %[^\n]%*c", facilities[index].rules);

    printf("\n\n** Facility updated successfully! **\n\n");
}

void displayPackages(struct Package packages[], int totalPackages)
{
    printf("\n\n** Displaying Available Packages **\n\n");
    for (int i = 0; i < totalPackages; i++)
    {
        printf("Package %d:\n", i + 1);
        
        printf("Name: %s\n", packages[i].name);
        
        printf("Price: %.2f\n", packages[i].price);
        
        printf("Access: %s\n", packages[i].access);
        
        printf("Description: %s\n", packages[i].description);
        
        printf("Additional Benefits: %s\n\n", packages[i].additionalBenefits);
    }
}

void displaySubscriptions(struct Subscription subscriptions[], int totalSubscriptions)
{
    printf("\n\n** Displaying Available Subscriptions **\n\n");
    for (int i = 0; i < totalSubscriptions; i++)
    {
        printf("Subscription %d:\n", i + 1);
        
        printf("Type: %s\n", subscriptions[i].type);
        
        printf("Price: %.2f\n", subscriptions[i].price);
        
        printf("Discount: %.2f%%\n", subscriptions[i].discount);
        
        printf("Description: %s\n", subscriptions[i].description);
        
        printf("Terms and Conditions: %s\n\n", subscriptions[i].termsConditions);
    }
}

void displayTimings(struct Cafe cafes[], int totalCafes, struct Facility facilities[], int totalFacilities)
{
    printf("\n\n** Displaying Timings **\n\n");
    
    

    printf("Cafes:\n");
    for (int i = 0; i < totalCafes; i++)
    {
        printf("Cafe %d:\n", i + 1);
        
        printf("Name: %s\n", cafes[i].name);
        
        printf("Hours: %s\n", cafes[i].hours);
        
        printf("Manager Contact: %s\n", cafes[i].managerContact);
        
        printf("Menu Highlights: %s\n\n", cafes[i].menuHighlights);
        
    }

    printf("Facilities:\n");
    for (int i = 0; i < totalFacilities; i++)
    {
        printf("Facility %d:\n", i + 1);
        printf("Name: %s\n", facilities[i].name);
        printf("Hours: %s\n", facilities[i].hours);
        printf("Special Features: %s\n", facilities[i].specialFeatures);
        printf("Rules: %s\n\n", facilities[i].rules);
    }
}

void contactUs()
{
    printf("\n\n** Contact Us **\n\n");
    printf("Phone: 0992-123456\n");
    printf("Email: info@abbottabadclub.com\n");
    printf("Address: Abbottabad Club, Main Street, Abbottabad\n\n");
}

void searchUser(struct UserInfo users[], int totalUsers)
{
    int choice;
    printf("Search by:\n");
    
    
    printf("1. Unique ID\n");
    printf("2. Name\n");
    
    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int id;
        printf("Enter unique ID: ");
        scanf("%d", &id);
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].uniqueID == id)
            {
                printf("\nUser Found:\n");
                
                printf("Unique ID: %d\n", users[i].uniqueID);
                printf("Name: %s\n", users[i].name);
                
                printf("Age: %d\n", users[i].age);
                printf("Gender: %s\n", users[i].gender);
                
                printf("Address: %s\n", users[i].address);
                printf("Phone Number: %s\n", users[i].phoneNumber);
                
                printf("Email: %s\n", users[i].email);
                printf("Package: %s\n", users[i].package);
                printf("Subscription: %s\n", users[i].subscription);
                
                printf("Subscription End Date: %s\n", users[i].subscriptionEndDate);
                printf("Membership Start Date: %s\n", users[i].membershipStartDate);
                printf("Emergency Contact: %s\n", users[i].emergencyContact);
                
                printf("Medical Conditions: %s\n", users[i].medicalConditions);
                
                
                printf("Preferences: %s\n", users[i].preferences);
                return;
            }
        }
    }
    else if (choice == 2)
    {
        char name[32];
        printf("Enter name: ");
        scanf(" %[^\n]%*c", name);
        for (int i = 0; i < totalUsers; i++)
        {
            if (strcasecmp(users[i].name, name) == 0)
            {
                printf("\nUser Found:\n");
                
                
                printf("Unique ID: %d\n", users[i].uniqueID);
                
                printf("Name: %s\n", users[i].name);
                
                printf("Age: %d\n", users[i].age);
                
                printf("Gender: %s\n", users[i].gender);
                
                printf("Address: %s\n", users[i].address);
                printf("Phone Number: %s\n", users[i].phoneNumber);
                
                printf("Email: %s\n", users[i].email);
                printf("Package: %s\n", users[i].package);
                
                printf("Subscription: %s\n", users[i].subscription);
                
                printf("Subscription End Date: %s\n", users[i].subscriptionEndDate);
                printf("Membership Start Date: %s\n", users[i].membershipStartDate);
                
                
                printf("Emergency Contact: %s\n", users[i].emergencyContact);
                printf("Medical Conditions: %s\n", users[i].medicalConditions);
                printf("Preferences: %s\n", users[i].preferences);
                return;
            }
        }
    }

    printf("User not found.\n");
}


void generateReport(struct UserInfo users[], int totalUsers) {
    int males = 0, females = 0, vipMembers = 0, premiumMembers = 0, basicMembers = 0;
    
    double totalAmountPaid = 0.0;



    for (int i = 0; i < totalUsers; i++) {
        if (strcasecmp(users[i].gender, "Male") == 0) males++;
                if (strcasecmp(users[i].gender, "m") == 0) males++;
        else if (strcasecmp(users[i].gender, "Female") == 0) females++;
        
        else if (strcasecmp(users[i].gender, "f") == 0) females++;
        



        if (strcasecmp(users[i].package, "VIP") == 0) {
            vipMembers++;
            totalAmountPaid += users[i].subscription[0] * 12; 
        } else if (strcasecmp(users[i].package, "Premium") == 0) {
        	
            premiumMembers++;
            
        } else if (strcasecmp(users[i].package, "Basic") == 0) {
           
		    basicMembers++;
        }
    }

    printf("\n\n** Report **\n\n");
    
    printf("Total Users: %d\n", totalUsers);
    
    
    printf("Male Users: %d\n", males);
    
    printf("Female Users: %d\n", females);
    
    printf("VIP Members: %d\n", vipMembers);
    
    printf("Premium Members: %d\n", premiumMembers);
    
    printf("Basic Members: %d\n", basicMembers);
    
    printf("Total Amount Paid by Members: %.2f\n", totalAmountPaid);
}


void frequentlyAskedQuestions()
{
    printf("\n\n** Frequently Asked Questions **\n\n");
    printf("Q1: What are the operating hours of Abbottabad Club?\n");
    printf("A1: Abbottabad Club operates from 6 AM to 10 PM every day.\n\n");

    printf("Q2: What facilities are available at Abbottabad Club?\n");
    printf("A2: We offer a gym, swimming pool, tennis courts, and a spa.\n\n");

    printf("Q3: How can I contact customer support?\n");
    printf("A3: You can contact us via phone at 0992-123456 or email at info@abbottabadclub.com.\n\n");

    printf("Q4: Are there any membership discounts available?\n");
    printf("A4: Yes, we offer discounts for students, senior citizens, and families. Please check our subscription plans for more details.\n\n");

    printf("Q5: Can I upgrade or downgrade my membership package?\n");
    printf("A5: Yes, you can upgrade or downgrade your membership package at any time by contacting our support team.\n\n");
}



int main()
{
    struct UserInfo users[100];
    
    int totalUsers = 0;

    FILE *fuser1;

    fuser1 = fopen("user.txt", "r");

    fscanf(fuser1, "%d\n", &totalUsers);

    for (int i = 0; i < totalUsers; i++)
    {
    	
        fscanf(fuser1, "%d;%32[^;];%d;%10[^;];%100[^;];%15[^;];%50[^;];%50[^;];%50[^;];%15[^;];%15[^;];%50[^;];%100[^;];%100[^\n]\n", &users[i].uniqueID, users[i].name, &users[i].age, users[i].gender, users[i].address, users[i].phoneNumber, users[i].email, users[i].package, users[i].subscription, users[i].subscriptionEndDate, users[i].membershipStartDate, users[i].emergencyContact, users[i].medicalConditions, users[i].preferences);
    }


    struct Package packages[] = {
        {"Basic", 1000, "Gym, Pool", "Access to gym and pool", "Free towels"},
        
        {"Premium", 2000, "Gym, Pool, Tennis", "Access to all facilities", "Free towels, Personal trainer"},
        
        {"VIP", 3000, "All Access", "All facilities with VIP lounge", "Free towels, Personal trainer, Spa access"}};
    int totalPackages = sizeof(packages) / sizeof(packages[0]);

    struct Subscription subscriptions[] = {
    	
        {"Monthly", 1000, 0, "Monthly subscription", "Cancel anytime"},
        
        {"Quarterly", 2700, 10, "Quarterly subscription", "Cancel anytime"},
        
        {"Yearly", 10000, 20, "Yearly subscription", "Cancel anytime"}};
        
    int totalSubscriptions = sizeof(subscriptions) / sizeof(subscriptions[0]);

    struct Employee employees[] = {
        {"Khizer", "Manager", "0992-111111", "khizer@abbottabadclub.com", "Morning", "Oversees operations"},
        
        {"Ali", "Trainer", "0992-222222", "ali@abbottabadclub.com", "Evening", "Personal training"}};
        
    int totalEmployees = sizeof(employees) / sizeof(employees[0]);

    
    

    struct Cafe cafes[] = {
    	
        {"Main Cafe", "6 AM - 10 PM", "0992-333333", "Coffee, Snacks"},
        
        {"VIP Lounge", "6 AM - 10 PM", "0992-444444", "Exclusive menu"}};
        
    int totalCafes = sizeof(cafes) / sizeof(cafes[0]);

    struct Facility facilities[] = {
        {"Gym", "6 AM - 10 PM", "State-of-the-art equipment", "Wear proper attire"},
        
        {"Pool", "6 AM - 10 PM", "Olympic-sized pool", "Shower before entering"},
        
        {"Tennis Court", "6 AM - 10 PM", "Clay courts", "Wear tennis shoes"}};
    int totalFacilities = sizeof(facilities) / sizeof(facilities[0]);

    int choice;
    while (1)
    {
        printf("\n\nWelcome to Abbottabad Club Management System:\n");
        
        
        printf("Select your Option to Proceed\n\n");
        
        printf("1. Add user\n");
        
        printf("2. Display total registered users\n");
        
        printf("3. Display all users\n");
        
        printf("4. Update user\n");
        
        printf("5. Delete user\n");
        
        printf("6. Display available packages\n");
        
        printf("7. Display available subscriptions\n");
        
        printf("8. Display timings\n");
        
        
        printf("9. Update package\n");
        
        printf("10. Update subscription\n");
        
        printf("11. Update employee\n");
        
        printf("12. Update cafe\n");
        
        printf("13. Update facility\n");
        
        printf("14. Contact us\n");
        
        printf("15. Search user\n");
        
        printf("16. Generate report\n");
        
        printf("17. Frequently asked questions\n");
        
        printf("18. Display Cafe's \n");
        
        
        printf("19. display All Employee\n");
        
        printf("20. Shutdown system\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addUser(users, &totalUsers, packages, totalPackages, subscriptions, totalSubscriptions);
            break;
        case 2:
            displayTotalRegistered(totalUsers);
            break;
        case 3:
            displayAllUsers(users, totalUsers);
            break;
        case 4:
            updateUser(users, totalUsers, packages, totalPackages, subscriptions, totalSubscriptions);
            break;
        case 5:
            deleteUser(users, &totalUsers);
            break;
        case 6:
            displayPackages(packages, totalPackages);
            break;
        case 7:
            displaySubscriptions(subscriptions, totalSubscriptions);
            break;
        case 8:
            displayTimings(cafes, totalCafes, facilities, totalFacilities);
            break;
        case 9:
            updatePackage(packages, totalPackages);
            break;
        case 10:
            updateSubscription(subscriptions, totalSubscriptions);
            break;
        case 11:
            updateEmployee(employees, totalEmployees);
            break;
        case 12:
            updateCafe(cafes, totalCafes);
            break;
        case 13:
            updateFacility(facilities, totalFacilities);
            break;
        case 14:
            contactUs();
            break;
        case 15:
            searchUser(users, totalUsers);
            break;
        case 16:
            generateReport(users, totalUsers);
            break;
        case 17:
            frequentlyAskedQuestions();
            break;
            
        case 18: 
        
        	displayAllCafes(cafes,totalCafes);
        	break;
        	
        	
        case 19:
        	
        	displayAllEmployee(employees, totalEmployees);
		    break;
        case 20:
        	
            printf("\n\n** System Shutdown **\n\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
