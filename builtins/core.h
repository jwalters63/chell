#pragma once

#include "../models/structs.h"
#include "../utils/errors.h"

shellStatus builtinExit(args cmd);

shellStatus builtinCd(args cmd);

shellStatus executeBuiltin(args cmd);