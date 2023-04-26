import Data.List 
import Data.Ord 
import Data.Function --I got to know about this function from the book
import Control.Arrow

numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]  
data People = People { name::String, age::Int } 

            
--I read the book learn youa haskell for a great good and I figured how to write input for the code. 
peoples = [
     People {name="Hal", age=20},
     People {name="Susann", age=31},
     People {name="Dwight", age=19},
     People {name="Kassandra",age= 21},
     People {name="Lawrence", age=25},
     People {name="Cindy", age=22},
     People {name="Cory", age=27},
     People {name="Mac", age=19},
     People {name="Romana", age=27}, 
     People {name="Doretha", age=32}, 
     People {name="Danna", age=20}, 
     People {name="Zara", age=23},
     People {name="Rosalyn", age=26},
     People {name="Risa", age=24},
     People {name="Benny", age=28},
     People {name="Juan", age=33}, 
     People {name="Natalie", age=25}    
    ]
    
sorted = sort numbers 

instance Show People where
    show (People n a) = n ++ " " ++ show a  ++ "\n"

sortByName :: [People] -> [People]
sortByName = sortBy (comparing name)

sortByAge :: [People] -> [People]
sortByAge = sortBy (comparing age)


main = do 
putStrLn "By Numerical Value "
print $ sorted

putStrLn "\nBy name: "
print $ sortByName peoples

putStrLn "\nBy age: "
print (sortByAge peoples)



