#ifndef CONCEPT_H
#define CONCEPT_H
#include <string>
#include <iostream>

namespace my_concepts{
    /**
     * @brief Concepts check whether interface(printable or sortable, comparable etc) of typename or class T is provided 
     * Syntax 
     * template< template parameter list>
     * concept concept_name -  constrain-expression;
     * requires   - allow userm to define their own contrain
     */
    template<typename T> 
    concept Printable = requires( const T & object){
        {std::cout<<object};
    };
    template<typename T> 
    concept EqualsComparable = requires( const T & object_a, const T & object_b){
        {object_a==object_b || object_a!=object_b};
    };
    template<typename T> 
    concept LessThanComparable = requires( const T & object_a, const T & object_b){
        {object_a<object_b};
    };
    template<typename T> 
    concept GreaterThanComparable = requires( const T & object_a, const T & object_b){
        {object_a>object_b};
    };

    template<typename T> 
    concept Square_Mutable = requires(T & object_a, int index){
        {object_a[index]=object_a };
    };
    template<typename T> 
    concept Round_Mutable = requires(T & object_a, int index){
        {object_a(index)=object_a };
    };
    template<typename T> 
    concept Insert_Mutable = requires(T & object_a, int index){
        {Round_Mutable<T> && Square_Mutable<T>};
    };

    template<typename T> 
    concept Copyable = requires(T &object_a,  const T &object_b ){
        {object_a=object_b};
    };
    template<typename T> 
    concept Movable = requires(T &&object_a, T &&object_b ){
        {object_a=std::move(object_b)};
    };
    template<typename T> 
    concept Addable = requires(const T &object_a, const T &object_b ){
        {object_a+object_b || object_a +=object_b};
    };

};


using namespace my_concepts;

template<typename T, int size>
class Template
{
private:
    /* data */
    T* elements;
    
    
public:
    Template(/* args */);

    Template(T & elements);
    //Template(T && elements);

    Template( const Template<T,size>& object)requires Copyable<T>;

    Template<T, size>& operator=(const Template<T,size> & object)requires Copyable<T>;

    Template(Template<T,size>&& object)requires Movable<T>;

    Template<T, size>& operator=(Template<T,size> && object)requires Movable<T>;


    T& operator[](const int index) requires Square_Mutable<T>;

    T& operator()(const int index)requires Round_Mutable<T>  ;

    const bool operator!=( const Template<T,size> & object)requires EqualsComparable<T>;

    void operator()(const int index, const T& element) requires Insert_Mutable<T> ;

    T* getElements();

    const T & min(const T & lhs, const T & rhs)requires LessThanComparable<T>;
    template<typename T_, int size_>
    friend T_ operator+(const T_& object_1,  const T_& object_2) requires Addable<T_>;
    template<typename T_, int size_>
    friend T_& operator+=(T_& object_1,  const T_& object_2) requires Addable<T_>;

    template<typename T_, int size_>
    friend std::ostream& operator<<(std::ostream & print,  Template<T_,size_> & object) requires Printable<T_>;

    template<typename T_, int size_>
    friend Template<T_,size_> operator+(const Template<T_,size_>& object_1,  const Template<T_,size_> & object_2);

    template<typename T_, int size_>
    friend Template<T_,size_>& operator+=(Template<T_,size_>& object_1,  const Template<T_,size_> & object_2);
    ~Template();
};


/**
 * @brief defaulted  construct
 * 
 * @tparam T  typename
 * @tparam size  size array
 */
template<typename T, int size>
Template<T, size>::Template(/* args */):elements(new T[size])
{
}
/**
 * @brief Get min T given two T objects 
 * 
 * @tparam T typename
 * @tparam size array
 * @param lhs  object 1 to compare  object 2
 * @param rhs  object 2  to compare object 1
 * @return const T&  minimum object between two given objects 
 */
template <typename T, int size> 
const T & Template < T, size>::min(const T & lhs, const T & rhs)
requires LessThanComparable<T>
{
    return lhs < rhs ? lhs : rhs;
}

/**
 * @brief Construct takes param T typename
 * 
 * @tparam T typename
 * @tparam size  size array
 * @param element  to be store to this class elements

 */
template<typename T, int size> 
Template<T, size>::Template(T & element){
    elements =new T[size];
    elements[0]= element;
}
/**
 * @brief Copy coonstruct
 * 
 * @tparam T typename
 * @tparam size  size array
 * @param object  to be copy to this class
 */
template<typename T, int size>
Template<T, size>::Template(const Template<T,size>& object)requires Copyable<T>{
    if(this != &object){
        if(this->elements != nullptr){
             elements = nullptr;
        }

        elements = new T[size];
        if(object.elements != nullptr){
            for(int i=0; i<size; i++){
                elements[i] = object.elements[i];
            }
        }
    }
        
    
}
/**
 * @brief Copy Assignment
 * 
 * @tparam T typename
 * @tparam size  size array
 * @param object  to be copy to this class
 * @return Template<T, size>&  this class
 */
