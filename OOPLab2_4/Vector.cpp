#include <iostream>
#include "Vector.h"

using namespace std;

int main() {

    int arr[] = { 1, 2, 3, 4, 5 };
    Vector vec1(arr, 5);


    cout << "Vector 1: " << vec1 << endl;


    Vector vec2;
    cin >> vec2;
    cout << "Vector 2: " << vec2 << endl;

    if (vec1 == vec2) {
        cout << "Vectors 1 and 2 are equal." << endl;
    }
    else {
        cout << "Vectors 1 and 2 are not equal." << endl;
    }

    Vector vec3 = vec1++;
    cout << "Vector 3 (post-increment): " << vec3 << endl;
    Vector vec4 = ++vec2;
    cout << "Vector 4 (pre-increment): " << vec4 << endl;


    int scalar = 2;
    Vector vec5 = vec1 * scalar;
    cout << "Vector 5 (multiplied by " << scalar << "): " << vec5 << endl;


    cout << "Norm of vector 1: " << vec1() << endl;


    try {
        int index = 2;
        cout << "Element at index " << index << " of vector 2: " << vec2[index] << endl;
    }
    catch (const out_of_range& ex) {
        cout << "Exception caught: " << ex.what() << endl;
    }

    return 0;
}