#ifndef TSEWU_H
#define TSEWU_H
#include <string>
#include <iostream>

class Tsewu
{
private:
    /* data */
    std::string* name;
public:
    Tsewu(/* args */);
    Tsewu(std::string &&name);
    Tsewu(const Tsewu &tsew);
    Tsewu& operator=(const Tsewu& tsewu);
    Tsewu(Tsewu &&tsew);
    Tsewu& operator=( Tsewu&& tsewu);
    const bool operator !=(const Tsewu& other_tsewu);
  
    friend std::ostream& operator<<(std::ostream &print, const Tsewu &tsewu);
    friend const bool  operator<(const Tsewu &tsewu, const Tsewu &Othe_tsewu);
    Tsewu& operator[](const int index);
    Tsewu& operator()(const int index);
    friend Tsewu  operator+(const Tsewu &tsewu, const Tsewu &Othe_tsewu);
    friend Tsewu&  operator+=(Tsewu &tsewu, const Tsewu &Othe_tsewu);

    std::string getName() {
        return *name;
    }

    const Tsewu & min(const Tsewu & lhs, const Tsewu & rhs);


    ~Tsewu();
};
/**
 * @brief Defualted construct 
 * 
 */
Tsewu::Tsewu(/* args */)
{
    this->name = new std::string;
        *(this->name)= "Wanga";
}
/**
 * @brief Copy Construct
 * 
 * @param tsewu  object being   its content being copied

 */
Tsewu::Tsewu(const Tsewu &tsewu){
    
    if(this != &tsewu){

        if(this->name != nullptr){
            //delete this->name;
            this->name == nullptr;
        }
        if(tsewu.name !=nullptr){
            this->name = new std::string(*(tsewu.name));
        }
    }
   

}
/**
 * @brief Copy Assigbment
 * 
 * @param tsewu  object being   its content being copied
 * @return Tsewu& of this class 

 */
Tsewu& Tsewu::operator=(const Tsewu& tsewu){

    if(this != &tsewu){
        if(this->name != nullptr){
            delete this->name;
            this->name == nullptr;
        }
        if(tsewu.name !=nullptr){
            this->name = new std::string(*(tsewu.name));
        }
    }

    return *this;

}

/**
 * @brief Move Construct
 * 
 * @param tsewu  object being   its content being moved
 */
Tsewu::Tsewu( Tsewu &&tsewu){
    
    if(this != &tsewu){
        this->name = std::move(new std::string(*(tsewu.name)));
        
    }
    tsewu.name =nullptr;
   

}
/**
 * @brief Move Assigbment
 * 
 * @param tsewu  object being   its content being moved
 * @return Tsewu&  this Tsewu
 */
Tsewu& Tsewu::operator=(Tsewu && tsewu){

    if(this != &tsewu){
         if(this->name !=nullptr){
            delete this->name; 
            this->name =nullptr;
         }
         if(tsewu.name !=nullptr){
            this->name = std::move(new std::string(*(tsewu.name)));
            tsewu.name =nullptr;
         }
    }

    return *this;

}
/**
 * @brief overload operator[] for get using [] given index 
 * 
 * @param index  index element being returned 
 * @return Tsewu&  element  given index
 */
Tsewu& Tsewu::operator[](const int index){

    return *(this+index);
}
/**
 * @brief overload operator for get using () given index 
 * 
 * @param index  index element being returned 
 * @return Tsewu&  element  given index
 */
Tsewu& Tsewu::operator()(const int index){
    return *(this+index);
}

/**
 * @brief overload operator != for Tsewu class
 * 
 * @param other_tsewu  another Tsewu object compare to this Tsewu
 * @return true  if this tsewu is less than other tsewu 
 * @return false otherwise
 */
const bool Tsewu::operator!=(const Tsewu& other_tsewu){
   
    return (*(other_tsewu.name) != *(this->name) )? true : false;
}

Tsewu  operator+(const Tsewu &tsewu, const Tsewu &Othe_tsewu){
    Tsewu results = tsewu; 
    results += Othe_tsewu;
    return results;
}
Tsewu&  operator+=( Tsewu &tsewu, const Tsewu &Othe_tsewu){

    *(tsewu.name) += ", "+*(Othe_tsewu.name);
    return tsewu;
}
/**
 * @brief overload operator << for Tsewu class 
 * 
 * @param print  is the ostream object for printing
 * @param tsewu  is Tsewu  object being printed
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &print, const Tsewu &tsewu){
    print<<"Tsewu "+*(tsewu.name)<<std::endl;
    return print;
}

/**
 * @brief Construct a new Tsewu:: Tsewu object
 * 
 * @param name - name to initialise name
 */
Tsewu::Tsewu(std::string &&name):name(new std::string(name))
{
}
/**
 * @brief overload less than operator
 * 
 * @param lhs  object 1 compare to object 2
 * @param rhs object 2 compare to object 1
 * @return const Tsewu&  object 1 if object 1 is less than object 2 otherwise object 2

 */
const Tsewu & Tsewu::min(const Tsewu & lhs, const Tsewu & rhs)
{
    return lhs < rhs ? lhs : rhs;
}
/**
 * @brief overload less than operator
 * 
 * @param tsewu  object 1 compare to object 2
 * @param Othe_tsewu object 2 compare to object 1
 * @return true if object 1 is less than object 2
 * @return false  otherwise
 */
const bool operator<(const Tsewu &tsewu, const Tsewu &Othe_tsewu)
{  
   return  ( tsewu.name->length() < Othe_tsewu.name->length() ) ?  true:  false;
}
/**
 * @brief Destroy the Tsewu:: Tsewu object
 * 
 */
Tsewu::~Tsewu()
{
    delete  name;
}

#endif