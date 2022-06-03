#ifndef _OPR
#define _OPR

#include<iostream>
    template <typename T , int N>
    class Queue { 

        
        private:
            int size; 
            T* queue; 
           
        public:
            typedef Queue<T,N> queue_type;
            Queue():size{0},queue{new T[100]}{}

            Queue(Queue<T,N> && rhs) : size(rhs.size), queue(rhs.queue){
                std::cout<<"Move Constructor"<<std::endl;
                
                rhs.size = 0;
                rhs.queue = nullptr;
            }


            ~Queue(){
                delete[] queue;
            }
            // copy constructor 
            Queue(const Queue<T,N> &lhs){
                size = lhs.size;

                queue = new T[N];

                for(int i = 0; i<size;++i){
                    this->queue[i] = lhs.queue[i];
                }
            }
            // copy assignment 
            Queue<T,N>& operator=(const Queue<T,N> &lhs){
                
                if (this != &lhs){ // Optimize

                    size = lhs.size;
                    delete [] queue; // release old resourses

                    queue = new T[N];

                    for(int j = 0 ; j<size;++j){
                        this->queue[j] = lhs.queue[j];
                    }

                }

                return *this;
                
            }

            Queue<T,N> & operator=(Queue<T,N> && rhs){
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
            
            void add(T data){
                queue[size] = data; 
                size++;
            }
            void remove(){
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

            void print(){
                if (size == 0) { 
                    std::cout << "Queue is empty"<<std::endl; 
                    return; 
                } 
                std::cout<< *this;
                std::cout << std::endl;
            }

            Queue<T,N>  operator+(const Queue<T,N> &rhs){
                Queue results = *this; // to hold the results sum
               
                results+=rhs;
                return rhs;
            }

            Queue<T,N> & operator+=(const Queue<T,N> &rhs){
                for(int i = 0;i<rhs.size;++i){
                    this->add(rhs.queue[i]);
                }
                return *this;
            }
                   
            template <typename U, int V>
            friend std::ostream & operator<<(std::ostream & os,const Queue<U,V> & rhs );

            template <typename A, int B>
            friend Queue<A,B> operator+(Queue<A,B> && lhs,const  Queue<A,B> & rhs);
    };

    // This is like a toString in Java 
    template <typename T, int N>
    std::ostream & operator<<(std::ostream & os, const  Queue<T,N> & rhs){

        std::cout<<"My To String"<<std::endl;
        for(int i = 0 ;i<rhs.size;++i){
            os<< rhs.queue[i] <<"->";
        }

       // std::cout<<std::endl;

        return os;
    }

    template <typename T, int N>
    Queue<T,N> operator+(Queue<T,N> && lhs, const Queue<T,N> & rhs ){
        std::cout<<"Second + called"<<std::endl;
        lhs += rhs;
        return  std::move(lhs);
    }

    // Need to define the other functions like this 

#endif
