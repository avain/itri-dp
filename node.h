#ifndef NODE_H
#define NODE_H
#include <string>
#include <fstream>
#include <sys/stat.h>

using std::string;

class Node {
public:
  Node(string const & nodeName):_name(nodeName){
    if (stat(_name.c_str(), &_st) != 0)
         throw string("file does not exist");
  }
  virtual string name() const = 0;
  virtual int getCharCount() const = 0;
  virtual void addEntry(Node * n) = 0;
  virtual int numEntries() = 0;
protected:
  string _name;
  struct stat _st;
};


class File : public Node {
public:
  File(string const &  s):Node(s){
    //if (stat(name().c_str(), &_st) != 0)
  //       throw string("file does not exist");
  }
  string name() const {return _name;}
  int getCharCount() const {
    return _st.st_size;
  }
  void addEntry(Node * n){
    throw string("unable to add entry to a file");
  }
  int numEntries(){
    throw string("illegal action");
  }

//private:
  //string _name;
  //struct stat _st;
};

#endif
