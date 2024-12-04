/*Question 05
You're building an inventory system for a pet shop called "Pets in Heart" that keeps track of different species of animals and their specific supplies (e.g., food, toys, bedding). The shopinventory system uses a 2D dynamic array char** speciesSupplies where:
● Rows are explicitly set for each species (e.g., "Dogs," "Cats," "Parrots"), and each row
corresponds to a different species.
● Columns are dynamically allocated for each species to hold their specific supplies (e.g., "Food," "Leash," "Toys"). Task:

Write a C program that:
1. Initialize the Inventory: Allocate memory for a specified number of species, with each species having its own list of supplies (initially empty). 
2. Add Supplies: For each species, dynamically allocate memory for a list of supplies and allow the user to add supplies for that species. 
3. Update Supplies: Let users update the name of a supply item for a specific species. 
4. Remove Species: Allow users to delete a species and free the associated memory (both for the species and its supplies). 
5. Display Inventory: Show the current supplies for each species in the inventory. */

#include <stdio.h>
#include <stdlib.h>

void initializeInventory(char **speciesSupplies, int numSpecies)
{
    speciesSupplies = (char **)malloc(numSpecies * sizeof(char *));
    for (int i = 0; i < numSpecies; i++)
    {
        speciesSupplies[i] = (char *)malloc(1 * sizeof(char));
    }
}

void addSupplies(char ***speciesSupplies, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        printf("Enter the number of supplies for species %d: ", i + 1);
        int numSupplies;
        scanf("%d", &numSupplies);
        speciesSupplies[i] = (char **)realloc(speciesSupplies[i], numSupplies * sizeof(char*));
        for (int j = 0; j < numSupplies; j++)
        {
            printf("Enter supply %d for species %d: ", j + 1, i + 1);
            scanf("%s", &speciesSupplies[i][j]);
        }
    }
}

void updateSupplies(char **speciesSupplies, int numSpecies)
{
    int speciesIndex, supplyIndex;
    printf("Enter the species index to update supplies: ");
    scanf("%d", &speciesIndex);
    printf("Enter the supply index to update: ");
    scanf("%d", &supplyIndex);
    printf("Enter the new supply name: ");
    scanf("%s", &speciesSupplies[speciesIndex][supplyIndex]);
}

void removeSpecies(char **speciesSupplies, int numSpecies)
{
    int speciesIndex;
    printf("Enter the species index to remove: ");
    scanf("%d", &speciesIndex);
    free(speciesSupplies[speciesIndex]);
    for (int i = speciesIndex; i < numSpecies - 1; i++)
    {
        speciesSupplies[i] = speciesSupplies[i + 1];
    }
    speciesSupplies = (char **)realloc(speciesSupplies, (numSpecies - 1) * sizeof(char *));
}

void displayInventory(char **speciesSupplies, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        printf("Species %d supplies: ", i + 1);
        for (int j = 0; j < sizeof(speciesSupplies[i]); j++)
        {
            printf("%s\n", speciesSupplies[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char **speciesSupplies;
    initializeInventory(speciesSupplies, numSpecies);

    addSupplies(speciesSupplies, numSpecies);
    displayInventory(speciesSupplies, numSpecies);

    updateSupplies(speciesSupplies, numSpecies);
    displayInventory(speciesSupplies, numSpecies);

    removeSpecies(speciesSupplies, numSpecies);
    displayInventory(speciesSupplies, numSpecies);

    return 0;
}
