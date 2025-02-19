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
    /*vec3 a, b;
    a = vec3(3.0f, 0.0f, 4.0f);
    b[0] = 1.0f, b[1] = 2.0f, b[2] = 3.0f;*/

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

    //Element multiplication
   // cout << "a * b = " << a * b << endl;

    //Dot and Cross products
    /*printf("\nDot and cross products:\n");
    printf("a . b = %0.3f\n", dot(a, b));*/

    //cout << "a x b = " << cross(a, b) << endl;
    //printf("a . (a x b) = %0.3f\n", dot(a, cross(a, b)));
    //printf("b . (a x b) = %0.3f\n", dot(b, cross(a, b)));

    //Defining matrices
    mat2 A, B;

    A[0][0] = 1.0f, A[0][1] = 2.0f,
    A[1][0] = 3.0f, A[1][1] = 4.0f;

    B = mat2(5.0f, 6.0f, 7.0f, 8.0f);

    /*printf("\Defining matricies\n");
    cout << "A = " << A << "\n" << endl;
    cout << "B = " << B << "\n" << endl;*/

    /*cout << "A = " << transpose(A) << "\n" << endl;
    cout << "B = " << transpose(B) << "\n" << endl;*/

    //Arithmetic operations on matricies
    /*printf("Arithmetic operations on matricies:\n");
    cout << "A + B = " << transpose(A + B) << "\n" << endl;
    cout << "A - B = " << transpose(A - B) << "\n" << endl;
    cout << "2A = " << transpose(2.0f * A) << "\n" << endl;
    cout << "A / 3 = " << transpose(A / 3.0f) << "\n" << endl;*/

    //Matrix Multiplication
    /*cout << "A * B = " << transpose(B * A) << "\n" << endl;
    cout << "B * A = " << transpose(A * B) << "\n" << endl;*/

    //The Identity Matrix
    /*printf("\nIdentity Matrix:\n");
    mat4 I;
    cout << "I =" << transpose(I) << "\n" << endl;*/

    //Inverse matrices
    printf("Inverse Matrices:\n");
    mat2 invA = inverse(A);
    mat2 invB = inverse(B);
    cout << "invA = " << transpose(invA) << "\n" << endl;
    cout << "invB = " << transpose(invB) << "\n" << endl;
    cout << "invA * A = " << transpose(invA * A) << "\n" << endl;
    cout << "invB * B = " << transpose(invB * B) << "\n" << endl;
    return 0;
}
