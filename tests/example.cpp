#include "json.hpp"
#include <source_file.hpp>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "You do not appear to have provided a file name" << std::endl;
    exit(1);
  } else {
    std::cout << "Attempting to parse file " <<  argv[1] << std::endl;
  }

  // Load tasks, can throw if badly formatted
  auto tasks = loadTasks(argv[1]);

  for(auto const &i : tasks)
  {
    auto task_handler = GetTaskHandler(i.type);
    task_handler->printResult(i.arguments[0], i.arguments[1]);
  }
}
