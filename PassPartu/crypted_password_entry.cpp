#include "stdafx.h"
#include "vigenere.h"
#include "b64.h"
#include "crypted_password_entry.h"

CryptedPasswordEntry::CryptedPasswordEntry(string key)
	: key_{ key }
{
}

CryptedPasswordEntry::~CryptedPasswordEntry()
{
}

std::string CryptedPasswordEntry::password() const
{
	string pwd{ password_ };
	string key{ key_ };

	string new_key = extend_key(pwd, key);
	return decrypt_vigenere(pwd, new_key);
}

std::string CryptedPasswordEntry::to_string() const
{
	std::string separator = "|";
	std::stringstream ss;
	ss << name_ << separator << password() << separator << url_ << separator << account_;
	return ss.str();
}
