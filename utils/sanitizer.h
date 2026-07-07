/*
 *  utils/sanitizer.h
 *
 *  Public interface for the string sanitizer utility.
 *  Provides generic string cleaning functions that are
 *  not tied to the shell's business logic.
 */

#pragma once

int chkNewline(char checking);

void sanitizeString(char *string);