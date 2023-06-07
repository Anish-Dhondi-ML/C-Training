#ifndef GLOBALS_H
#define GLOBALS_H
#include <map>
#include <vector>
#include "mystructure.h"

extern std::map<int,std::pair<enum Emp,void*>> emp_sock_id;
extern std::vector<ApprovalStatus> state;

#endif