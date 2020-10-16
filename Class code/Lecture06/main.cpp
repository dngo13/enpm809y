#include <iostream>
#include <memory>
#include <vector>

//int main(){
//    int *ptr = new int{3};
//
//    if (2>1)
//        return 0;
//
//    delete ptr;
//}
/**
 * ===========================
 * arrow and dot operators
 * ===========================
 */
//struct Person {
//    std::string first_name;
//    std::string last_name;
//};
//
//int main(){
//    Person person;
//    person.first_name = "Bjarne";
//    person.last_name = "Stroutstrup";
//    std::cout << person.first_name <<"," << person.last_name << std::endl;
//    Person *person_ptr {&person};
//    person_ptr->first_name = "Guido";
//    person_ptr->last_name = "van Rossum";
//    std::cout << person.first_name <<"," << person.last_name << std::endl;
//}


/**
 * ===========================
 * unique_ptr
 * ===========================
 */
//int main() {
//    {
//        //--p1 points to 100 on the heap
////        std::unique_ptr<int> p1{new int{100}};
//        auto p1{new int{100}};
//        std::cout << *p1 << std::endl;//--100
//        *p1 = 200;
//        std::cout << *p1 << std::endl;//--200
//    }//--automatic deallocation of memory for p1
////    std::unique_ptr<int> p2 = std::make_unique<int>(30);
//    auto p2 = std::make_unique<int>(30);
//    std::cout << *p2 << std::endl;//--30
//}//--automatic deallocation of memory for p2


//int main() {
//    auto p2 = std::make_unique<int>(30);
//    p2.reset(new int{33});
//    std::cout << p2.get() << std::endl;//--30
//}//--automatic deallocation of memory for p2

//int main(){
//    int *p2;
//    {
//        int a;
//        std::cout << a+1 << std::endl;
//        //--p1 points to 100 on the heap
//        std::unique_ptr<int> p1{new int{100}};
//        std::cout << *p1 << std::endl;
//        std::cout << p1.get() << std::endl;
//
//        p2 = p1.get();
//        int *p3 = new int{4};
//        int *p4 = p3;
//        delete p3;
//        delete p3;
//        *p4 = 10;
//        std::cout << p2 << '\n';
//        std::cout << *p2 << '\n';
//        p1.reset(nullptr);//--p1 is now nullptr
//        if (p1)//-- if p1 != NULL
//            std::cout << *p1 << std::endl;//--will not execute
//
//
//        *p2 = 6;
//    }//--automatic deallocation of memory
//}


/**
 * ************************
 * Example with function
 * ************************
 */
//struct Person{
//    std::string first_name;
//    std::string last_name;
//
//    void PrintPerson(){
//        std::cout << "First name: " << first_name << ", Last name: " << last_name << std::endl;
//    }
//};
//
//
//std::unique_ptr<Person> PersonFactory(const std::string& f_name,
//        const std::string& l_name){
//    Person person {f_name, l_name};
//    return std::make_unique<Person>(person);
//}
//
//int main(){
//    Person bjarne {"Bjarne", "Stroustrup"};
//    auto bjarne_ptr = std::make_unique<Person>(bjarne);
//
//    std::unique_ptr<Person> guido_ptr = PersonFactory("Guido", "van Rossum");
//    guido_ptr.get()->PrintPerson();
//    std::vector<std::string> first_names {bjarne_ptr->first_name, guido_ptr->first_name};
//
//    for (const auto& first_name : first_names)
//        std::cout << first_name << std::endl;
//}


//--Pass unique_ptr to functions

//void TakeUnique1(std::unique_ptr<int>& unique){
//std::cout << *unique.get() << std::endl;
//}
//
//void TakeUnique2(std::unique_ptr<int> unique){
//    std::cout << *unique.get() << std::endl;
//}
//
//int main(){
//    std::unique_ptr<int> ptr = std::make_unique<int>(5);
//    TakeUnique1(ptr);
////    TakeUnique2(std::move(ptr));
////    std::cout << *ptr.get() << std::endl;
////    assert(ptr == nullptr);
//
//}



/**
 * ************************
 * Move semantics
 * ************************
 */
//int main(){
//
//    std::unique_ptr<int> p1 = std::make_unique<int>(100);
//    std::cout << p1.get() << std::endl;
//    std::unique_ptr<int> p2{std::move(p1)};
//    std::cout << p1.get() << std::endl;
//    std::cout << p2.get() << std::endl;
//}


//int main(){
//    std::vector<std::unique_ptr<int>> vec;
//    std::unique_ptr<int> p1 {new int{10}};
//
////    vec.push_back(p1);//--error
//    vec.push_back(std::move(p1));//--p1 set to nullptr
//
//    return 0;
//}//--unique_ptr deleted automatically


/**
 * ===========================
 * shared_ptr
 * ===========================
 */

//int main(){
//    {
//        //--p1 points to 100 on the heap
//        std::shared_ptr<int> p1 = std::make_shared<int>(100);
//        std::cout << *p1 << std::endl;//--100
//        *p1 = 200;
//        std::cout << *p1 << std::endl;//--200
//    }//--automatic deallocation of memory
//}

