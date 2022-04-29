#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <random>
#include <sstream>
namespace tests
{
    PriorityQueueTestInterface::PriorityQueueTestInterface() :
        SimpleTest("Interface")
    {
    }

    void PriorityQueueTestInterface::test()
    {
        int x = 0;
        structures::PriorityQueue<int>* queue = this->makePriorityQueue();
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);
        delete queue;
        this->logPass("Compiled.");
    }

    structures::PriorityQueue<int>* PriorityQueueUnsortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueUnsortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLimitedSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLimitedSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLinkedListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLinkedList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueTwoLists<int>();
    }

    structures::PriorityQueue<int>* HeapTestInterface::makePriorityQueue()
    {
        return new structures::Heap<int>();
    }

    PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
    }

    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());

    }

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
        addTest(new PriorityQueueLimitedSortedArrayListTestImplementation(std::string()));
    }

    PriorityQueueLinkedListTestOverall::PriorityQueueLinkedListTestOverall() :
        ComplexTest("PriorityQueueLinkedList")
    {
        addTest(new PriorityQueueLinkedListTestInterface());
    }

    PriorityQueueTwoListsTestOverall::PriorityQueueTwoListsTestOverall() :
        ComplexTest("PriorityQueueTwoLists")
    {
        addTest(new PriorityQueueTwoListsTestInterface());
        addTest(new PriorityQueueTwoListsImplementationTest());
        addTest(new PriorityQueueTwoListsScenario());
        addTest(new PriorityQueueTwoListsSpeed());

    }

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());
        addTest(new HeapTestImplementation());
        addTest(new HeapTestScenario());
        addTest(new HeapTestSpeed());
    }


    PriorityQueueTestOverall::PriorityQueueTestOverall() :
        ComplexTest("PriorityQueue")
    {
        addTest(new PriorityQueueUnsortedArrayListTestOverall());
        addTest(new PriorityQueueSortedArrayListTestOverall());
        addTest(new PriorityQueueLimitedSortedArrayListTestOverall());
        addTest(new PriorityQueueLinkedListTestOverall());
        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
    }


    //--------------------------------------------------Testy Implementacie-----------------------------------------------------------------------------------------

    HeapTestImplementation::HeapTestImplementation() : SimpleTest("Implementation test") {

    }

    void HeapTestImplementation::test() {

        auto heap = tests::HeapTestImplementation::makeHeap();
        for (int i = 1; i <= 4; ++i) {
            heap->push(i + 20, i);
        }
        //SimpleTest::assertTrue(heap->getParentIndex(2) == 0, "Otec je koren");
        //SimpleTest::assertTrue(heap->getParentIndex(3) == 1, "Otec je na indexe 1");
        SimpleTest::assertTrue(heap->peekPriority() == 21, "Priorita na peeku je 21");

        heap->push(4, 34);
        heap->push(6, 13);

        //SimpleTest::assertTrue(heap->getGreaterSonIndex(0) == 2, "Po pridani prvkov bude koren 34 a jeho lavy syn 13");
        //SimpleTest::assertTrue(heap->getParentIndex(7) == 3, "Otec 4 je 1 (datovo)");

        heap->push(20, 1);
        heap->push(5, 2);

        SimpleTest::assertTrue(heap->peekPriority() == 4, "Test peekPriority, mala by tam byt 4");
        SimpleTest::assertTrue(heap->peek() == 34, "Test peekPriority, mali by tam byt data  34");
        heap->push(27, 4);
        heap->push(14, 5);
        heap->pop();
        SimpleTest::assertTrue(heap->peekPriority() == 5, "Po vyhodeni korena sa zmenila priorita peeku na 5");
        //SimpleTest::assertTrue(heap->getGreaterSonIndex(2) == 6, "syn 6ky je 20");


        heap->push(250, 6);
        heap->push(54, 7);
        SimpleTest::assertTrue(heap->size() == 11, "pridali sme 4 dalsie prvky");

        heap->push(254, 8);
        heap->push(144, 9);
        heap->push(256, 10);
        heap->push(56, 11);
        SimpleTest::assertTrue(heap->size() == 15, "pridali sme 4 dalsie prvky");
        SimpleTest::assertTrue(heap->pop() == 2, "popne prvok na peeku, teda data s prioritou 5");

        auto copyHeap = tests::HeapTestImplementation::makeHeap(*heap);
        SimpleTest::assertTrue(copyHeap->peekPriority() == heap->peekPriority(), "Peeky priority musia byt rovnake, je to cez kopyKonstruktor");
        heap->clear();
        SimpleTest::assertTrue(heap->size() == 0, "Vycistil som frontu");
        heap->assign(*copyHeap);
        SimpleTest::assertTrue(heap->peek() == 13, "test assignu, mala by tam byt 13");
        delete heap;

    }
    PriorityQueueLimitedSortedArrayListTestImplementation::PriorityQueueLimitedSortedArrayListTestImplementation(
        const std::string& name) : SimpleTest("Implementation test") {

    }

    void PriorityQueueLimitedSortedArrayListTestImplementation::test() {
        auto queue = tests::PriorityQueueLimitedSortedArrayListTestImplementation::makePriorityQueue();

        queue->push(20, 1);
        queue->push(5, 2);

        SimpleTest::assertTrue(queue->peekPriority() == 5, "Test peekPriority, mala by tam byt 5");
        SimpleTest::assertTrue(queue->peek() == 2, "Test peekPriority, mala by tam byt 2");

        queue->pushAndRemove(3, 4);
        SimpleTest::assertTrue(queue->peekPriority() == 3, "Zmenila sa priorita peeku na 3");

        SimpleTest::assertTrue(queue->trySetCapacity(10), "Chceme zvysit kapacitu, malo by to prejst");
        queue->push(24, 4);
        queue->push(14, 5);
        queue->push(250, 6);
        queue->push(54, 7);
        SimpleTest::assertTrue(queue->size() == 6, "pridali sme 4 dalsie prvky");

        queue->push(254, 8);
        queue->push(144, 9);
        queue->push(256, 10);
        queue->push(56, 11);

        SimpleTest::assertTrue(queue->size() == 10, "pridali sme 4 dalsie prvky");
        SimpleTest::assertTrue(queue->pop() == 4, "popne prvok na peeku, teda data s prioritou 3");
        SimpleTest::assertTrue(queue->minPriority() == 256, "Najmensia priorita vo fronte je 256");

        auto copyQueue = tests::PriorityQueueLimitedSortedArrayListTestImplementation::makePriorityQueue(*queue);
        SimpleTest::assertTrue(copyQueue->peekPriority() == queue->peekPriority(), "Peek priority musia byt rovnake, je to cez kopyKonstruktor");
        queue->clear();
        SimpleTest::assertTrue(queue->size() == 0, "Vycistil som frontu");
        copyQueue->pushAndRemove(1, 12);
        queue->assign(*copyQueue);
        SimpleTest::assertTrue(queue->peek() == 12, "test assignu, mala by tam byt 12");

        delete copyQueue;
        delete queue;

    }
    PriorityQueueTwoListsImplementationTest::PriorityQueueTwoListsImplementationTest() :
        SimpleTest("Implementation test")
    {
    }
    void PriorityQueueTwoListsImplementationTest::test()
    {


        auto queue = tests::PriorityQueueTwoListsImplementationTest::makePriorityQueue();
        for (int i = 1; i <= 10; ++i) {
            queue->push(i + 20, i);
        }

        SimpleTest::assertTrue(queue->peekPriority() == 21, "Test peekPriority, mala by tam byt 21");
        SimpleTest::assertTrue(queue->pop() == 1, "Test pop(), malo by to vytiahnut 1");
        SimpleTest::assertTrue(queue->peekPriority() == 22, "Test priorityPeek() po pop, malo by to ukazat 22");

        queue->push(7, 40);

        SimpleTest::assertTrue(queue->peekPriority() == 7, "Test peekPriority() po pridani prvku s prioritou 7");

        SimpleTest::assertTrue(queue->peek() == 40, "Test peek() po pridani prvku s najvyssou prioritou");
        queue->push(152, 50);
        queue->push(4, 2);
        queue->push(64, 23);

        SimpleTest::assertTrue(queue->peekPriority() == 4, "Test peekPriority(), mal by ukazovat na 4");
        SimpleTest::assertTrue(queue->peek() == 2, "Test peek() data s najvacsou prioritou su 2");
        auto copyQueue = tests::PriorityQueueTwoListsImplementationTest::makePriorityQueue(*queue);

        SimpleTest::assertTrue(copyQueue->size() == queue->size(), "Test size() po prekopirovani");
        SimpleTest::assertTrue(copyQueue->peek() == 2, "Test peek() kopirovaneho frontu, mala by tam byt 2");
        SimpleTest::assertTrue(copyQueue->peekPriority() == 4, "Test peekPriority() kopirovaneho frontu, mala by tam byt 4");
        queue->clear();
        SimpleTest::assertTrue(queue->size() == 0, "Front bol vymazany, mal by byt 0");

        copyQueue->pop();
        copyQueue->push(1, 5000);
        queue->assign(*copyQueue);

        SimpleTest::assertTrue(queue->peek() == 5000, "Test peek() na peeku by mali byt data 5000");
        SimpleTest::assertTrue(queue->peekPriority() == 1, "Test peekPriority() peekPriority je 1");

        delete copyQueue;
        delete queue;
    }

    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    PriorityQueueTestScenario::PriorityQueueTestScenario(std::string name)
        :SimpleTest(std::move(name)) {

    }

    void PriorityQueueTestScenario::test() {

        int count = 100000;
        int maxPriority = 100000;
        std::vector<int> operations;
        operations.reserve(count);

        for (int i = 0; i < count; i++) {
            operations.emplace_back(i);
        }

        srand(time(nullptr));
        std::string nameOfScript;
        char scripts[] = { 'A', 'B', 'C' };

        structures::Logger::getInstance().logInfo(this->getNazov());
        for (char script : scripts) {
            structures::PriorityQueue<int>* queue;

            int pushCount;
            int popCount;
            int peekCount;

            std::shuffle(std::begin(operations), std::end(operations), std::mt19937(std::random_device()()));
            queue = this->makePriorityQueue();

            switch (script) {
            case 'A':
                nameOfScript = "Script A";
                pushCount = 35 * count / 100;
                popCount = 35 * count / 100;
                peekCount = 30 * count / 100;
                break;
            case 'B':
                nameOfScript = "Script B";
                pushCount = 50 * count / 100;
                popCount = 30 * count / 100;
                peekCount = 20 * count / 100;

                break;
            default:
                nameOfScript = "Script C";
                pushCount = 70 * count / 100;
                popCount = 25 * count / 100;
                peekCount = 5 * count / 100;

                break;
            }
            for (int i = 0; i < 1000; ++i) {
                int priority = rand() % maxPriority;
                queue->push(priority, i);
            }

            Milliseconds timePush = std::chrono::microseconds(0);
            Milliseconds timePop = std::chrono::microseconds(0);
            Milliseconds timePeek = std::chrono::microseconds(0);


            for (int i = 0; i < count; i++) {

                if (operations.at(i) < pushCount) {
                    int priority = rand() % maxPriority;
                    this->startStopwatch();
                    queue->push(priority, operations.at(i));
                    this->stopStopwatch();
                    timePush += getElapsedTime();

                }
                else if (pushCount <= operations.at(i) &&
                    operations.at(i) < (pushCount + popCount)) {
                    this->startStopwatch();
                    queue->pop();
                    this->stopStopwatch();
                    timePop += getElapsedTime();

                }
                else {
                    this->startStopwatch();
                    queue->peek();
                    this->stopStopwatch();
                    timePeek += getElapsedTime();

                }
            }
           // structures::Logger::getInstance().log(structures::LogType::Info, nameOfScript);
            structures::Logger::getInstance().logDuration(pushCount, std::chrono::milliseconds(0), "Push");
            structures::Logger::getInstance().logDuration(peekCount, timePeek, "Peek");
            structures::Logger::getInstance().logDuration(popCount, timePop, "Pop");
            structures::Logger::getInstance().logInfo("");
            delete queue;
        }

    }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    PriorityQueueTestSpeed::PriorityQueueTestSpeed(std::string name)
        : SimpleTest(std::move(name)) {
    }

	void PriorityQueueTestSpeed::test() {

        const size_t MAX_VALUE = 100000;
        const size_t STEP = 1000;
        const size_t MAX_PRIORITY = 100000;
        const size_t POCET_OPERACII = 200;
        size_t currentSize = 1000;

        srand(time(nullptr));

        structures::Logger::getInstance().logInfo(this->getNazov());
        std::stringstream info;
        info << "CurrentSize" << ";" << "timePush" << ";" << "timePop" << ";" << "timePeek" << ";"
            << "timePushMin" << ";" << "timePopMin" << ";" << "timePeekMin" << ";" << "timePushMax" << ";" << "timePopMax" <<
            ";" << "timePeekMax" << ";" << "AvgPush" << ";" << "AvgPop" << ";" << "AvgPeek" << ";" << "AvgPushMin" << ";" <<
            "AvgPopMin" << ";" << "AvgPeekMin" << ";" << "AvgPushMax" << ";" << "AvgPopMax" << ";" << "AvgPeekMax";
        structures::Logger::getInstance().logInfo(info.str());




        while (currentSize <= MAX_VALUE) {
            structures::PriorityQueue<int>* queue = this->makePriorityQueue();

            Milliseconds timePush = std::chrono::microseconds(0);
            Milliseconds timePeek = std::chrono::microseconds(0);
            Milliseconds timePop = std::chrono::microseconds(0);
            Milliseconds avgPush = std::chrono::microseconds(0);
            Milliseconds avgPop = std::chrono::microseconds(0);
            Milliseconds avgPeek = std::chrono::microseconds(0);
            Milliseconds timePushMin = std::chrono::microseconds(0);
            Milliseconds timePeekMin = std::chrono::microseconds(0);
            Milliseconds timePopMin = std::chrono::microseconds(0);
            Milliseconds avgPushMin = std::chrono::microseconds(0);
            Milliseconds avgPopMin = std::chrono::microseconds(0);
            Milliseconds avgPeekMin = std::chrono::microseconds(0);
            Milliseconds timePushMax = std::chrono::microseconds(0);
            Milliseconds timePeekMax = std::chrono::microseconds(0);
            Milliseconds timePopMax = std::chrono::microseconds(0);
            Milliseconds avgPushMax = std::chrono::microseconds(0);
            Milliseconds avgPopMax = std::chrono::microseconds(0);
            Milliseconds avgPeekMax = std::chrono::microseconds(0);


            for (int i = 1; i < currentSize; ++i) {
                int priority = rand() % MAX_PRIORITY;
                queue->push(priority, i);
            }

            for (int i = 1; i <= POCET_OPERACII; ++i) {
                int priority = rand() % MAX_PRIORITY;
                this->startStopwatch();
                queue->push(priority, currentSize + i);
                this->stopStopwatch();
                timePush += getElapsedTime();

                this->startStopwatch();
                queue->peek();
                this->stopStopwatch();
                timePeek += getElapsedTime();

                this->startStopwatch();
                queue->pop();
                this->stopStopwatch();
                timePop += getElapsedTime();
            }
            for (int i = 1; i <= POCET_OPERACII; ++i) {
                this->startStopwatch();
                queue->push(0, currentSize + i);
                this->stopStopwatch();
                timePushMin += getElapsedTime();

                this->startStopwatch();
                queue->peek();
                this->stopStopwatch();
                timePeekMin += getElapsedTime();

                this->startStopwatch();
                queue->pop();
                this->stopStopwatch();
                timePopMin += getElapsedTime();
            }
            for (int i = 1; i <= POCET_OPERACII; ++i) {
                this->startStopwatch();
                queue->push(MAX_PRIORITY, currentSize + i);
                this->stopStopwatch();
                timePushMax += getElapsedTime();

                this->startStopwatch();
                queue->peek();
                this->stopStopwatch();
                timePeekMax += getElapsedTime();

                this->startStopwatch();
                queue->pop();
                this->stopStopwatch();
                timePopMax += getElapsedTime();
            }
            avgPush = timePush / POCET_OPERACII;
            avgPeek = timePeek / POCET_OPERACII;
            avgPop = timePop / POCET_OPERACII;
            avgPushMin = timePushMin / POCET_OPERACII;
            avgPeekMin = timePeekMin / POCET_OPERACII;
            avgPopMin = timePopMin / POCET_OPERACII;
            avgPushMax = timePushMax / POCET_OPERACII;
            avgPeekMax = timePeekMax / POCET_OPERACII;
            avgPopMax = timePopMax / POCET_OPERACII;
            std::stringstream complex;
            complex << currentSize << ";" << std::to_string(timePush.count()) << ";" << std::to_string(timePop.count()) << ";"
                << std::to_string(timePeek.count()) << ";" << std::to_string(timePushMin.count()) << ";" << std::to_string(timePopMin.count()) << ";"
                << std::to_string(timePeekMin.count()) << ";" << std::to_string(timePushMax.count()) << ";" << std::to_string(timePopMax.count()) << ";"
                << std::to_string(timePeekMax.count()) << ";" << std::to_string(avgPush.count())
                << ";" << std::to_string(avgPop.count()) << ";" << std::to_string(avgPeek.count()) << ";" <<
                std::to_string(avgPushMin.count()) << ";" << std::to_string(avgPopMin.count()) << ";"
                << std::to_string(avgPeekMin.count()) << ";" << std::to_string(avgPushMax.count())
                << ";" << std::to_string(avgPopMax.count()) << ";" << std::to_string(avgPeekMax.count());

            structures::Logger::getInstance().logInfo(complex.str());

            currentSize += STEP;
            delete queue;
        }

        structures::Logger::getInstance().logInfo("");

    }

}