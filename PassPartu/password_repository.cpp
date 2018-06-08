#include "stdafx.h"
#include <algorithm>
#include <fstream>
#include "password_repository.h"

PasswordRepository::PasswordRepository(string key)
	:key_{ key }
{
}


PasswordRepository::~PasswordRepository()
{
}

void PasswordRepository::add(CryptedPasswordEntry pentry)
{
	entries_.push_back(pentry);
}

void PasswordRepository::save() const
{
	const char* FILENAME = "passpartu.dat";

	ofstream out;
	out.open(FILENAME);
	for (const auto& pe : entries_)
	{
		out << pe.to_string() << std::endl;
	}

	out.close();
}

CryptedPasswordEntry PasswordRepository::get(string name) const
{
	auto it = find_if(entries_.begin(), entries_.end(), [=](const CryptedPasswordEntry pe) { return pe.name().compare(name) == 0; });
	if (it != entries_.end())
	{
		return *it;
	}

	throw "Not Found";
}
