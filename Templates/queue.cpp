/**
 * @file queue.cpp
 * @author Sphesihle Madonsela (you@domain.com)
 * @brief This code test the Templated Queue class with int and string 
 * @version 0.1
 * @date 2022-05-26
 * Credit, SoloLearn question
 * @copyright Copyright (c) 2022
 * 
 */

#include "Q_Temp.h"
#include <string>
int main(int argc, char **argv){
    
    Queue<int,4> q1, q2, q3,q4; 
    {
       
        q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
        q1.print();
      
        q2.add(3); q2.add(66); q2.add(128);  q2.add(5);
        q2.print();

        std::cout<< "Adding q1 and q2 i.e q3 = q1+q2"<<std::endl;
        q3 = q1+q2;
        q3.print();

        std::cout<<"q3 = q1+q2+q1"<<std::endl;
        q3.add(221); q3.add(123); q3.add(144); q3.add(505);
        q3.print();

        q4 = q1 + q2 + q3;
        std::cout<<q4<<std::endl;
    }
    
    std::cout << std::endl;

   Queue<std::string,3 > s1,s2; 
    {
        s1.add("C++ is awesome"); s1.add("Strings are cool"); s1.add("You are great");
        s1.print();

        Queue<std::string, 3> s3;

        s3 +=s2;
            
    }  

    
    return 0;
}