#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Prioritny front implementovany utriednym ArrayList-om. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class PriorityQueueSortedArrayList : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		PriorityQueueSortedArrayList();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Prioritny front implementovany utriednym ArrayList-om, z ktoreho sa prevezmu vlastnosti. </param>
		PriorityQueueSortedArrayList(PriorityQueueSortedArrayList<T>& other);

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

	protected:
		/// <summary> Vrati index v utriedenom ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je zoznam prazdny. </exception>
		int indexOfPeek() override;
	};

	template<typename T>
	inline PriorityQueueSortedArrayList<T>::PriorityQueueSortedArrayList() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{

	}

	template<typename T>
	inline PriorityQueueSortedArrayList<T>::PriorityQueueSortedArrayList(PriorityQueueSortedArrayList<T>& other) :
		PriorityQueueSortedArrayList()
	{
		assign(other);
	}

	template<typename T>
	inline Structure& PriorityQueueSortedArrayList<T>::assign(Structure& other)
	{
		
		if (this != &other)
		{
			PriorityQueueList<T>::assign(dynamic_cast<PriorityQueueList<T>&>(other));
		}
		return *this;
	}

	template<typename T>
	inline void PriorityQueueSortedArrayList<T>::push(int priority, const T& data)
	{
		auto* item = new PriorityQueueItem<T>(priority, data);
		if (!PriorityQueueList<T>::list_->isEmpty())
		{
			if (priority > PriorityQueueList<T>::list_->at(0)->getPriority()) {
				PriorityQueueList<T>::list_->insert(item, 0);
			}
			else if (priority < PriorityQueueList<T>::list_->at(PriorityQueueList<T>::list_->size() - 1)->getPriority()) {
				PriorityQueueList<T>::list_->add(item);
			}
			else {
				int leftIndex = 0;
				int rightIndex = static_cast<int>(PriorityQueueList<T>::list_->size());

				while (leftIndex < rightIndex)
				{
					int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
					if (priority < PriorityQueueList<T>::list_->at(middleIndex)->getPriority())
					{
						leftIndex = middleIndex + 1;
					}
					else
					{
						rightIndex = middleIndex;
					}
				}
				PriorityQueueList<T>::list_->insert(item, leftIndex);
			}
		}
		else
			PriorityQueueList<T>::list_->add(item);


	}

	template<typename T>
	inline int PriorityQueueSortedArrayList<T>::indexOfPeek()
	{
		return PriorityQueueList<T>::list_->size() - 1; //o(1), platim tym dlhym prechadzanim
	}
}