template<typename T, int size>
Template<T, size>& Template<T, size>::operator=(const Template<T,size> & object)requires Copyable<T>{
    
     if(this != &object){

        if(this->elements != nullptr){
                 elements =nullptr ;
        }
        
        elements = new T[size];

        if(object.elements != nullptr){

            for(int i=0; i<size; i++){
                elements[i] = object.elements[i];
            }
        }
     }
    return *this;

}
/**
 * @brief Move Construct
 * 
 * @tparam T typename
 * @tparam size  size array
 * @param object  to be move to this class
 */
template<typename T, int size>
Template<T, size>::Template(Template<T,size>&& object)requires Movable<T>{
    
    if(this->elements != nullptr){
        delete [] this->elements ;
        this->elements=nullptr;
    }
    this->elements = std::move(object.elements);
    object.elements=nullptr;

}
/**
 * @brief Move Assignment
 * 
 * @tparam T typename
 * @tparam size  size array
 * @param object  to be move to this class
 * @return Template<T, size>&  this class
 */
template<typename T, int size>
Template<T, size>& Template<T, size>::operator=(Template<T,size> && object)requires Movable<T>{
    
     if(this == &object){
         object.elements =nullptr;

     }
    else{
        if(this->elements != nullptr){
            delete[] this->elements;
            this->elements=nullptr;
        }
        if(object.elements != nullptr){
           
            this->elements = std::move(object.elements);
            object.elements = nullptr;
        }
    }
    
    return *this;

}
/**
 * @brief Overload operator != for this template class
 * 
 * @tparam T  typename
 * @tparam size  array
 * @param object template object compare with this clas
 * @return true if this class equal object ( all elements in array are equals in the same indexes) 
 * @return false otherwise
 */
template<typename T, int size>
const bool Template< T,  size>::operator!=(const Template<T,size> & object)requires EqualsComparable<T>{
    bool equals = true;
    for( int i=0 ; i<size; i++){
        equals = this->elements[i] == object.elements[i];
        if (! equals)break;
    }
   return equals;
}
/**
 * @brief overload operator[] for get element at given index 
 * 
* @tparam T typename
 * @tparam size array
 * @param index of element 
 * @return T& of element 
 */
template<typename T, int size>
T& Template<T, size>::operator[](const int index) requires Square_Mutable<T>{

    return elements[index];
}
/**
 * @brief overload operator() for get element at given index 
 * 
 * @tparam T typename
 * @tparam size array
 * @param index of element 
 * @return T& of element 
 */
template<typename T, int size>
T& Template<T, size>::operator()(const int index) requires Round_Mutable<T> {
    return elements[index];
}
/**
 * @brief overload operator() for mutating array at given index and element
 * 
 * @tparam T typename
 * @tparam size  size array
 * @param index  insertion index
 * @param element  to insert at index
 */
template<typename T, int size>
void Template<T, size>::operator()(const int index, const T& element) requires Insert_Mutable<T>{
     elements[index] = element;
}
/**
 * @brief 
 * 
 * @tparam T typename
 * @tparam size  array
 * @return T*  array 
 */
template<typename T, int size>
T* Template<T,size>::getElements() {
    return elements;
}
template<typename T, int size>
T operator+(const T& object_1,  const T& object_2) requires Addable<T>{
    T results = object_1;
    results +=object_2;
    return results;
}
template<typename T, int size>
T& operator+=( T& object_1,  const T& object_2) requires Addable<T>{
    object_1 +=object_2;
    return object_1;
}
// Template<T_,size_> operator+(const Template<T_,size_>& object_1,  const Template<T_,size_> & object_2) requires Addable<T_>;

template<typename T, int size>
Template<T,size> operator+(const Template<T,size>& object_1,  const Template<T,size> & object_2){
    Template<T,size> results = object_1;
    results +=object_2;
    return results;
}
template<typename T, int size>
Template<T,size>& operator+=( Template<T,size>& object_1,  const Template<T,size> & object_2) {
    try{
        for(int i=0; i<size; i++){
          object_1.elements[i] +=object_2.elements[i];
        }
    }catch(std::exception){
        std::cout<<"Can't object of different size.\nLine 336 - 343"<<std::endl;
    }
     
    return object_1;
}


/**
 * @brief overload operator<< for template class
 * 
 * @tparam T typename
 * @tparam size  of array
 * @param print ostream object
 * @param object  object being printed out
 * @return std::ostream&  object for this template class
 */
template<typename T, int size> 
std::ostream& operator<<(std::ostream & print,  Template<T,size> & object)
requires Printable<T>
{
    
     for(int i=0; i<size; i++){
        print<<object.getElements()[i];
    }
    return print;
}
/**
 * @brief Destroy the Template< T, size>:: Template object
 * 
 * @tparam T typename
 * @tparam size  size array
 */
template<typename T, int size>
Template<T, size>::~Template()
{
    delete [] elements;
}

#endif 