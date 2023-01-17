#pragma once

#include "vertagt_aktion - Vorlage.h"
#include <list>
using namespace std;

namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		list<T> p_objekte;
		list<unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename list<T>::iterator;
		using const_iterator = typename list<T>::const_iterator;

		// Konstruktoren
		VListe() = default; // Benötigt man einen Standardkonstruktor?
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}


		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.begin();
		}
		const_iterator end() const
		{
			return p_objekte.end();
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			return p_objekte.end();
		}
		bool empty() const
		{
			return p_objekte.empty();
		}

		// Schreibfunktionen
		void push_back(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(make_unique<VPushBack<T>>(p_objekte, move(obj)));
			//cout<<"pushBack"<<endl;
		}

		void push_front(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen //push_front ist gemeint...
			p_aktionen.push_front(make_unique<VPushFront<T>>(p_objekte, move(obj)));
		}

		void erase(iterator it)
		{
			// Aktionselement für PushBack auf Liste erzeugen (hier Iterator statt Objekt !)
			p_aktionen.push_back(make_unique<VErase<T>>(p_objekte, it));
		}

		// Änderungen auf Objektliste übertragen
		void vAktualisieren()
		{
			// Änderungen auf Objektliste übertragen
			for (auto& pAktion : p_aktionen)
			{
				// Aktion ausführen
				pAktion.get()->vAusfuehren();
			}
			// Aktionsliste löschen
			p_aktionen.clear();
		}

		void clear()
		{
			vAktualisieren();
			p_objekte.clear();
		}
	};
} // namespace vertagt
