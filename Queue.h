#include <iostream>
#include <string>

template <typename T>
class Queue { 
    int size; 
    T* queue; 
	
    public:
    Queue<T>() { 
        size = 0;
        queue = new T[10];
    }

    ~Queue(){
        delete [] queue;
    }


    //Copy Assign 
    Queue<T>& operator=(const Queue<T> &rhs){
            
        if (this != &rhs){ // Optimize

            size = rhs.size;
            delete [] queue; // release old resourses

            queue = new T[size];

            for(int j = 0 ; j<size;++j){
                this->queue[j] = rhs.queue[j];
            }

        }

        return *this;
            
    }

     Queue<T> & operator=(Queue<T> && rhs){
        std::cout<< "Move assign "<<std::endl;

        if (this == &rhs)
            return *this;
                
        size = rhs.size;
        delete [] queue;

        queue = rhs.queue;

        rhs.queue = nullptr;
        rhs.size = 0; 
        return *this;

    }
            

    // copy constructor 
    Queue<T>(const Queue<T> &rhs){
        size = rhs.size;
        queue = new T[size];

        for(int i = 0; i<size;++i){
            this->queue[i] = rhs.queue[i];
        }
    }

    Queue<T>(Queue<T> && rhs) : size(rhs.size), queue(rhs.queue){
        std::cout<<"Move Constructor"<<std::endl;  
        rhs.size = 0;
        rhs.queue = nullptr;
    }




    void add(T data) { 
        queue[size] = data; 
        size++;
    }
    void remove() { 
        if (size == 0) { 
            std::cout << "Queue is empty"<<std::endl; 
            return; 
        } 
        else { 
            for (int i = 0; i < size - 1; i++) { 
                queue[i] = queue[i + 1]; 
            } 
            size--; 
        } 
    } 
    void print() { 
        if (size == 0) { 
            std::cout << "Queue is empty"<<std::endl; 
            return; 
        } 
        std::cout<<*this<<std::endl; 
        std::cout << std::endl;
    }
    
    template <typename U>
    friend Queue<U> & operator+=(Queue<U> & lhs, const Queue<U> & rhs); 

    template <typename V>
    friend Queue<V> operator+( const Queue<V> & lhs, const Queue<V> & rhs); 

    template <typename X>
    friend Queue<X> operator+( const Queue<X> && lhs, const Queue<X> & rhs); 
    
    template <typename Y>
    friend std::ostream & operator<<(std::ostream & os, const  Queue<Y> & rhs);


}; 

    template <typename T>
    Queue<T> & operator+=(Queue<T> & lhs, const Queue<T> & rhs){
        for(int i = 0 ;i<rhs.size;i++){
            lhs.add(rhs.queue[i]);
        }
        return lhs;
    }

    template <typename T>
    Queue<T> operator+(const Queue<T> & lhs, const Queue<T> & rhs){
        std::cout<<"1st + called"<<std::endl;
        Queue<T> results = lhs;

        results += rhs;
        return results;
    }

 template <typename T>
    Queue<T> operator+(Queue<T> && lhs, const Queue<T> & rhs){
    std::cout<<"Second + called"<<std::endl;
    lhs += rhs;
    return std::move(lhs);
}

// This is like a toString in Java 
template <typename T>
std::ostream & operator<<(std::ostream & os, const  Queue<T> & rhs){

    std::cout<<"My To String"<<std::endl;
    for(int i = 0 ;i<rhs.size;++i){
        os<< rhs.queue[i] <<"->";
    }

    return os;
}

