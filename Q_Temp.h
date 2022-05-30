#ifndef _OPR
#define _OPR

#include<iostream>

    template <typename T , int N>
    class Queue { 
        private:
            int size; 
            T* queue; 
        public:
            Queue():size{0},queue{new T[N]}{}

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
                for (int i = 0; i < size; i++) { 
                    std::cout<<queue[i]<<" <- ";
                } 
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
            
            
            void Swap(T &a,T &b){
                T temp = b;
                b = a;
                a = temp;
            }

            
    };

#endif
