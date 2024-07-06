#pragma once

#ifndef FW
#error FW not set
#endif

#if FW==755
#include "offsets/755.h"
#elif FW==800
#include "offsets/800-801.h"
#elif FW==801
#include "offsets/800-801.h"
#elif FW==803
#include "offsets/803.h"
#elif FW==850
#include "offsets/850.h"
#elif FW==852
#include "offsets/852.h"
#elif FW==900
#include "offsets/900.h"
#elif FW==903
#include "offsets/903.h"
#elif FW==904
#include "offsets/904.h"
#elif FW==950
#include "offsets/950.h"
#elif FW==951
#include "offsets/951.h"
#elif FW==960
#include "offsets/960.h"
#elif FW==1000
#include "offsets/1000.h"
#elif FW==1001
#include "offsets/1001.h"
#elif FW==1050
#include "offsets/1050.h"
#elif FW==1070
#include "offsets/1070-1071.h"
#elif FW==1071
#include "offsets/1070-1071.h"
#elif FW==1100
#include "offsets/1100.h"
#endif