// for reference
// https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
// https://stackoverflow.com/questions/7186103/how-to-elegantly-implement-a-series-of-functions-in-different-type-versions-usin/7186396#7186396

#include <iostream>

template <class T>
class Node {
    public:
        T value;
        Node * next_node;
        Node * previous_node;
        Node(T);
        ~Node();
        void init(T);
};

template <class T>
class LinkedList {
    private:
        Node<T> *first_node;
        Node<T> *last_node;
        int length;
    public:
        LinkedList<T>();
        ~LinkedList<T>();
        void append(T);
        void prepend(T);
        T popfirst(int*);
        T poplast(int*);
        void print();
        int get_length();
};





template <class T>
Node<T>::Node(T value) {
    this->init(value);
}

template <class T>
void Node<T>::init(T value) {
    this->value = value;
    this->next_node = NULL;
    this->previous_node = NULL;
}

template <class T>
Node<T>::~Node() {
    this->next_node = NULL;
    this->previous_node = NULL;
}


template <class T>
LinkedList<T>::LinkedList() {
    this->first_node = NULL;
    this->last_node = NULL;
    this->length = 0;
}


template <class T>
void LinkedList<T>::append(T value) {
    Node<T> *new_node;
    new_node = new Node<T>(value);
    if(this->first_node == NULL) {
        this->last_node = new_node;
        this->first_node = new_node;
    } else {
        new_node->previous_node = this->last_node;
        this->last_node->next_node = new_node;
        this->last_node = new_node;
    }
    this->length = this->length + 1;
}

template <class T>
void LinkedList<T>::prepend(T value) {
    Node<T> *new_node;
    new_node = new Node<T>(value);
    if(this->first_node == NULL) {
        this->last_node = new_node;
        this->first_node = new_node;
    } else {
        new_node->next_node= this->first_node;
        this->first_node->previous_node = new_node;
        this->first_node = new_node;
    }
    this->length = this->length + 1;
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *current_node;
    if(this->first_node != NULL) {
        current_node = this->first_node;
        while(current_node != NULL) {
            std::cout << current_node->value;
            std::cout << "->";
            current_node = current_node->next_node;
        }
        printf("\n");
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *current_node;
    Node<T> *next_node;
    this->last_node = NULL;
    if(this->first_node != NULL) {
        current_node = this->first_node;
        while(current_node != NULL) {
            next_node = current_node->next_node;
            delete current_node;
            current_node = next_node;
        }
    }
}


enum status { SUCCESS, EMPTY_LIST };

template <class T>
T LinkedList<T>::popfirst(int *result) {
    int status;
    if(this->first_node != NULL) {
        Node<T>* first_node;
        first_node = this->first_node;
        status = SUCCESS;
        if(first_node->next_node != NULL) {
            first_node->next_node->previous_node = NULL;
            this->first_node = first_node->next_node;
        }
        *result = first_node->value;
        delete first_node;
        this->length = this->length - 1;
    } else {
        status = EMPTY_LIST;
    }
    return status;
}

template <class T>
T LinkedList<T>::poplast(int *result) {
    int status;
    if(this->last_node!= NULL) {
        Node<T>* last_node;
        last_node = this->last_node;
        status = SUCCESS;
        if(last_node->previous_node != NULL) {
            last_node->previous_node->next_node = NULL;
            this->last_node = last_node->previous_node;
        }
        *result = last_node->value;
        delete last_node;
        this->length = this->length - 1;
    } else {
        status = EMPTY_LIST;
    }
    return status;
}

template <class T>
int LinkedList<T>::get_length() {
    return this->length;
}
