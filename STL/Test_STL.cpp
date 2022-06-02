#include <vector>
#include "STL_Class.h"
#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
#include<typeinfo>
class Student
{
private:
    /* data */
    std::string name;
public:
    Student(/* args */):name("Lu")
    {
    }
    Student(std::string &&name):name(name)
    {
    }
    Student(std::string &name):name(name)
    {
    }
    friend const bool operator!=(const Student & a, const Student & b){

        return (a.name!=b.name)? true:false;
    }
    friend std::ostream&  operator<<( std::ostream& print, const Student & object){

        return print<<object.getName();
    }

    std::string getName()const{
        return name;
    }

    ~Student()
    {
    }
    
};
class Lu: public Student{
    public:
        Lu():Student(){}
        Lu(std::string &name):Student(name){}
        Lu(std::string &&name):Student(name){}
};


int main(){
   
   // copy  data from  vector to another 
   std::cout<<"copy insert "<<std::endl;
    std::vector<int> data ={1,2,3,4,5,6,7};
    std::vector<int> results(data.size());
    my_factors::copy(data.begin(), data.end(),results.begin());
    // overload ostream to print data from container 
    my_factors::copy(results.begin(), results.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<<"\n";
  
  
   //back insert copy  
   std::cout<<"back insert "<<std::endl;
   std::vector<int> results_back_iterator ;
   //std::back_insert_iterator<std::vector<int>> back_insert(results_back_iterator);
   my_factors::copy(data.begin(),data.end(),std::back_inserter(results_back_iterator));
    my_factors::copy(results_back_iterator.begin(), results_back_iterator.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<<"\n";

   // Front insert 
    std::cout<<"Front insert "<<std::endl;
    std::list<int> results_front_insert;
    my_factors::copy(data.begin(),data.end(),std::front_inserter(results_front_insert));
    my_factors::copy(results_front_insert.begin(), results_front_insert.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<<"\n";


    //STL Algorithms
    std::cout<<"STL Algorithms"<<std::endl;
    std::vector<int> my_data (10);

    std::cout<<"Fill Algorithms"<<std::endl;
    std::fill(my_data.begin(),my_data.end(), 4 );
    my_factors::copy(my_data.begin(), my_data.end(), std::ostream_iterator<int>(std::cout, ", "));std::cout<<"\n";
   
    std::cout<<"Remove Algorithms"<<std::endl;
    my_data[4]= 3;
    my_data[9]=-1;
    std::remove(my_data.begin(), my_data.end(), 3);
     my_factors::copy(my_data.begin(), my_data.end(), std::ostream_iterator<int>(std::cout, ", "));std::cout<<"\n";

     std::cout<<"Find Algorithms"<<std::endl;
     std::vector<int>::iterator find = std::find(my_data.begin(),my_data.end(),6);
     std::cout<<*find<<std::endl;

    std::cout<<"Sort Algorithms"<<std::endl;
    std::sort(my_data.begin(), my_data.end());
    my_factors::copy(my_data.begin(), my_data.end(), std::ostream_iterator<int>(std::cout, ", "));std::cout<<"\n";

    std::cout<<"Accumulate Algorithms"<<std::endl;
    int total = std::accumulate(my_data.begin(), my_data.end(), 10);
    std::cout<<total<<std::endl;

    std::cout<<"Transform Algorithms"<<std::endl;
    std::vector<int> values;
    std::transform(my_data.begin(), my_data.end(),std::back_inserter(values), my_factors::Transform<int>(2));
    my_factors::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, ", "));std::cout<<"\n";
    std::vector<int> values_positive;
    std::cout<<"Copy_if  functor"<<std::endl;
    my_factors::copy_if(values.begin(), values.end(), std::back_inserter(values_positive), my_factors::Not_equal<int>(-2));
    my_factors::copy(values_positive.begin(), values_positive.end(), std::ostream_iterator<int>(std::cout, ", "));std::cout<<"\n";
   
    //Test using Student class
    std::vector<Student> students ={Student(), Student("Wanga"), Student("Sisa"),Student("Kuhle")};
    std::vector<Student> students_results ;
    my_factors::copy_if(students.begin(), students.end(), std::back_inserter(students_results), my_factors::Not_equal<Student>(Student("Lu")));
    my_factors::copy(students_results.begin(), students_results.end(), std::ostream_iterator<Student>(std::cout, ", "));std::cout<<"\n";
     
    //For each 
    std::cout<<"For each functor"<<std::endl;
    std::vector<int> int_values(6) ;
    std::fill(int_values.begin(),int_values.end(), 3);
    my_factors::copy(int_values.begin(), int_values.end(), std::ostream_iterator<int>(std::cout, ", "));std::cout<<"\n";
    my_factors::EachBit<int>bit(3);
    my_factors::EachBit<int>bit_(4);
    std::for_each(int_values.begin(), int_values.end(), bit);
    std::cout<<bit.count<<std::endl;
    std::for_each(int_values.begin(), int_values.end(), bit_);
    std::cout<<bit_.count<<std::endl;



   std::cout<<"**********************************  LAMBDAS ********************************************************"<<std::endl;
    /**
     * @brief LAMBDAS 
     * Great replacement for  functors above 
     * Formart :  [capture args](parameters)->(return type(optional)){ body} 
     * capture args - way want to capture value ( reference or by value)
     * parameters  - usual parameters like functions
     * return type is optional - compiler figures it out
     * body - write logic of lambdas like function body 
     */
     std::cout<<"Sum lambdas_vector elements from 10\n";
     std::vector<int> lambdas_vector = {1,2,3,4,5,6,7};
     int sum =10;
     std::for_each(lambdas_vector.begin(), lambdas_vector.end(),[&](int x){sum+=x;});
     std::cout<<sum<<std::endl;
     int multiplier_value =3;

     //multiplier lambdas_vector elements by 3
     std::cout<<"multiplier lambdas_vector elements by 3\n";
     std::vector<int>lamdas_transform_results;
     std::transform(
         lambdas_vector.begin(),lambdas_vector.end() ,std::back_inserter(lamdas_transform_results),
            [=](int value)->int{return value*multiplier_value;}
     );
     my_factors::copy(lamdas_transform_results.begin(), lamdas_transform_results.end(), std::ostream_iterator<int>(std::cout,", "));std::cout<<"\n";
     
     //copy if lamdas_transform_results elements greater than 9
     std::cout<<"copy if lamdas_transform_results elements greater than 9\n";
     std::vector<int>lamdas_copy_if_results;
     const int value_copy_if = 9;
     std::copy_if(
         lamdas_transform_results.begin(),lamdas_transform_results.end() ,std::back_inserter(lamdas_copy_if_results),
            [& , value_copy_if](const int &value)->bool const{return value > value_copy_if;}
     );
     my_factors::copy(lamdas_copy_if_results.begin(), lamdas_copy_if_results.end(), std::ostream_iterator<int>(std::cout,", "));std::cout<<"\n";

    //Sort array elements in ascending order
    std::cout<<"Sort array elements in ascending order\n";
    char* array[3] ={"abc","ghi","def"};
    std::sort(array, array+3, [](char*a, char*b)->bool const{return std::strcmp(a,b)<0;});
    my_factors::copy(array, array+3, std::ostream_iterator<char*>(std::cout,", "));std::cout<<"\n";
    
    // Sum using lamdas 
    std::cout<<"Sum array elements \n";
    std::vector<std::string> strings  = {"Awe", " ta", " Brizo"};
    int N=0;
    std::string Sum ="";
    std::for_each(strings.begin(), strings.end(), [&Sum,&N](const std::string & value)->void{
        if(N==0) Sum=value;
        else Sum = Sum +value;
        ++N;

    });
    std::cout<<Sum<<std::endl;
      
      
    //check type of object 
    std::cout<<"check types of object"<<std::endl;
    Student* a  = new Student();
    Lu*  b = new Lu(); 
    Student* z = new Lu();
    std::cout<<"Stude is: "<<typeid(a).name()<<std::endl;
    std::cout<<"Stude is: "<<typeid(b).name()<<std::endl;
    std::cout<<"Stude is: "<<typeid(*a).name()<<std::endl;
    std::cout<<"Stude is: "<<typeid(*b).name()<<std::endl;
    std::cout<<"Stude is: "<< (typeid(a) == typeid(b))<<std::endl;
    std::cout<<"Stude is: "<<(typeid(*a) == typeid(*b))<<std::endl;
    std::cout<<"Stude is: "<<(typeid(*a) == typeid(*z))<<std::endl;
    std::cout<<"Stude is: "<<(typeid(*z) == typeid(*b))<<std::endl;

    


    return 0;
}
