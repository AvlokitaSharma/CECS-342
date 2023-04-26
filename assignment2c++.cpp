//My CECS 325 taught me how vectors can come handy while sorting. Luckily, i used it //and it was helpful 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct People {
    string name;
    int age;
};


template<typename T>
bool comparename(const T& a, const T& b)
{
    return a.name<b.name;
}

template<typename T>
bool compareagename(const T& a, const T& b)
{
  
    if (a.age>b.age)
        return true;
    if (a.age<b.age)
        return false;
    return a.name<b.name;
}

void printPeople(vector<People> peoples){
    for(int i=0;i<peoples.size(); i++){
        cout<< peoples[i].name<<", "<<peoples[i].age<< endl;
    }
    cout<<endl;
}

int main(int argc, char **argv)
{
    vector<float> numbers{645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    
    vector<People> peoples{{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};
    
    
    std::sort(numbers.begin(), numbers.end(), std::less<float>());

    cout<<"Numerical Value: \n";
    for(int i=0;i<numbers.size(); i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    
    
    std::sort(peoples.begin(), peoples.end(), comparename<People>);
    
    cout<<"\n By name: \n";
    printPeople(peoples);
    
    
    
    std::sort(peoples.begin(), peoples.end(), compareagename<People>);
    cout<<"\ndescending age, if same age then ascending names: \n";
    printPeople(peoples);
    
    return 0;
}
