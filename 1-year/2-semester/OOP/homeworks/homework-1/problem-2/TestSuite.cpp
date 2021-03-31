#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name) {
	this->name = name;
}

void TestSuite::add(const TestCase& test_case) {
	this->tests.push_back(test_case);
}

std::vector<TestCase> TestSuite::filterPassing() const {
	std::vector<TestCase> result;
	std::vector<TestCase> cases_with_none =
		this->filterByErrorType(ErrorType::None);

	result.insert(result.end(), cases_with_none.begin(), 
		cases_with_none.end());

	std::vector<TestCase> cases_with_warning =
		this->filterByErrorType(ErrorType::Warning);

	result.insert(result.end(), cases_with_warning.begin(),
		cases_with_warning.end());

	return result;
}

std::vector<TestCase> TestSuite::filterFailing() const {
	std::vector<TestCase> result;
	std::vector<TestCase> cases_with_warning =
		this->filterByErrorType(ErrorType::Warning);

	result.insert(result.end(), cases_with_warning.begin(),
		cases_with_warning.end());

	std::vector<TestCase> cases_with_build_failed =
		this->filterByErrorType(ErrorType::BuildFailed);

	result.insert(result.end(), cases_with_build_failed.begin(),
		cases_with_build_failed.end());

	std::vector<TestCase> cases_with_failed_assertion =
		this->filterByErrorType(ErrorType::FailedAssertion);

	result.insert(result.end(), cases_with_failed_assertion.begin(),
		cases_with_failed_assertion.end());

	return result;
}

std::vector<TestCase> TestSuite::filterByErrorType(
	ErrorType error_type) const {

	std::vector<TestCase> filtered;
	//https://stackoverflow.com/questions/21204676/modern-way-to-filter-stl-container/57319794
	//first answer
	std::copy_if(this->tests.begin(), this->tests.end(),
		std::back_inserter(filtered),
		[error_type](TestCase test_case) {
			return test_case.getErrorType() == error_type;
		});

	return filtered;
}

void TestSuite::removeByErrorType(ErrorType error_type) {
	//https://www.freecodecamp.org/news/how-to-remove-elements-from-a-container-in-c/
	//example section
	this->tests.erase(std::remove_if(this->tests.begin(), this->tests.end(),
		[error_type](const TestCase& test_case) {
			return test_case.getErrorType() == error_type;
		}), 
		this->tests.end());
}

std::string TestSuite::getName() const {
	return this->name;
}

void TestSuite::setName(const std::string& new_name) {
	this->name = new_name;
}