#ifndef _OPR
#define _OPR

#include<iostream>

    template <typename T>
    class Queue { 
        private:
            int size; 
            T* queue; 
        public:
            Queue():size{0},queue{new T[100]}{}

            /*~Queue(){
                delete [] queue;
            }
            */
            
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
            Queue & operator+(Queue &other){

                for(int i=0;i<other.size;++i){
                    this->add(other.queue[i]);
                }
                return *this;
            }
            Queue & operator+=(Queue &other){
                *this = *this + other;
                return *this;
            }
            
            
            void Swap(T &a,T &b){
                T temp = b;
                b = a;
                a = temp;
            }

            
    };

#endif