#include <source_file.hpp>

Task::Task(std::string const &task_type, double const &first_op, double const &second_op) {
  type = task_type;
  arguments.push_back(first_op);
  arguments.push_back(second_op);
}

void Add::printResult(double A, double B) {
  std::cout << A + B << std::endl;
}

void Sub::printResult(double A, double B) {
  std::cout << A - B << std::endl;
}

void Mul::printResult(double A, double B) {
  std::cout << A * B << std::endl;
}

void Div::printResult(double A, double B) {
  std::cout << A / B << std::endl;
}

std::unique_ptr<TaskHandler> GetTaskHandler(std::string const &task_type) {

  if (task_type == "add" || task_type == "ADD") {
    return make_unique<Add>();
  }

  if (task_type == "sub" || task_type == "SUB") {
    return make_unique<Sub>();
  }

  if (task_type == "div" || task_type == "DIV") {
    return make_unique<Div>();
  }

  if (task_type == "mul" || task_type == "MUL") {
    return make_unique<Mul>();
  }

  throw std::invalid_argument(std::string("Unknown task type provided: " + std::string(task_type)));
}
