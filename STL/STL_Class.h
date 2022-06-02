#ifndef STL_CLASS_H
#define STL_CLASS_H
#include <cstring>
namespace my_factors{

    /**
     * @brief templated method that copy values of the input iterator( container ) to output iterator( can be contain or iostream)
     * 
     * @tparam InputIterator  Iterator of the input data
     * @tparam OutputIterator Iterator of the output data
     * @param first start copying data
     * @param last   end copying data
     * @param results Output value
     * @return OutputIterator 
     */
    template<typename InputIterator, typename OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last, OutputIterator results){

            for(; first!=last; ++first, ++results){
                *results = *first;
            }
        return results;
    }
    
    /**
     * @brief templated method that copy values of the input iterator( container ) to output iterator( can be contain or iostream)
     *  if satify condition of Predicator
     * 
     * @tparam InputIterator Iterator of the input data
     * @tparam OutputIterator OutputIterator Iterator of the output data
     * @tparam Predicate functor function typename
     * @param first start copying data
     * @param last  end copying data
     * @param results Output value satify conditions
     * @param functor   functor function check if element of input data satify condition
     * @return OutputIterator 
     */
    template<typename InputIterator, typename OutputIterator, typename Predicate>
    OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator results, Predicate functor){

            for(; first!=last; ++first){
                if(functor(*first)) {
                    *results++ = *first;
                }
                
            }
        return results;
    }

    

    /*class functor_multiplier
    {
    private:
      
    public:
        
     /**
      * @brief Transform value by multiplier
      * 
      * @param x  value to be transformed 
      * @param multiplier  tranformer valuer
      * @return int  tranformed value
      *
     int operator()(const int& x)const{
         return x*2;
     }
     
     
    };*/
    
    template<typename T>
    concept Not_equalComparable = requires(const T &a , const T &b){{a!=b};};
    template<typename T>
    concept Addable = requires(const T &a , const T &b){{a+b};};
    template<typename T>
    class Not_equal
    {
    private:
        /* data */
        const T* value;
    public:
        Not_equal (const T &value): value(&value){}
        /**
      * @brief compare two given values
      * 
      * @param a  value compare to b value
      * @param b  value compare to a value
      * @return true  if a value less than b value
      * @return false  otherwise
      */
        bool operator()(const T &a)const  requires Not_equalComparable<T>{
            return a != *value;
        }
    };

    
    template<typename T>class EachBit{
           
        public:
            std::size_t count, bit;
            EachBit(std::size_t bit):count(0), bit(bit){}
            EachBit(const EachBit& object): count(object.count), bit(object.bit){}

            void operator()(const T& value){
                 if(value &(0x1<<bit)){
                    ++count;
                }
            }

    };

    template<typename T>class Transform{
           
        public:
            const T* Value;
            /**
             * @brief Construct a new Transform object
             * 
             * @param value initialise Value 
             */
            Transform( const  T& value):Value(&value){}
            /**
             * @brief transform each value of data
             * 
             * @param value  data element to tranform
             * @return T  transformed value
             */
            T operator()(const T& value)const requires Addable<T>{
                 return *Value+value;
            }

    };


    template<typename T>class Sum{
           
        public:
            T sum;
            int N;
            /**
             * @brief Construct a new Sum object
             * 
             */
            Sum():N(0){}
            /**
             * @brief Construct a new Transform object
             * 
             * @param value initialise Value 
             */
            Sum( const  Sum& obj):sum(obj.sum), N(obj.N){}
            /**
             * @brief Sum value of data
             * 
             * @param value  data element to add
             * @return T  sum value
             */
            void operator()(const T& value) requires Addable<T>{
                 if(N==0)sum = value;
                 else sum = sum + value;
                 ++N;
            }

            T getSum()const{
                return sum;
            }


    };
  
  
    /*template<typename IT , typename Cmp>
    void sort(IT a, IT b, Cmp cmp_fun){ ... if(cmp_fun(a,b)) ... }*/


    
    
}


#endif