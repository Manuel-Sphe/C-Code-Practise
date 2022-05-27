#ifndef STACK
#define STACK
    #include <iostream>
    template <typename T>
    class Stack{
        private:
            T* basePtr; 
            int max_size;
            int tip; //Stack tip

        public:
            Stack(int n): basePtr(new T[n]), max_size(n), tip(0)  {} //
            
            Stack(const Stack<T>& lhs){//Copy Construtor

                std::cout<<"Copy Constructor "<<std::endl;
                
                max_size = lhs.max_size;
                
                tip = lhs.tip;

                basePtr = new T[max_size]; // Very important, don't remove this causes a seg fault 

                for(int i = 0 ;i<max_size;++i){
                        
                        this->basePtr[i] = lhs.basePtr[i]; // copy everything 
                }
            } 

            ~Stack(){
                delete[] basePtr;
            }

            Stack<T>& operator=(const Stack<T> & lsh){
                if(this != &lsh){
                    max_size = lsh.max_size;
                    tip = lsh.tip;
                    delete [] basePtr;

                    basePtr = new T[max_size];

                    for(int i =0 ;i<max_size;++i){
                        this->basePtr[i] = lsh.basePtr[i];
                    }

                    
                }
                return *this;
            } //Copy Assignment 

            // Methods 

            bool empty(){ return (tip==0);};
            bool push(const T& x);
            bool pop(T& x);

    };

    template <typename T>
        bool Stack<T>::push(const T& x){
            if (tip<max_size-1){
                basePtr[tip++] = x;
                return true;
            }
            else 
                return false;
        }
    template <typename T>
        bool Stack<T>::pop(T& x){
            if(tip>0){
                x = basePtr[--tip];
                return true;
            }
            return false;
        }

#endif