#pragma once

/************************************************************************/
/* C++ Objects                                                         */
/************************************************************************/
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

/************************************************************************/
/* Include Memory                                                       */
/************************************************************************/
#include <memory>

/************************************************************************/
/* Containers                                                           */
/************************************************************************/
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>

/************************************************************************/
/* Special Containers                                                   */
/************************************************************************/
#include <unordered_map>
#include <unordered_set>

/************************************************************************/
/* Algorithms                                                           */
/************************************************************************/
#include <algorithm>
#include <functional>
#include <limits>

/************************************************************************/
/* Stream Stuff                                                         */
/************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

/************************************************************************/
/*                                                                      */
/************************************************************************/
//std::map<>

template < typename T , typename A = std::allocator < T > >
using Vector = std::vector < T, A >;

//Map: el parametro P es la función que define el orden de ordenamiento.