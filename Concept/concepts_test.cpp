#include "Template.h"
#include  "Tsewu.h"
#include <iostream>


int main(){
     


    Tsewu lu("Lu");
    Tsewu wanga;
    Tsewu Bonile("Bonile");
    Tsewu sizwe("Sizwe");
    Template<Tsewu, 3>template_obj(lu);
    std::cout<<template_obj;
    std::cout<<template_obj.min(lu, wanga);
    std::cout<<template_obj.min(lu, Bonile);
    
    template_obj[0]=lu;
    template_obj(1)=wanga;
    template_obj(2)=Bonile;
    template_obj(1,sizwe);

   std::cout<<"***********1*********\n";
   std::cout<<template_obj;


   std::cout<<"**********Constructable**********\n";
   ////test copy construct 
   Template<Tsewu, 3>template_obj_1(template_obj);
   std::cout<<template_obj_1;


   std::cout<<"********** Copyable**********\n";
   ////test copy Assignment 
   Template<Tsewu, 3>template_obj_2;
   template_obj_2= template_obj_1;
   std::cout<<template_obj_2;



   std::cout<<"********** Movable **********\n";
   //test move construct
   Tsewu lungile  = Tsewu("Lungisile");
   Template<Tsewu,3> N{Template<Tsewu, 3>(lungile) };
   std::cout<<N;
   //test move assignment
   template_obj_1 = std::move(template_obj_2);
   std::cout<<template_obj_1;

   std::cout<<"********** Addable Tsewu class **********\n";

   Tsewu sisand("Sisanda");
   Tsewu yolanda("Yolanda");
   Tsewu tumeka("Tumeka");
   Tsewu Family ;
   Family += tumeka+sisand+yolanda;
   std::cout<<Family;

   std::cout<<"********** Addable Template class **********\n";

   Template<Tsewu, 3> template_family ;
   template_family += N + template_obj_1;
   std::cout<<template_family;
   std::cout<<"********** Addable Template class at index**********\n";
   std::cout<<template_family(0);



 
   
    
    return 0;
}