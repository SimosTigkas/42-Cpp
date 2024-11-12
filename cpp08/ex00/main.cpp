#include "easyfind.hpp"

int main(void)
{
	std::vector<int> nums;
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(12);
	nums.push_back(24);
	nums.push_back(48);
	nums.push_back(96);
	try {
		easyfind(nums, 90);
		std::cout << "\033[32m Vector: Found " << *easyfind(nums, 90) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m Vector: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;
	std::deque<int> dq = {5, 15, 25};
	dq.push_front(0);
	dq.push_back(35);
	try {
		easyfind(dq, 35);
		std::cout << "\033[32m Deque: Found " << *easyfind(dq, 35) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m Deque: " << e.what() << "\033[0m" << std::endl;
	}
	try {
		easyfind(dq, 10);
		std::cout << "\033[32m Deque: Found " << *easyfind(dq, 10) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m Deque: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;
	std::list<int> lst = {24, 25, 26};
	lst.push_back(42);
	lst.push_front(20);
	try {
		easyfind(lst, 42);
		std::cout << "\033[32m List: Found " << *easyfind(lst, 42) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m List: " << e.what() << "\033[0m" << std::endl;
	}
	try {
		easyfind(lst, 2);
		std::cout << "\033[32m List: Found " << *easyfind(lst, 2) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m List: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;
	std::forward_list<int> flst = {22, 33, 44};
	try {
		easyfind(flst, 33);
		std::cout << "\033[32m Forward list: Found " << *easyfind(flst, 33) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m Forward list: " << e.what() << "\033[0m" << std::endl;
	}
	try {
		easyfind(flst, 222);
		std::cout << "\033[32m Forward list: Found " << *easyfind(flst, 222) << "\033[0m" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "\033[31m Forward list: " << e.what() << "\033[0m" << std::endl;
	}
	return (0);
}
