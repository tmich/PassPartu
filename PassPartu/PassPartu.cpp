// PassPartu.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include "crypted_password_entry.h"
#include "password_repository.h"

using namespace std;

int main()
{
	string cmd;
	string name, pass, url, acct, search_term, key;
	bool exit = false;

	cout << "Inserire la chiave: ";
	getline(std::cin, key);
	
	PasswordRepository repo(key);

	do
	{
		cout << "Nome: ";
		getline(std::cin, name);

		cout << "URL: ";
		getline(std::cin, url);

		cout << "Account: ";
		getline(std::cin, acct);

		cout << "Password: ";
		getline(std::cin, pass);

		CryptedPasswordEntry pe(key);
		pe.set_name(name);
		pe.set_url(url);
		pe.set_password(pass);
		pe.set_account(acct);

		repo.add(pe);

		cout << "Vuoi inserire una nuova password (S/N)? ";
		getline(std::cin, cmd);

		if (cmd.compare("N") == 0)
		{
			repo.save();
			exit = true;
		}

		/*cout << "Cerca per nome: ";
		getline(std::wcin, search_term);

		auto found = repo.get(search_term);
		if (found != nullptr)
		{
			wcout << L"TROVATO: " << found.name() << L" con password " << found.password() << endl;
		}*/

	} while (!exit);

	cout << "Ciao" << endl;
    return 0;
}

