#include <iostream>
#include <memory>
#include <cstddef>
#include <functional>
#include "linkedlist.h"
#include "utility.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    auto disjoint = LinkedList<string>::CreateList("NaN");

    auto t1 = First<string>(three);
    auto t2 = Rest<string>(three);
    auto t3 = Cons<string>(one, three);

    // PrintSequence<string>(three);
    // PrintSequence<string>(two);
    // PrintSequence<string>(one);
    
    // auto result = Search<string>("130", three);
    // PrintData<string>(result);
    
    PrintSequence<string>(Search<string>(two, three));
    cout << "After " << endl;
    auto result = InsertAfter<string>("29", disjoint, three);
    //auto result = InsertAfter<string>("19", two, three);
    cout << "Result: ";
    PrintSequence<string>(result);
    class Inc
    {
    public:

        string operator()(string obj)
        {
            return obj + " Pos";
        }
    };
    Inc i;
    auto inc = Map<Inc, string>(i, result);
    PrintSequence<string>(inc);
    
    return 0;
}
