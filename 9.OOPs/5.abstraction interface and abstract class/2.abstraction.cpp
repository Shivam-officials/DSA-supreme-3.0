#include <iostream>
#include "1.bird.h"
using namespace std;

void birdDoesSomething(Bird *bs){
    bs->fly();
    bs->eat();
    bs->fly();
}

int main(int argc, char const *argv[])
{   
    Bird *sparrow = new Sparrow();

    birdDoesSomething(sparrow);

   

    Bird *bs = new Eagle();
    birdDoesSomething(bs);

    return 0;
}
