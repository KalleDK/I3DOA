#include <iostream>

void print_phone(char* number, int size, char* prefix = NULL, int prefix_size = 0) {
	if (size == 0) {
		for (int i = 0; i < prefix_size; ++i) {
			std::cout << prefix[i];
		}
		std::cout << "\n";
		return;
	} 
	if ( prefix == NULL ) {
		prefix = new char[size];
		prefix_size = size;
	}
	switch(number[0] )
	{
	  case '0':
	  case '1':
		prefix[prefix_size-size] = '-';
		print_phone(number+1,size-1, prefix, prefix_size);
		break;
	  case '2':
	  case '3':
	  case '4':
	  case '5':
	  case '6':
		for (int i=0; i < 3; ++i) {
			prefix[prefix_size-size] = (char)('a' + i + 0 + (number[0]-'2')*3);
			print_phone(number+1,size-1, prefix, prefix_size);
		}
		break;
	  case '7':
		for (int i=0; i < 4; ++i) {
			prefix[prefix_size-size] = (char)('a' + i + 0 + (number[0]-'2')*3);
			print_phone(number+1,size-1, prefix, prefix_size);
		}
		break;
	  case '8':
		for (int i=0; i < 3; ++i) {
			prefix[prefix_size-size] = (char)('a' + i + 1 + (number[0]-'2')*3);
			print_phone(number+1,size-1, prefix, prefix_size);
		}
		break;
	  case '9':
		for (int i=0; i < 4; ++i) {
			prefix[prefix_size-size] = (char)('a' + i + 1 + (number[0]-'2')*3);
			print_phone(number+1,size-1, prefix, prefix_size);
		}
		break;
	  default:
		break;
	}
	if (size == prefix_size) {
		delete[] prefix;
	}
}

int main(int narg, char *argv[]) {
	char number[] = "79";
	print_phone(number,2);
	std::cout << "\n";
}
