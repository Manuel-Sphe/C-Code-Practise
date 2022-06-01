#include "Queue.h"

int main() { 
    Queue<int> q1,q2,q3,q4; 
    q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
    q1.print();

    q2.add(12); q2.add(20); q2.add(81);  q2.add(10) ;q2.add(50);
    q2.print();

    q3.add(200); q3.add(500); q3.add(800);  q3.add(190) ; q3.add(2020); q3.add(2022);
    q3.print();


    q4 = q1 + q2 +q3;

    q4.print();
    
    
    Queue<std::string> s1,s3;
    s1.add("Dave"); s1.add("John"); s1.add("Amy");

   

    s1.print();

    
    return 0; 
} 
