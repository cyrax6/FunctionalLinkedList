/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   unit_tests.cpp
 * Author: cyrax
 *
 * Created on March 27, 2016, 10:29 AM
 */

#include <iostream>
#include <memory>
#include <cstddef>
#include <functional>
#include "linkedlist.h"
#include "utility.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void testCreateList()
{
    // Also checks types. Don't use auto here
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    if(!one)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testCreateList (unit_tests) message=error message sample" << std::endl;
    }
}

void testAddHead()
{
    auto one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    
    if(!two || two->IsTail())
    {
        std::cout << "%TEST_FAILED% time=0 testname=testAddHead (unit_tests) message=error message sample" << std::endl;
    }
}

void testFirst()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    if(First<string>(three) != three)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testFirst (unit_tests) message=error message sample" << std::endl;
    }
}

void testRest()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    if(Rest<string>(three) != two)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testRest (unit_tests) message=error message sample" << std::endl;
    }
}

void testCons()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    auto cons = Cons<string>(one, three);
    if(cons->GetData() != one->GetData())
    {
        std::cout << "%TEST_FAILED% time=0 testname=testCons (unit_tests) message= Data doesn't match" << std::endl;
    }
    if(cons == one)
    {
        std::cout << "%TEST FAILED% testname=testCons message= Cons did not create a new node instead attached an existing node" << std::endl;
    }
}

void testMap()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    class Inc
    {
    public:

        string operator()(string obj)
        {
            return obj + " Pos";
        }
    };
    Inc i;
    auto inc = Map<Inc, string>(i, three);
    
    if(inc->GetData() != "30 Pos"
       || inc->Behead()->GetData() != "20 Pos"
       || inc->Behead()->Behead()->GetData() != "10 Pos")
    {
        std::cout << "%TEST_FAILED% time=0 testname=testMap (unit_tests) message=Mapping function did not return expected results" << std::endl;
    }
    
    if(inc == three)
    {
        std::cout << "%TEST_FAILED% message= Mapping function did not create a new node" << endl;
    }
}

void testSearchData()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    auto disjoint = LinkedList<string>::CreateList("NaN");
    if(!Search<string>(two->GetData(), three))
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearch (unit_tests) message=Could not find 20 in the sequence" << std::endl;
    }
    
    if(Search<string>(disjoint->GetData(), three))
    {
        cout << "%TEST_FAILED% message=Should not have found NaN in the sequence" << endl;
    }
}

void testSearchNode()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    auto disjoint = LinkedList<string>::CreateList("NaN");
    if(!Search<string>(two, three))
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearchNode (unit_tests) message=Could not find 20 in the sequence" << std::endl;
    }
    
    if(Search<string>(disjoint, three))
    {
        cout << "%TEST_FAILED% testname=testSearchNode message=Should not have found NaN in the sequence" << endl;
    }
}

void testInsertAfter()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    auto disjoint = LinkedList<string>::CreateList("NaN");
    
    if(InsertAfter<string>("29", disjoint, three))
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertAfter (unit_tests) message=InserAfter should have returned a null" << std::endl;
    }
    
    auto result = InsertAfter<string>("29", three, three);
    if(result->Behead()->GetData() != "29")
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertAfter (unit_tests) message=Node after head should have been 29 instead of "<< result->Behead()->GetData() << std::endl;
    }
    
    if(result == three)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertAfter (unit_tests) message=result should have been a new node" << std::endl;
    }
    
    auto new_result = InsertAfter<string>("9", one, three);
    if(!Search<string>("9", new_result))
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertAfter (unit_tests) message=error while inserting to tail" << std::endl;
    }
}

void testInsertBefore()
{
    shared_ptr<const LinkedList < string>> one = LinkedList<string>::CreateList("10");
    auto two = LinkedList<string>::AddHead("20", one);
    auto three = LinkedList<string>::AddHead("30", two);
    auto disjoint = LinkedList<string>::CreateList("NaN");
    
    if(InsertBefore<string>("29", disjoint, three))
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertBefore (unit_tests) message=InserAfter should have returned a null" << std::endl;
    }
    
    auto result = InsertBefore<string>("39", three, three);
    if(result->Behead()->GetData() != "30" && result->GetData() != "39")
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertBefore (unit_tests) message=Node after head should have been 30 instead of "<< result->Behead()->GetData() << std::endl;
    }

    if(result == three)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertBefore (unit_tests) message=result should have been a new node" << std::endl;
    }
    cout << "Result after creating a new head 39" << endl;
    PrintSequence<string>(result);
    
    auto new_result = InsertBefore<string>("11", one, three);
    if(!Search<string>("11", new_result))
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertBefore (unit_tests) message=error while inserting to tail" << std::endl;
    }
    
    cout << "Result after appending 11" << endl;
    PrintSequence<string>(new_result);
}

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% unit_tests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
/*
    std::cout << "%TEST_STARTED% testCreateList (unit_tests)" << std::endl;
    testCreateList();
    std::cout << "%TEST_FINISHED% time=0 testCreateList (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testAddHead (unit_tests)" << std::endl;
    testAddHead();
    std::cout << "%TEST_FINISHED% time=0 testAddHead (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testFirst (unit_tests)" << std::endl;
    testFirst();
    std::cout << "%TEST_FINISHED% time=0 testFirst (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testRest (unit_tests)" << std::endl;
    testRest();
    std::cout << "%TEST_FINISHED% time=0 testRest (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testCons (unit_tests)" << std::endl;
    testCons();
    std::cout << "%TEST_FINISHED% time=0 testCons (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testMap (unit_tests)" << std::endl;
    testMap();
    std::cout << "%TEST_FINISHED% time=0 testMap (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testSearch (unit_tests)" << std::endl;
    testSearchData();
    std::cout << "%TEST_FINISHED% time=0 testSearch (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testSearch2 (unit_tests)" << std::endl;
    testSearchNode();
    std::cout << "%TEST_FINISHED% time=0 testSearch2 (unit_tests)" << std::endl;
*/
    std::cout << "%TEST_STARTED% testInsertAfter (unit_tests)" << std::endl;
    testInsertAfter();
    std::cout << "%TEST_FINISHED% time=0 testInsertAfter (unit_tests)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertBefore (unit_tests)" << std::endl;
    testInsertBefore();
    std::cout << "%TEST_FINISHED% time=0 testInsertBefore (unit_tests)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return(EXIT_SUCCESS);
}

