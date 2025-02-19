#include <iostream>

// Include the glm library
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>
using namespace glm;
using namespace std;

int main() 
{
    //Vectors
    printf("Vectors and Matrices \n");
    printf("--------------------------------------------------\n");

    //define vectors
    vec3 a, b;
    a = vec3(3.0f, 0.0f, 4.0f);
    b[0] = 1.0f, b[1] = 2.0f, b[2] = 3.0f;

    //Vector length
    /*printf("\nVector Length:\n");
    printf("length(a) = %0.3f\n", length(a));
    printf("length(b) = %0.3f\n", length(b));*/

    //Normalising vectors
    //vec3 aUnitVec, bUnitVec;
    //aUnitVec = normalize(a);
    //bUnitVec = b / length(b);

    //printf("\nNormalising vectors:\n");
    //cout << "aUnitVec = " << aUnitVec << endl;
    //cout << "bUnitVec = " << bUnitVec << endl;
    //printf("length(aUnitVec) = %0.3f\n", length(aUnitVec));
    //printf("length(bUnitVec) = %0.3f\n", length(bUnitVec));

    //Arithmetic operations on vectors
    /*printf("\nArithmetic operations on vectors:\n");
    cout << "a + b" << a + b << endl;
    cout << "a - b" << a - b << endl;*/

    /*cout << "2a   = " << 2.0f * a << endl;
    cout << "b / 3 = " << b / 3.0f << endl;*/

    //Dot and Cross products
    printf("\nDot and cross products:\n");
    printf("a . b = %0.3f\n", dot(a, b));
    return 0;
}
