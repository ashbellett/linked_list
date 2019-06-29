#include "../include/dynamic-array.hh"

template <class T>
Array<T>::Array() {
    /* Initialises array object. */ 
    a_capacity = 1;                        // set initial capacity to one element
    a_length = 0;                          // no occupied elements when created
    a_data = (T *)malloc(sizeof(*a_data)); // allocate memory for one element
}

template <class T>
Array<T>::~Array() {
    /* Terminates array object. */
    free(a_data); // deallocate memory
}

template <class T>
size_t Array<T>::length(void) {
    /* Returns number of occupied elements. */
    return a_length;
}

template <class T>
size_t Array<T>::capacity(void) {
    /* Returns maximum array size. */
    return a_capacity;
}

template <class T>
void Array<T>::print(void) {
    /* Prints each element and index in array. */
    for (int i = 0; i < a_length; i++) {     // for each element
        cout << i << ": " << get(i) << "\n"; // print index and data
    }
}

template <class T>
void Array<T>::expand(void) {
    /* Expands maximum size of array. */
    a_capacity *= 2;                                             // double maximum size
    a_data = (T *)realloc(a_data, a_capacity * sizeof(*a_data)); // reallocate memory
}

template <class T>
void Array<T>::shrink(void) {
    /* Reduces maximum size of array. */
    a_capacity /= 2;                                             // halve maximum size
    a_data = (T *)realloc(a_data, a_capacity * sizeof(*a_data)); // reallocate memory
}

template <class T>
void Array<T>::push(T data) {
    /* Inserts one element at end of array. */
    if (a_length >= a_capacity) {  // if array capacity is exceeded
        expand();                  // expand array capacity
    }
    *(a_data + a_length++) = data; // inserts data and post-increments array length
}

template <class T>
T Array<T>::pop(void) {
    /* Returns and removes one element at end of array. */
    if (2 * a_length <= a_capacity) { // if array capacity is excessive
        shrink();                     // shrink array capacity
    }
    return *(a_data + --a_length);    // returns data and pre-decrements array length
}

template <class T>
void Array<T>::set(size_t index, T data) {
    /* Replaces element at given index with passed data. */
    while (index >= a_length) // passed index exceeds array length
        this->push(0);        // buffer with zeroes up to passed index
    *(a_data + index) = data; // replace element with data
}

template <class T>
T Array<T>::get(size_t index) {
    /* Returns data at given index. */
    return *(a_data + index);
}

template <class T>
int Array<T>::index(T data) {
    /* Searches for element in array and returns index. */
    for (int i = 0; i < a_length; i++) { // for each element
        if (a_data[(size_t)i] == data) { // if element matches search data
            return i;                    // return index
        }
    }
    return -1;                           // otherwise return -1
}

template <class T>
void Array<T>::clear(void) {
    /* Resets array structure and frees memory. */
    a_capacity = 1; // reset array size
    a_length = 0;   // reset occupied element count
}

template class Array<int>;
template class Array<float>;
template class Array<char>;