//int main(){
//    //--p1 points to 100 on the heap
//    std::shared_ptr<int> p1 = std::make_shared<int>(100);
//    std::cout << p1.use_count() << std::endl;//--1
//    std::shared_ptr<int> p2{p1};//--shared ownership
//    std::cout << p2.use_count() << std::endl;//--2
//    {
//        std::shared_ptr<int> p3{p2};//--shared ownership
//        std::cout << p1.use_count() << std::endl;//--3
//        std::cout << p2.use_count() << std::endl;//--3
//        std::cout << p3.use_count() << std::endl;//--3
//    }
//    std::cout << p1.use_count() << std::endl;//--2
//    std::cout << p2.use_count() << std::endl;//--2
//    p1.reset();//--decrement the use_count, p1 is nullptr
//    std::cout << "Value of p1: "<< p1.get() << std::endl;//--0
//    std::cout << p1.use_count() << std::endl;//--0
//    std::cout << p2.use_count() << std::endl;//--1
//}

//int main(){
//    {
//        std::vector<std::shared_ptr<int>> vec;
//        std::shared_ptr<int> ptr = std::make_shared<int>(10);
//        std::cout << ptr.use_count() << std::endl;//--1
//        vec.push_back(ptr);//--ok
//        *ptr = 20;
//        std::cout << *(vec.at(0)) << std::endl;
//        *(vec.at(0)) = 30;
//        std::cout << *ptr.get() << std::endl;
//        std::cout << ptr.use_count() << std::endl;//--2
//    }
//}

/**
 * ************************
 * Example with functions
 * ************************
 */

//void TakeSharedPointer1(std::shared_ptr<int> shared){
//    std::cout << "Pass by value:" << shared.use_count() << std::endl;
//    std::cout << *shared.get() << std::endl;
//    *shared = 5;
////    std::cout << *shared.get() << std::endl;
//}
//
//void TakeSharedPointer2(std::shared_ptr<int>& shared){
//    std::cout << "Pass by reference:" <<  shared.use_count() << std::endl;
//    std::cout << *shared.get() << std::endl;
//    *shared = 15;
////    std::cout << *shared.get() << std::endl;
//}
//
//int main(){
//    std::shared_ptr<int> ptr = std::make_shared<int>(40);
//    std::cout << ptr.use_count() << std::endl;
//    TakeSharedPointer1(ptr);
//    std::cout << *ptr.get() << std::endl;
//    TakeSharedPointer2(ptr);
//    std::cout << *ptr.get() << std::endl;
//}

/**
 * ===========================
 * weak_ptr
 * ===========================
 */
//int main()
//{
//    // OLD, problem with dangling pointer
//    // PROBLEM: ref will point to undefined data!
//
//    int* ptr = new int(10);
//    int* ref = ptr;
//    delete ptr;
//
//    // NEW
//    // SOLUTION: check expired() or lock() to determine if pointer is valid
//
//    // empty definition
//    std::shared_ptr<int> sptr;
//
//    // takes ownership of pointer
//    sptr.reset(new int);
//    *sptr = 10;
//    std::cout << sptr.use_count() << std::endl;//--1
//
//    // get pointer to data without taking ownership
//    std::weak_ptr<int> weak1 = sptr;
//    std::cout << weak1.use_count() << std::endl;//--1
//
//
//    // deletes managed object, acquires new pointer
//    sptr.reset(new int);
//    *sptr = 5;
//
//    // get pointer to new data without taking ownership
//    std::weak_ptr<int> weak2 = sptr;
//
//    // weak1 is expired!
//    if(auto tmp = weak1.lock())
//        std::cout << *tmp << '\n';
//    else
//        std::cout << "weak1 is expired\n";
//
//    // weak2 points to new data (5)
//    if(auto tmp = weak2.lock())
//        std::cout << *tmp << '\n';
//    else
//        std::cout << "weak2 is expired\n";
//}

/**
 * ===========================
 * Exercise
 * ===========================
 */
//struct Point {
//    double x;
//    double y;
//    double z;
//};

//--1: Use unique_ptr:
//---- a:Rewrite d_1  to be a unique_ptr
//---- b:Create d_2, a unique_ptr
//---- c:Transfer ownership from d_1 to d_2
//---- d: Run Valgrind

//--2: Use shared_ptr:
//---- a:Rewrite ptr to be a shared pointer
//---- b:Create ptr2, a shared pointer which points to point_1
//---- c:Create point_2{10, 10.5, 11}, and allocate memory for it using ptr
//---- d: Run Valgrind

//int main() {
//
//    double* d_1 = new double (1.0);
//    Point point_1 {3.5, 4.0, 5.5};
//    Point* ptr = new Point{point_1};
//
//    *d_1 = 2.0;
//    ptr->x=3.0;
//    ptr->y=3.0;
//    ptr->z=3.0;
//
//    delete d_1;
//    delete ptr;
//
//}