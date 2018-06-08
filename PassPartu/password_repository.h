#pragma once
#include <vector>
#include "crypted_password_entry.h"

using namespace std;

class PasswordRepository
{
public:
	PasswordRepository(string key);
	~PasswordRepository();

	void add(CryptedPasswordEntry pentry);
	CryptedPasswordEntry get(string name) const;

	void save() const;
protected:
	vector<CryptedPasswordEntry> entries_;
	string key_;
};

