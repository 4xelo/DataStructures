#pragma once

#include "../test.h"
#include "../../structures/priority_queue/priority_queue.h"
#include "../../structures/priority_queue/priority_queue_list.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"



namespace tests
{
    /// <summary>
    /// Zavola vsetky metody z rozhrania prioritneho frontu avsak nekontroluje ich spravnost.
    /// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
    /// </summary>
    class PriorityQueueTestInterface
        : public SimpleTest
    {
    public:
        PriorityQueueTestInterface();
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() = 0;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLinkedListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueTwoListsTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class HeapTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueUnsortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLimitedSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLinkedListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLinkedListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueTwoListsTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListsTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class HeapTestOverall
        : public ComplexTest
    {
    public:
        HeapTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju prioritny front.
    /// </summary>
    class PriorityQueueTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTestOverall();
    };
    //-------------------------------- TESTY Implementacie--------------------------------------
    /// <summary>
    /// Test ktory skontroluje ci funguje add a insert v V oboch implementáciach Listu
    /// </summary>

    class HeapTestImplementation
        :public SimpleTest {
    public:
        explicit HeapTestImplementation();
        void test() override;
    private:

        static structures::Heap<int>* makeHeap() {
            return new structures::Heap<int>();
        };
        static structures::Heap<int>* makeHeap(structures::PriorityQueue<int>& other) {
            auto& priorityQueue = dynamic_cast<structures::Heap<int>&>(other);
            return new structures::Heap<int>(priorityQueue);
        };
    };

    class PriorityQueueLimitedSortedArrayListTestImplementation
        :public SimpleTest {
    public:
        explicit PriorityQueueLimitedSortedArrayListTestImplementation(
            const std::string& name);
        void test() override;
    private:
        static structures::PriorityQueueLimitedSortedArrayList<int>* makePriorityQueue() {
            return new structures::PriorityQueueLimitedSortedArrayList<int>();
        };
        static structures::PriorityQueueLimitedSortedArrayList<int>* makePriorityQueue(structures::PriorityQueue<int>& other) {
            auto& priorityQueue = dynamic_cast<structures::PriorityQueueLimitedSortedArrayList<int>&>(other);
            return new structures::PriorityQueueLimitedSortedArrayList<int>(priorityQueue);
        };

    };

    class PriorityQueueTwoListsImplementationTest
        :public SimpleTest {
    public:
        PriorityQueueTwoListsImplementationTest();
        void test() override;

    private:
        static structures::PriorityQueueTwoLists<int>* makePriorityQueue() {
            return new structures::PriorityQueueTwoLists<int>();
        };
        static structures::PriorityQueueTwoLists<int>* makePriorityQueue(structures::PriorityQueue<int>& other) {
            auto& priorityQueue = dynamic_cast<structures::PriorityQueueTwoLists<int>&>(other);
            return new structures::PriorityQueueTwoLists<int>(priorityQueue);
        };
    };

    //--------------------------------------------------------Testy Scenario-------------------------------------------------------------------------------------------------------------
    class PriorityQueueTestScenario
        : public SimpleTest {
    public:
        explicit PriorityQueueTestScenario(std::string name);
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() const = 0;
        virtual structures::PriorityQueue<int>* makePriorityQueue(structures::PriorityQueue<int>& other) const = 0;
        virtual std::string getNazov() const = 0;
    };

    class HeapTestScenario
        :public PriorityQueueTestScenario {

    public:
        HeapTestScenario() : PriorityQueueTestScenario("Heap Scenario") {}

    protected:
        structures::PriorityQueue<int>* makePriorityQueue() const override {
            return new structures::Heap<int>();
        };
        structures::PriorityQueue<int>* makePriorityQueue(structures::PriorityQueue<int>& other) const override {
            auto& priorityQueue = dynamic_cast<structures::Heap<int>&>(other);
            return new structures::Heap<int>(priorityQueue);
        };
        std::string getNazov() const override {
            return "Heap";
        }
    };

    class PriorityQueueTwoListsScenario
        :public PriorityQueueTestScenario {
    public:
        PriorityQueueTwoListsScenario() : PriorityQueueTestScenario("TwoLists scenario") {}

    protected:
        structures::PriorityQueue<int>* makePriorityQueue() const override {
            return new structures::PriorityQueueTwoLists<int>();
        };
        structures::PriorityQueue<int>* makePriorityQueue(structures::PriorityQueue<int>& other) const override {
            auto& priorityQueue = dynamic_cast<structures::PriorityQueueTwoLists<int>&>(other);
            return new structures::PriorityQueueTwoLists<int>(priorityQueue);
        };
        std::string getNazov() const override {
            return "TwoLists";
        }
    };


    //-----------------------------------------------------Testy Speed--------------------------------------------------------------------------
    class PriorityQueueTestSpeed
        : public SimpleTest {
    public:
        explicit PriorityQueueTestSpeed(std::string name);
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() const = 0;
        virtual structures::PriorityQueue<int>* makePriorityQueue(structures::PriorityQueue<int>& other) const = 0;
        virtual std::string getNazov() const = 0;
    };
    class HeapTestSpeed
        :public PriorityQueueTestSpeed
    {
    public:
        HeapTestSpeed() : PriorityQueueTestSpeed("Heap speed") {}
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() const override {
            return new structures::Heap<int>();
        };
        structures::PriorityQueue<int>* makePriorityQueue(structures::PriorityQueue<int>& other) const override {
            auto& priorityQueue = dynamic_cast<structures::Heap<int>&>(other);
            return new structures::Heap<int>(priorityQueue);
        };
        std::string getNazov() const override {
            return "Heap";
        }
    };

    class PriorityQueueTwoListsSpeed
        :public PriorityQueueTestSpeed {
    public:
        PriorityQueueTwoListsSpeed() : PriorityQueueTestSpeed("TwoLists speed") {}
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() const override {
            return new structures::PriorityQueueTwoLists<int>();
        };
        structures::PriorityQueue<int>* makePriorityQueue(structures::PriorityQueue<int>& other) const override {
            auto& priorityQueue = dynamic_cast<structures::PriorityQueueTwoLists<int>&>(other);
            return new structures::PriorityQueueTwoLists<int>(priorityQueue);
        };
        std::string getNazov() const override {
            return "TwoLists";
        }
    };
}