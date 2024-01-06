# EshyError
A simple header-only error handling library. A replacement for std::exceptions.

## Usage

### C example:

```
struct eshy_error get_result()
{
	return throw_eshy_error_c(5);
}

struct eshy_error get_another_result()
{
	return throw_eshy_error_m("This is a test error message");
}

int main(void)
{
	struct eshy_error error1 = get_result();
	struct eshy_error error2 = get_another_result();

	std::cout << get_code(error1);
	std::cout << get_message(error2);

	return 0;
}
```

### C++ example:

```
eerror::eshy_error get_result()
{
	return eerror::eshy_error(5);
}

eerror::eshy_error get_another_result()
{
	return eerror::eshy_error("This is a test error message");
}

int main()
{
	eerror::eshy_error error1 = get_result();
	eerror::eshy_error error2 = get_another_result();

	std::cout << error1.get_code();
	std::cout << error2.get_message();

	return 0;
}
```
#### Tip:

Using `eerror::eshy_error` can become rapidly tedious. While the classic solution is to use `using eerror::eshy_error`, this only avoids the `eerror` portion. A better solution is to use: `typedef eerror::eshy_error Error`.

This gives the library a much more geenric name and is easier to write and read. I have avoided using `Error` as the name of the struct in case that name is taken by something else in the project. The library is placed in the `eerror` namespace for similar reasons. Finally, the library is header only and quite small, so it is easy to modify the names in the library itself, thereby avoiding the `typedef`.
