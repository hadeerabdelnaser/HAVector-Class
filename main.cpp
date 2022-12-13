#include <iostream>
#include<algorithm>

using namespace std;

template <class T>
class HAVector{
private:
    int size, capacity;
    T* data;
public:
    typedef T* iterator;
    //constructor(int)
    HAVector(int cap=2 ){
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }
    //constructor(T*arr,int n)
    HAVector(T* arr,int n)
    {
        size = n;
        capacity = n;
        data = new T[capacity];
        for(int i = 0; i < n; i++)
        {
            data[i] = arr[i];
        }
    }
    // copy constructor.
    HAVector(const T& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < other.size; i++) {
            data[i] = other.data[i];
        }
    }
    //destructor()
    ~HAVector(){
        delete[] data;
    }
    //copy Ass
    T& operator=(const T& other){
        if(this != &other){
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(int i = 0; i < other.size; i++){
                data[i] = other.data[i];
            }
        }
        else{
            cout << "Cannot delete self" << endl;
        }
    }
    // move ass
    T& operator=(const T&& other){
        if(this != &other){
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(int i = 0; i < other.size; i++){
                data[i] = other.data[i];
            }
        }
        else{
            cout << "Cannot delete self" << endl;
        }
    }
    // Access modi
    T& operator[](int indx){
        if(indx > size-1){
           throw "INVALID.";
        }
        return data[indx];
    }
    void push_back(T item){
        if(size < capacity){
            data[size++] = item;
        }
        else{
            cout << "Resizing to " << capacity*2 << endl;
            T* newdata = new T[capacity*2];
            capacity *= 2;

            for(int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            newdata = nullptr;
            data[size++] = item;
        }
    }

    T pop_back(){
        return data[--size];
    }

    void  erase (auto iterator1,auto iterator2)
    {
        if(iterator2 <= size && iterator1 <= size && iterator1<=iterator2){
            auto P = new T[size];
            int j=0;
            for(int i = 0; i < iterator1-1; i++){
                P[j] = data[i];
                j++;
            }
            for(int i = iterator2; i < size; i++){
                P[j] = data[i];
                j++;
            }
            delete [] data;
            data = P;
            size -= (iterator2-iterator1+1);
        }
        else{
           throw "INVALID.";
        }

    }


    void  erase (auto iterator)
    {
        if(iterator <= size ){
            auto P = new T[size];
            int j=0;
            for(int i = 0; i < iterator-1; i++){
                P[j] = data[i];
                j++;
            }
            for(int i = iterator; i < size; i++){
                P[j] = data[i];
                j++;
            }
            delete [] data;
            data = P;
            size --;
        }
        else{
           throw "INVALID.";
        }

    }
    void clear(){
        size = 0;
        delete [] data;
        cout<<"DONE\n";
    }

    void insert(int indx,T x) {
        // HAvector<string>::iterator it = vec3.begin();
        // vec3.insert(it,"Hadder")
        if (indx < 0 || indx > size - 1) {
            throw "INVALID.";
        } else {
            size += 1;
            for (int i = size - 1; i > indx; --i) {
                data[i] = data[i - 1];
            }
            data[indx] = x;
        }
    }

    iterator  begin()
    {
        return data;
    }

    iterator  end()
    {
        return data+(size-1);
    }

    bool operator==(const HAVector<T> &vec2) {
        int count = 0;
        if (size == vec2.size) {
            for (int i = 0; i < vec2.size; ++i) {
                if (data[i] == vec2.data[i]) {
                    count++;
                }
            }
            if (count == size) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator<(const HAVector<T> &vec) {
        if (size < vec.size) {
            return true;
        } else if (size == vec.size) {
            for (int i = 0; i < vec.size; ++i) {
                if (data[i] < vec.data[i]) {
                    return true;
                } else {
                    return false;
                }

            }
        } else {
            return false;
        }


    }

    int getSize(){
        return size;
    }

    int  getcapacity(){
        return capacity;
    }
    
   int resize(int n) {
        cout << "Resizing to " << n << endl;
        T * newdata = new T[n];
        capacity = n;

        for (int i = 0; i < min(n, size); i++) {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        newdata = nullptr;

    }

    bool empty() {
        if (getSize() == 0) {
            return true;
        }
    }

    friend ostream &operator<<(ostream &out, const HAVector<T> vec) {
        for (int i = 0; i < vec.size; ++i) {
            out << vec.data[i]<<" ";
        }
        return out;
    }









};

int main(){
    HAVector <string> vec(1);
    vec.push_back((string) "Hello");
    vec.push_back((string) "Neehaw");
    vec.push_back((string) "Bonjour");
    vec.push_back((string) "Guten Tag");
    vec.push_back((string) "Salam Alykum");
    vec.push_back((string) "Hola");
    try{
        vec[0] = "Hellooooo";
    }
    catch(const char * s){
        cout<<"Exception :"<<s<<endl;
    }

    for(int i = 0; i < vec.getSize(); i++){
        cout << vec[i] << endl;
    }
    cout << endl << endl;
    HAVector <string> vec2;
    vec2 = move(vec);
    vec2[0] = "Salam Alykum231";

    for(int i = 0; i < vec2.getSize(); i++){
        cout << vec2[i] << endl;
    }
    if((vec == vec2)){
        cout <<"equal"<< endl;
    }
    if((vec < vec2)){cout << "first vector is smaller." << endl;}
    string arr[7];
    arr[0]="Aya";arr[1]="Ali";arr[2]="Hassan";arr[3]="Ali";
    arr[4]="Teammate";arr[5]="Hadder";arr[6]="Abdelnasser";
    HAVector<string> vec3(arr,7);
    for(int i = 0; i < vec3.getSize(); i++){
        cout << vec3[i] << endl;
    }
    cout<<endl;
    vec3.pop_back();
    //Aya Ali Hassan Ali teammate Hadder

    for(int i = 0; i < vec3.getSize(); i++){
        cout << vec3[i] << endl;
    }
    cout<<endl;
    try{
        vec3.erase(1,1);
    }
    catch(const char * s){
        cout<<"Exception :"<<s<<endl;
    }
    //Ali Hassan Ali teammate Hadder
    for(int i = 0; i < vec3.getSize(); i++){
        cout << vec3[i] << endl;
    }
    cout<<endl;
    cout<<vec3.getSize()<<endl;//5
    try{
        vec3.erase(1);
    }
    catch(const char * s){
        cout<<"Exception :"<<s<<endl;
    }
    // Hassan Ali teammate Hadder
    for(int i = 0; i < vec3.getSize(); i++){
        cout << vec3[i] << endl;
    }
    cout<<endl;
    cout<<*vec3.begin()<<endl;//Hassan
    cout<<*vec3.end()<<endl;//Hadder
    HAVector<string> :: iterator it = vec3.begin();
    cout<<*it<<endl;//Hassan
    it++;
    cout<<*it<<endl;//Ali
    HAVector<string> :: iterator it2 = it+1;
    //Hassan Ali Teammate Hadder
    cout<< *it2<<endl;//teammate
    try{
        vec3.insert(1,"Hadeer");
    }
    catch(const char * s){
        cout<<"Exception :"<<s<<endl;
    }
    for(int i = 0; i < vec3.getSize(); i++){
        cout << vec3[i] << endl;
    }
    cout<<vec3<<endl;
    vec3.clear();

    for(int i = 0; i < vec3.getSize(); i++){
        cout << vec3[i] << endl;
    }


}
