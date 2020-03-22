

	Lista_8() {
		first = NULL;
		last = NULL;
	}
	void insertFirst(T v)
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			first = new Terna <T>();
			first->setValue(v);
			last = first;
		}
		else
		{
			if (buscar(v) == true)
			{
				Terna<T>* aux = getPos(v);
				aux->addSize();
			}
			else
			{
				aux = new Terna <T>();
				aux->setValue(v);
				aux->setNext(first);
				first->setPrevious(aux);
				first = aux;
			}
		}
	}

	void deleteFirst()
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			cout << "Lista Vacia" << endl;
		}
		else {
			if (first->getNext() == NULL) { // solo un elemento

				delete first;
				first = NULL;
				last = NULL;

			}
			else {
				aux = first;
				first = first->getNext();
				delete aux;
				first->setPrevious(NULL);
			}
		}
	}

	void deleteBack()
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			cout << "Lista Vacia" << endl;
		}
		else {
			if (first->getNext() == NULL) { // solo un elemento

				delete last;
				first = NULL;
				last = NULL;

			}
			else {
				aux = last;
				last = last->getPrevious();
				delete aux;
				last->setNext(NULL);
			}
		}
	}

	void eliminarElemento(T v) {
		Terna <T>* aux;
		aux = first;
		if (v == last->getValue())
		{
			deleteBack();
		}
		else
		{

		}
		if (first == NULL)
		{
			cout << "Lista Vacia";
		}
		else
		{
			if (v == first->getValue())
			{
				deleteFirst();
			}
			else
			{
				while (aux != NULL)
				{
					if (v == aux->getValue())
					{
						Terna<T>* auxAnt;
						Terna<T>* auxSig;
						auxAnt = aux->getPrevious();
						auxSig = aux->getNext();
						auxAnt->setNext(auxSig);
						auxSig->setPrevious(auxAnt);
						delete aux;
						break;
					}
					aux = aux->getNext();
				}
			}
		}
	}

	void mostrar()
	{
		Terna <T>* aux;
		aux = first;
		if (aux == NULL)
		{
			cout << "Lista Vacia";
		}
		while (aux != NULL)
		{
			cout << aux->getValue() << " " << aux->getSize() << endl;
			aux = aux->getNext();
		}
		cout << endl;
	}

	bool buscar(T v)
	{
		Terna <T>* aux = first;
		bool found = false;
		if (first == NULL)
		{
			found = false;
		}
		while (aux != NULL)
		{
			if (v == aux->getValue())
			{
				found = true;
				break;
			}
			aux = aux->getNext();

		}
		return found;
	}
	void buscar1(T v)
	{
		Terna <T>* aux = first;
		bool found = false;
		if (first == NULL)
		{
			found = false;
		}
		while (aux != NULL)
		{
			if (v == aux->getValue())
			{
				aux->mostrar();
				break;
			}
			aux = aux->getNext();

		}
	}
	Terna<T>* getPos(T v)
	{
		Terna <T>* aux = first;
		while (aux != NULL)
		{
			if (v == aux->getValue())
			{
				return aux;
				break;
			}
			aux = aux->getNext();

		}
	}
	int contar(){
		Terna <T>* aux = first;
		int i=0; 
		while(aux != NULL){
			i++;
			aux = aux->getNext();
		}
		return i; 
	}
};

