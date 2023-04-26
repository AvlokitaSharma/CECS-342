// I used help of a reference: https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.list-1.sort?view=net-7.0 to understanding generic sorting in C#. I did not however copy the code. I also learned about LINQ to broden my knowledge on the same website. 

using System;
using System.Collections.Generic;
using System.Linq;

public class People {
	public string name {get; set;}
	public int age {get; set;}
}


					
public class Program
{
	public static void Main()
	{
	    float[] numbers={645.41f, 37.59f, 76.41f, 5.31f, -34.23f, 1.11f, 1.10f, 23.46f, 635.47f, -876.32f, 467.83f, 62.25f};
		List<People> peoples = new List<People>(){
		    	new People {name="Hal", age=20},
		    	new People {name="Susann", age=31}, 	
		    	new People {name="Dwight", age=19}, 
		    	new People {name="Kassandra",age= 21}, 
		    	new People {name="Lawrence", age=25}, 	
		    	new People {name="Cindy", age=22}, 	
		    	new People {name="Cory", age=27}, 	
		    	new People {name="Mac", age=19}, 	
		    	new People {name="Romana", age=27}, 	
		    	new People {name="Doretha", age=32}, 	
		    	new People {name="Danna", age=20}, 
		    	new People {name="Zara", age=23}, 	
		    	new People {name="Rosalyn", age=26}, 	
		    	new People {name="Risa", age=24}, 	
		    	new People {name="Benny", age=28}, 	
		    	new People {name="Juan", age=33}, 	
		    	new People {name="Natalie", age=25}
		};
		
		Array.Sort(numbers); 
		Console.WriteLine("Numeric Value: ");
		foreach(float number in numbers){
		  Console.WriteLine(number +" ");  
		}
		Console.WriteLine();
		
		
		List<People> sortedPeoples = peoples.
			OrderBy(x => x.name).ToList();
		
		Console.WriteLine("By name:");
		foreach(People people in sortedPeoples){
		  Console.WriteLine(people.name +", "+ people.age);  
		}
		Console.WriteLine();
		
		
		sortedPeoples = peoples.
			OrderByDescending(x => x.age).
			ThenBy(x => x.name).ToList();
		
		Console.WriteLine("By age in descending order, if age is same then name in asending order:");
		foreach(People people in sortedPeoples){
		  Console.WriteLine(people.name +", "+ people.age);  
		}
		Console.WriteLine();
	}
	
}
