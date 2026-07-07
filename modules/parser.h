/*
 *  modules/parser.h
 *
 *  Public interface for the tokenizer/parser module.
 *  Exposes the FSM-based tokenizer that splits a raw input string
 *  into discrete tokens stored in an args struct.
 */

#pragma once

int chkQuote(char checking);

void tokenizer(char *string);