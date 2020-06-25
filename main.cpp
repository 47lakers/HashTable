//
//  main.cpp
//  HashTable
//
//  Created by Ira Xavier Porchia on 6/23/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 5;

template <class K, class V>
class HashNode{
private:
    K _key;
    V _value;
    HashNode<K, V> *_next;
public:
    HashNode(const K &key, const V &value):
    _key(key), _value(value), _next(nullptr){}

    K getKey() const {
        return _key;
    }

    V getValue() const {
        return _value;
    }

    void setValue(V value) {
        _value = value;
    }

    HashNode *getNext() const {
        return _next;
    }

    void setNext(HashNode *next) {
        _next = next;
    }
};

template <class K, class V>
class HashMap{
private:
    HashNode<K, V> *_arr[MAX];
public:
    HashMap(){
        for(int i = 0; i < MAX; i++){
            _arr[i] = nullptr;
        }
    }

    ~HashMap(){
        clear();
    }

    void clear(){
        HashNode<K, V> *p;
        HashNode<K, V> *q;
        for(int i = 0; i < MAX; i++){
            q = nullptr;
            p = _arr[i];
            _arr[i] = nullptr;
            while(p != nullptr){
                q = p;
                p = p->getNext();
                q->setNext(nullptr);
                delete q;
                q = nullptr;
            }
        }
    }

    K hashFunction(int key){
        return key % MAX;
    }

    void insert(const K &key, const V &value){
        K hashValue = hashFunction(key);
        if(_arr[hashValue] == nullptr){
            _arr[hashValue] = new HashNode<K, V>(key, value);
            return;
        }
        HashNode<K, V> *temp = _arr[hashValue];
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        HashNode<K, V> *i = new HashNode<K, V>(key, value);
        temp->setNext(i);
    }

    void display(){
        for(int i = 0; i < MAX; i++){
            cout << i;
            HashNode<K, V> *temp = _arr[i];
            while(temp != nullptr){
                cout << " ----> " << temp->getValue();
                temp = temp->getNext();
            }
            cout << endl;
        }
        cout << endl;
    }

    bool get(const K &key, const V &value){
        K hashValue = hashFunction(key);
        HashNode<K, V> *temp = _arr[hashValue];
        while(temp != nullptr){
            if(temp->getValue() == value){
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    void remove(const K &key, const V &value){
        if(!get(key, value)){
            cout << "Not in there." << endl << endl;
        }else{
            K hashValue = hashFunction(key);
            HashNode<K, V> *temp = _arr[hashValue];
            HashNode<K, V> *prev = _arr[hashValue];
            temp = temp->getNext();
            // Delete what _arr[hashValue] is pointing to.
            if(prev->getValue() == value){
                _arr[hashValue] = prev->getNext();
                cout << "Deleted Key: " << key << " and Value: " << value << endl << endl;
                return;
            }
            while(temp != nullptr){
                if(temp->getValue() == value){
                    // Delete what temp is pointing to.
                    prev->setNext(temp->getNext());
                    cout << "Deleted Key: " << key << " and Value: " << value << endl << endl;
                    return;
                }
                prev = temp;
                temp = temp->getNext();
            }
        }
    }
};

//template<class K, class V>
//class hashNode{
//private:
//    K _key;
//    V _value;
//public:
//    hashNode(K key, V value):
//    _key(key), _value(value){}
//    
//    K key(){
//        return _key;
//    }
//    
//    V value(){
//        return _value;
//    }
//};
//
//template<class K, class V>
//class HashMap{
//private:
//    hashNode<K, V> *_arr[MAX];
//public:
//    HashMap(){
//        for(int i = 0; i < MAX; i++){
//            _arr[i] = nullptr;
//        }
//    }
//    
//    ~HashMap(){
//        clear();
//    }
//    
//    void clear(){
//        for(int i = 0; i < MAX; i++){
//            delete _arr[i];
//            _arr[i] = nullptr;
//        }
//    }
//    
//    K hashFunction(K key){
//        return key % MAX;
//    }
//    
//    void insert(K key, V value){
//        K hashValue = hashFunction(key);
//        if(_arr[hashValue] == nullptr){
//            _arr[hashValue] = new hashNode<K, V>(key, value);
//            return;
//        }else{
//            for(int i = 0; i < MAX; i++){
//                hashValue = (hashValue + 1) % MAX;
//                if(_arr[hashValue] == nullptr){
//                    _arr[hashValue] = new hashNode<K, V>(key, value);
//                    return;
//                }
//            }
//            /*
//             int i = 1;
//             Quadratic Probing: hashValue + i^i;
//             i++
//             
//             Double Hashing: hashValue + 1 * hashValue2;
//             */
//        }
//        cout << "All of the spaces are filled up." << endl << endl;
//    }
//    
//    void display(){
//        for(int i = 0; i < MAX; i++){
//            hashNode<K, V> *temp = _arr[i];
//            if(_arr[i] == nullptr){
//                cout << i << endl;
//            }else{
//                cout << "Key: " << temp->key() << " Value: " << temp->value() << endl;
//            }
//        }
//    }
//    
//    bool get(K key, V value){
//        for(int i = 0; i < MAX; i++){
//            hashNode<K, V> *temp = _arr[i];
//            if(temp->key() == key && temp->value() == value){
//                return true;
//            }
//        }
//        return false;
//    }
//    
//    void remove(K key, V value){
//        K hashValue = hashFunction(key);
//        for(int i = 0; i < MAX; i++){
//        hashNode<K, V> *temp = _arr[i];
//        if(temp->key() == key && temp->value() == value){
//            _arr[i] = nullptr;
//            return;
//        }
//    }
//}
//    
//};

int main(int argc, const char * argv[]) {
    HashMap<int, int> hm;
    hm.insert(0, 10);
    hm.insert(1, 20);
    hm.insert(2, 30);
    hm.insert(3, 40);
    hm.insert(4, 50);
    hm.insert(5, 60);
    hm.insert(6, 70);
    hm.insert(7, 80);
    hm.insert(8, 90);
    hm.insert(9, 100);
    hm.insert(10, 200);
    hm.insert(11, 300);
    hm.insert(12, 400);
    hm.insert(13, 500);
    hm.insert(14, 600);
    hm.display();
    hm.remove(0, 10);
    hm.remove(10, 200);
    hm.display();
    hm.clear();
    hm.display();
    return 0;
}
