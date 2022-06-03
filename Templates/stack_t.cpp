
#include "stack.h"
#include <iomanip>

typedef Stack<unsigned> USTACK; // for unsigned types 
void fill( USTACK& stk );
void clear( USTACK& stk );

int main(int argc,char* argv[]){
    
    USTACK ustk(10); // Create and fill
    fill( ustk); // the original stack.
    
    USTACK ostk(ustk);

    std::cout << "The copy: " << std::endl;
    clear( ostk); // Output and clear the copy.
    std::cout << "The original: " << std::endl;
    clear( ustk ); // Output, clear the original. 
    
    return 0;
}

void fill(USTACK &stk){
    unsigned x;
    std::cout << "Enter positive integers (quit with 0):\n";
    while( std::cin >> x && x != 0 )
        if( !stk.push(x) ){
            std::cerr<<"Stack is full "<<std::endl; break;
        }   
    std::cout<<"Done"<<std::endl;
}

void clear(USTACK & stk){
    if(stk.empty())
        std::cerr << "Stack is empty!" << std::endl;
    else{
        unsigned x;
        while( stk.pop(x))
            std::cout << std::setw(8) << x << " ";
        std::cout << std::endl;
    }
}