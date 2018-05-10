#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <stack> 
#include <string> 

#include "Expression.hpp"

namespace OberonLang {

  class Environment {
  public:
    static Environment* instance(); 
    void env(std::string var, Value* value);
    Value* lookup(std::string var); 
    void push();                                   //it should be called after a procedure call
    void pop();           //it should be called after returning 
    static void free();
    ~Environment() {
      std::map<std::string, Value*> *tmp;
      while(_env->size()) {
        tmp = _env->top();
        _env->pop();
        delete tmp;
      }
      delete _env;
    } // It wasn't deleting elements from stack
  private:
    Environment() { _env = new std::stack< std::map<std::string, Value*>* >(); }
    static Environment* _instance;                 // according to the singleton design pattern
    std::stack< std::map<std::string, Value*>* >* _env; 
  };

}

#endif 
