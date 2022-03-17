#pragma once

#include "json.hpp"
#include <source_file.hpp>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <memory>

using nlohmann::json;

// Convenience since sometimes not found on system
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class Task {
public:
  Task(std::string const &task_type, double const &first_op, double const &second_op);
  std::string type;
  std::vector<double> arguments;
};

// All possible tasks inherit from taskhandler
class TaskHandler {
public:
  virtual ~TaskHandler() = default;
  virtual void printResult(double A, double B) = 0;
private:
};

std::unique_ptr<TaskHandler> GetTaskHandler(std::string const &task_type);

// Attempt to load and validate file
template <typename T>
std::vector<Task> loadTasks(T&& filename) {

  std::vector<Task> tasks;

  // read the JSON file
  std::ifstream i(std::forward<T>(filename));
  json j;

  if (!i) {
    throw std::invalid_argument(std::string("Failed to find or load the input file."));
  }

  try {
    i >> j;
  } catch(std::exception& e) {
    throw std::invalid_argument(std::string("Failed to parse the input file. Received exception: " + std::string(e.what())));
  }

  // Do a minimum of checking of the file
  if (j == nullptr || j["tasks"] == nullptr || j["tasks"].is_array() == false) {
    throw std::invalid_argument("Failed to find tasks in the json file - is it correctly formatted?");
  }

  // If any of these items are missing they will be null. If they are the incorrect type "3" instead of 3 for example,
  // this will throw
  for (auto& el : j["tasks"].items()) {
    auto const &type_of_op = el.value()["type"];
    auto const &first_op = el.value()["num1"];
    auto const &second_op = el.value()["num2"];

    tasks.push_back(Task(type_of_op, first_op, second_op));
  }

  return tasks;
}

class Add : public TaskHandler  {
public:
  Add() = default;
  virtual ~Add(){};
  void printResult(double A, double B) override;
};

class Sub : public TaskHandler  {
public:
  Sub() = default;
  virtual ~Sub(){};
  void printResult(double A, double B) override;
};

class Mul : public TaskHandler  {
public:
  Mul() = default;
  virtual ~Mul(){};
  void printResult(double A, double B) override;
};

class Div : public TaskHandler  {
public:
  Div() = default;
  virtual ~Div(){};
  void printResult(double A, double B) override;
};
