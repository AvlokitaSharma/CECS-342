def sort(numeric_array, name_age_array):
    print("By Numeric: \n",sorted(numeric_array),"\n")
    print("By name: \n",sorted(name_age_array),"\n") 
    
    
    sorted_array = sorted(name_age_array,reverse=True)
    sort_age = sorted(sorted_array,key = lambda x: x[1]) #sorted out the sorted_array with respect to second element of every sublist which is age
    print("By age: \n",sort_age[::-1],"\n")
    

numeric_array = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
name_age = [['Hal', 20], ['Susann', 31], ['Dwight', 19], ['Kassandra', 21], ['Lawrence', 25], ['Cindy', 22], ['Cory', 27], ['Mac', 19], ['Romana', 27], ['Doretha', 32], ['Danna', 20], ['Zara', 23], ['Rosalyn', 26], ['Risa', 24], ['Benny', 28], ['Juan', 33], ['Natalie', 25]]

print(sort(numeric_array,name_age))