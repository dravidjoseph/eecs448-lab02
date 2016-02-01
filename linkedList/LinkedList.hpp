/**
*	@author Dravid Joseph
*	@date 2/1/16
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//just return size
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

//nothing to do if list is empty
	if(size() == 0){
		return isFound;
	}
	//otherwise, traverse
	else{
		//while temp isn't pointing at the last node
		while(temp->getNext() != nullptr){
			//check node by node if value is there and switch flag
			if(temp->getValue() == value){
				isFound = true;
			}
			//move to next node
			temp = temp->getNext();
		}
		//check last node
		if(temp->getValue() == value){
			isFound = true;
		}

	}



	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	//nothing to remove if list is empty
	if(size() == 0){
		return isRemoved;
	}
	//deal with special case when only one node exists
	if(size() == 1){
		delete m_front;
		m_front->setNext(nullptr);
		m_size--;
		isRemoved = true;
	}
	//for 2+ nodes
	else{
		secondintoLast = m_front;
		lastNode = m_front->getNext();

		//move pointers to back of list
		while(lastNode->getNext() != nullptr){
			secondintoLast = secondintoLast->getNext();
			lastNode = lastNode->getNext();
		}
		//delete the last node
		delete lastNode;
		lastNode = nullptr;
		//set the second to last node's pointer to null-new end of list
		secondintoLast->setNext(nullptr);
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
