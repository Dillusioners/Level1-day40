'''
Author - Debag101
Purpose - Removing duplicates from a list of integers
Date - 01 06 2023
'''

# Getting the integers input and returning the list
def get_integers():
   try :
       lst = list(map(int, input("Enter the numbers in one line => ").split())) 
   except ValueError:
       print("Please enter integers only !")

   return lst

# Removes duplicate integers
def filter_duplicate(dup_list):
    filtered_list = []
    for i in dup_list:
        # Checks if new list already contains i 
        if i not in filtered_list:
            filtered_list.append(i)
    return filtered_list # Returns the list


integers = get_integers() # Getting the list
print("List with duplicates removed => ", filter_duplicate(integers)) # Printing fresh list
