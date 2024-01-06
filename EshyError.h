//Copyright Eshwary Mishra 2024. Lisenced under BSD.

#pragma once

#include <string.h>
#include <stdlib.h>

#ifndef __cplusplus

struct eshy_error
{
	union
	{
		//Ideally in a program this would be represented by an enum
		unsigned int error_code;

		//Sometimes we just want an error message and not bother with codes
		char* error_message;
	};

	//True if failed
	bool b_has_error;
};

struct eshy_error throw_eshy_error_c(unsigned int error_code)
{
	struct eshy_error error_struct;
	error_struct.error_code = error_code;
	error_struct.b_has_error = true;
	return error_struct;
}

struct eshy_error throw_eshy_error_m(const char* error_message)
{
	struct eshy_error error_struct;
	error_struct.error_message = calloc(strlen(error_message) + 1, sizeof(char));
	memmove(error_struct.error_message, error_message, strlen(error_message));
	error_struct.b_has_error = true;
	return error_struct;
}

bool has_error(struct eshy_error* error_struct)
{
	return error_struct->b_has_error;
}

unsigned int get_code(struct eshy_error* error_struct)
{
	return error_struct->error_code;
}

char* get_message(struct eshy_error* error_struct)
{
	return error_struct->error_message;
}

#else

#include <string>

namespace eerror
{
struct eshy_error
{
	eshy_error()
		: b_has_error(false)
	{}

	eshy_error(unsigned int _error_code)
		: error_code(_error_code)
		, b_has_error(true)
	{}

	eshy_error(const char* _error_message)
		: b_has_error(true)
	{
		error_message = (char*)calloc(strlen(_error_message) + 1, sizeof(char));
		memmove(error_message, _error_message, strlen(_error_message));
	}

	eshy_error(const std::string& _error_message)
		: b_has_error(true)
	{
		error_message = (char*)calloc(_error_message.size() + 1, sizeof(char));
		memmove(error_message, _error_message.c_str(), strlen(error_message));
	}

	union
	{
		//Ideally in a program this would be represented by an enum
		unsigned int error_code;

		//Sometimes we just want an error message and not bother with codes
		char* error_message;
	};

	//True if failed
	bool b_has_error;

	bool has_error()
	{
		return b_has_error;
	}

	unsigned int get_code()
	{
		return error_code;
	}

	char* get_message()
	{
		return error_message;
	}
};
}

#endif