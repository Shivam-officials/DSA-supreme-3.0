#include <iostream>
using namespace std;



// tail recursion bcz recursive call is at end
void printCountNto1(int n){

    // base case
    if(n ==0)
    {
        return;
    }
    
    //processing 
    cout << n <<endl;

   // recursive relation
    printCountNto1(n-1);
    return ;
}


// head reacursion bcz recursve call is not on the last line ..its in middle
void printCount1toN(int n){

    // base case
    if(n ==0)
    {
        return;
    }
    

    // recursive relation
    printCount1toN(n-1);

    //processing
    cout << n <<endl;
    return ;
}

int main(int argc, char const *argv[])
{
    printCountNto1(10);
    cout << endl<<"------------------"<<endl;

    printCount1toN(10);
    return 0;
}
