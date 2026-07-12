/*
 *  modules/parser.h
 *
 *  Public interface for the tokenizer/parser module.
 *  Exposes the FSM-based tokenizer that splits a raw input string
 *  into discrete tokens stored in an args struct.
 */

#pragma once

#include "../models/structs.h"
#include "errors.h"

int chkQuote(char checking);

args tokenizer(char *string);