#pragma once

#include <list>
using namespace std;

namespace vertagt
{
	// Oberklasse VAktion
	template <class T>
	class VAktion
	{
	protected:
		list<T>& p_pListe;  // Zeiger auf Liste der Objekte

	public:
		VAktion(list<T>& ptListe) : p_pListe(ptListe){}
		virtual ~VAktion() = default;
		virtual void vAusfuehren() = 0;
	};

	// PushBack
	template <class T>
	class VPushBack : public VAktion<T>
	{
	private:
		T p_objekt;

	public:
	    VPushBack();
		VPushBack(list<T>& liste, T obj) : VAktion<T>(liste), p_objekt(move(obj))	{
			//cout<<"VPushBack"<<endl;
		}
		virtual ~VPushBack() = default;
		void vAusfuehren() override
		{
			VAktion<T>::p_pListe.push_back(move(p_objekt));
		}
	};

	// PushFront
	template <class T>
		class VPushFront : public VAktion<T>
		{
		private:
			T p_objekt;

		public:
			VPushFront(list<T>& liste, T obj) : VAktion<T>(liste), p_objekt(move(obj))	{}
			virtual ~VPushFront() = default;
			void vAusfuehren() override
			{
				VAktion<T>::p_pListe.push_front(move(p_objekt));
			}
		};
	// Erase
	template <class T>
	class VErase : public VAktion<T>
	{
	protected:
		 //ansonsten ist p_pListe nicht deklariert..
	public:
		using iterator = typename list<T>::iterator;

	private:
		iterator p_it;  // bei erase Iterator speichern
	public:
		VErase(list<T>& liste, iterator it): VAktion<T>(liste),p_it(move(it)){}
		virtual ~VErase() = default;
		void vAusfuehren() override
		{
			VAktion<T>::p_pListe.erase(p_it);
		}
	};
}  // namespace vertagt
